#include "ScanningWidget.h"
#include "Vietnamese.h"
#include "Utils.h"
#include "Scanner.h"
#include "MapInfo.h"
#include "Database.h"

#include <QThread>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
#include <QMenu>
#include <QPointer>
#include <spdlog/spdlog.h>

#include "TyLeType.hxx"
#include "TyLeType-odb.hxx"

namespace regexp
{
	const QString map25k = "\\d{4}(\\s+|_+|-+)*(i{1,3}|I{1,3}|1|2|3|4|iv|IV)(\\s+|_+|-+)*(DB|\\x0110B|TB|DN|\\x0110N|TN)(\\s+|_+|-+)*";
	const QString map50k = "\\d{4}(\\s+|_+|-+)*(i{1,3}|I{1,3}|1|2|3|4|iv|IV)(\\s+|_+|-+)*";
	const QString map100k = "\\d{4}(\\s+|_+|-+)*";
	const QString map250k = "[A-Za-z]{2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*";
	const QString map500k = "[A-Za-z]{2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*(a|A|b|B|c|C|d|D)(\\s+|_+|-+)*";
	const QString map1m = "[A-Za-z]{2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*";
}

ScanningWidget::ScanningWidget(QWidget* parent)
	: QWidget(parent)
{
	setupUi(this);

	connect(scanButton, &QPushButton::clicked, this, &ScanningWidget::scan);
	connect(browseScanDirButton, &QPushButton::clicked, this, &ScanningWidget::browseScanDir);

	/*
	* Nhớ thay đổi trong Copier
	*/
	mItemModel = QSharedPointer<QStandardItemModel>(new QStandardItemModel(0, 10, tableView));
	mItemModel->setHeaderData(0, Qt::Horizontal, Vietnamese::str(L"Số hiệu mảnh"));
	mItemModel->setHeaderData(1, Qt::Horizontal, Vietnamese::str(L"Tên mảnh"));
	mItemModel->setHeaderData(2, Qt::Horizontal, Vietnamese::str(L"Hệ tọa độ"));
	mItemModel->setHeaderData(3, Qt::Horizontal, Vietnamese::str(L"Khoảng cao đều"));
	mItemModel->setHeaderData(4, Qt::Horizontal, Vietnamese::str(L"Múi chiếu"));
	mItemModel->setHeaderData(5, Qt::Horizontal, Vietnamese::str(L"Năm sản xuất"));
	mItemModel->setHeaderData(6, Qt::Horizontal, Vietnamese::str(L"Phương pháp"));
	mItemModel->setHeaderData(7, Qt::Horizontal, Vietnamese::str(L"Đường dẫn"));
	mItemModel->setHeaderData(8, Qt::Horizontal, Vietnamese::str(L"Thời gian lưu kho"));
	mItemModel->setHeaderData(9, Qt::Horizontal, Vietnamese::str(L"Trạng thái"));
	/*
	* Nhớ thay đổi trong Copier
	*/

	tableView->setModel(mItemModel.get());
	tableView->resizeColumnsToContents();
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->setContextMenuPolicy(Qt::CustomContextMenu);

	loadTyLeType();

	mRegExp.insert("1/25.000", regexp::map25k);
	mRegExp.insert("1/50.000", regexp::map50k);
	mRegExp.insert("1/100.000", regexp::map100k);
	mRegExp.insert("1/250.000", regexp::map250k);
	mRegExp.insert("1/500.000", regexp::map500k);
	mRegExp.insert("1/1.000.000", regexp::map1m);

	connect(mapScaleComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &ScanningWidget::mapScaleComboBoxChanged);
	connect(tableView, SIGNAL(customContextMenuRequested(const QPoint&)),
		this, SLOT(slotCustomMenuRequested(const QPoint&)));
}

size_t ScanningWidget::idTyLeType() const
{
	int idx = mapScaleComboBox->currentIndex();
	return mapScaleComboBox->itemData(idx).toInt();
}

QString ScanningWidget::scaleText() const
{
	return mapScaleComboBox->currentText();
}

void ScanningWidget::browseScanDir()
{
	auto dir = QFileDialog::getExistingDirectory(this, Vietnamese::str(L"Chọn thư mục cần quét"));
	if (!dir.isEmpty())
	{
		scanDirLineEdit->setText(dir);
	}
}

void ScanningWidget::scan()
{
	mScaleScan = mapScaleComboBox->currentText();
	auto regExp = mRegExp[mScaleScan];
	auto dir = scanDirLineEdit->text().trimmed();
	if (dir.isEmpty())
		return;

	spdlog::get("logger")->debug("Scan [{}] [{}]", mScaleScan.toStdString(), dir.toStdString());
	QPointer<Scanner> scanner(new Scanner(dir, regExp));
	QPointer<QThread> thread(new QThread);
	scanner->moveToThread(thread);

	connect(scanner, SIGNAL(started()), this, SLOT(scannerStarted()));
	connect(scanner, SIGNAL(finished()), this, SLOT(scannerFinished()));
	connect(scanner, &Scanner::finished, [this] { emit finished(mItemModel); });
		
	connect(scanner, SIGNAL(progressPath(const QString&)), this, SLOT(scannerProgress(const QString&)));
	connect(scanner, SIGNAL(detected(const QString&, const QString&, const QDateTime&)),
		this, SLOT(scannerDetection(const QString&, const QString&, const QDateTime&)));

	connect(scanner, SIGNAL(finished()), thread, SLOT(quit()));
	connect(scanner, SIGNAL(finished()), scanner, SLOT(deleteLater()));
	connect(thread, SIGNAL(started()), scanner, SLOT(run()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}

void ScanningWidget::scannerStarted() const
{
	auto rowCount = mItemModel->rowCount();
	mItemModel->removeRows(0, rowCount);
	statusLabel->clear();
	setTotalLabel(0);
}

void ScanningWidget::scannerFinished() const
{
	statusLabel->setText(Vietnamese::blue(L"Đã quét xong!"));
}

void ScanningWidget::scannerProgress(const QString& message) const
{
	statusLabel->setText(message);
}

void ScanningWidget::scannerDetection(const QString& name, const QString& path,
	const QDateTime& dateTime) const
{
	auto correctName = Utils::adjustMapName(name, mScaleScan);
	MapInfo sheet = MapInfo::get(name, mapScaleComboBox->currentText());

	auto row = mItemModel->rowCount();
	mItemModel->insertRow(row);
	mItemModel->setItem(row, 0, new QStandardItem(correctName));
	mItemModel->setItem(row, 1, new QStandardItem(sheet.mTenManh));
	mItemModel->setItem(row, 2, new QStandardItem(sheet.mHeToaDo));
	mItemModel->setItem(row, 3, new QStandardItem(sheet.mKhoangCaoDeu));
	mItemModel->setItem(row, 4, new QStandardItem(sheet.mMuiChieu));
	mItemModel->setItem(row, 5, new QStandardItem(sheet.mNamSanXuat));
	mItemModel->setItem(row, 6, new QStandardItem(sheet.mPhuongPhapThanhLap));
	mItemModel->setItem(row, 7, new QStandardItem(path));
	mItemModel->setItem(row, 8, new QStandardItem(dateTime.toString("dd-MM-yyyy")));
	setTotalLabel(row + 1);
}

void ScanningWidget::slotCustomMenuRequested(const QPoint& p)
{
	if (mItemModel == nullptr || mItemModel->rowCount() == 0)
		return;

	QPointer<QMenu> menu(new QMenu(this));
	auto makeSameWithAction = menu->addAction(Vietnamese::str(L"Dãn cột mặc định"));
	auto fitContentAction = menu->addAction(Vietnamese::str(L"Dãn cột theo nội dung"));
	auto saveAction = menu->addAction(Vietnamese::str(L"Lưu bảng"));

	connect(fitContentAction, &QAction::triggered, [this] {
		tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
		});

	connect(makeSameWithAction, &QAction::triggered, [this] {
		tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Stretch);
		});

	connect(saveAction, &QAction::triggered, [this] { saveTable(); });
	menu->popup(tableView->viewport()->mapToGlobal(p));
}

void ScanningWidget::mapScaleComboBoxChanged(int index)
{
	QString scale = mapScaleComboBox->itemText(index);
	regExpLineEdit->setText(mRegExp[scale]);
}

void ScanningWidget::saveTable()
{
	auto saveFileCsv = QFileDialog::getSaveFileName(this,
		Vietnamese::str(L"Lưu bảng"), QString(), "CSV (*.csv)");
	if (saveFileCsv.isEmpty())
		return;

	QFile file(saveFileCsv);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QTextStream csv(&file);
	csv.setCodec("UTF-8");
	auto rowCount = mItemModel->rowCount();
	auto colCount = mItemModel->columnCount();
	for (auto row = 0; row < rowCount; ++row)
	{
		QStringList record;
		for (auto col = 0; col < colCount; ++col)
		{
			const QStandardItem* item = mItemModel->item(row, col);
			record << (item ? item->text() : " ");
		}
		csv << record.join(", ") << "\n";
	}

	file.close();
	statusLabel->setVisible(true);
	statusLabel->setText(Vietnamese::blue(L"Đã lưu bảng xong!"));
}

void ScanningWidget::setTotalLabel(int count) const
{
	totalLabel->setText(Vietnamese::str(L"Số lượng: %1").arg(count));
}

void ScanningWidget::loadTyLeType()
{
	spdlog::get("logger")->debug("Load TyLeType");
	try
	{
		auto db = Database::m_database;
		odb::transaction t(db->begin());
		using TyLeTypeQuery = odb::query<TyLeType>;
		using TyLeTypeResult = odb::result<TyLeType>;
		auto result = db->query<TyLeType>(TyLeTypeQuery::mLoaiTyLe == 1);
		for (const auto& r : result)
		{
			mapScaleComboBox->addItem(r.mMa, r.mTyLeTypeId);
		}
		t.commit();
	}
	catch (const odb::exception& e)
	{
		spdlog::get("logger")->error(e.what());
	}
}
