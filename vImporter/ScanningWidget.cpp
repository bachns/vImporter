#include "ScanningWidget.h"
#include "Vietnamese.h"
#include "GlobalVariables.h"
#include "Utils.h"
#include "Scanner.h"

#include <spdlog/spdlog.h>
#include <QThread>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
#include <QMenu>
#include <QPointer>

ScanningWidget::ScanningWidget(QWidget* parent)
	: QWidget(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);

	setupUi(this);

	connect(scanButton, &QPushButton::clicked, this, &ScanningWidget::scan);
	connect(browseScanDirButton, &QPushButton::clicked, this, &ScanningWidget::browseScanDir);

	mItemModel = QSharedPointer<QStandardItemModel>(new QStandardItemModel(0, 4, tableView));
	mItemModel->setHeaderData(0, Qt::Horizontal, Vietnamese::str(L"Số hiệu mảnh"));
	mItemModel->setHeaderData(1, Qt::Horizontal, Vietnamese::str(L"Thời gian"));
	mItemModel->setHeaderData(2, Qt::Horizontal, Vietnamese::str(L"Đường dẫn"));
	mItemModel->setHeaderData(3, Qt::Horizontal, Vietnamese::str(L"Trạng thái"));
	tableView->setModel(mItemModel.get());
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	tableView->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(tableView, SIGNAL(customContextMenuRequested(const QPoint&)),
		this, SLOT(slotCustomMenuRequested(const QPoint&)));
	
	auto it = GlobalVariables::mMapScaleProperties.begin();
	auto end = GlobalVariables::mMapScaleProperties.end();
	while (it != end)
	{
		const auto& scale = it.key();
		const auto& mapScaleProperty = it.value();
		mapScaleComboBox->addItem(mapScaleProperty.mName, QVariant::fromValue<MapScale>(scale));
		++it;
	}
}

ScanningWidget::~ScanningWidget()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}


void ScanningWidget::browseScanDir()
{
	auto dir = QFileDialog::getExistingDirectory(this, Vietnamese::str(L"Chọn thư mục cần quét"));
	if (!dir.isEmpty())
	{
		scanDirLineEdit->setText(dir);
	}
}

void ScanningWidget::scan() const
{
	auto scale = mapScaleComboBox->currentData().value<MapScale>();
	auto regExp = GlobalVariables::mMapScaleProperties[scale].mRegExp;
	auto dir = scanDirLineEdit->text().trimmed();
	if (dir.isEmpty())
		return;

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
	auto correctName = Utils::adjustMapName(name, MapScale::map25k);
	auto row = mItemModel->rowCount();
	mItemModel->insertRow(row);
	mItemModel->setItem(row, 0, new QStandardItem(correctName));
	mItemModel->setItem(row, 1, new QStandardItem(dateTime.toString("dd/MM/yyyy")));
	mItemModel->setItem(row, 2, new QStandardItem(path));
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
		tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
		});

	connect(saveAction, &QAction::triggered, [this] { saveTable(); });
	menu->popup(tableView->viewport()->mapToGlobal(p));
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
	for (auto row = 0; row < rowCount; ++row)
	{
		QStringList record;
		for (auto col = 0; col < 4; ++col)
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
