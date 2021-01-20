#include "ScanningWidget.h"
#include "Vietnamese.h"
#include "GlobalVariables.h"
#include "Scanner.h"
#include "Copier.h"
#include "Utils.h"

#include <spdlog/spdlog.h>
#include <QThread>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QDateTime>
#include <QDebug>

ScanningWidget::ScanningWidget(QWidget* parent)
	: QWidget(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);

	setupUi(this);
	connect(scanButton, &QPushButton::clicked, this, &ScanningWidget::scan);
	connect(browseScanDirButton, &QPushButton::clicked, this, &ScanningWidget::browseScanDir);
	connect(storeButton, &QPushButton::clicked, this, &ScanningWidget::store);
	connect(browseStoreDirButton, &QPushButton::clicked, this, &ScanningWidget::browseStoreDir);
	connect(saveTableButton, &QPushButton::clicked, this, &ScanningWidget::saveTable);

	mItemModel = std::make_unique<QStandardItemModel>(0, 4, tableView);
	mItemModel->setHeaderData(0, Qt::Horizontal, Vietnamese::str(L"Số hiệu mảnh"));
	mItemModel->setHeaderData(1, Qt::Horizontal, Vietnamese::str(L"Thời gian"));
	mItemModel->setHeaderData(2, Qt::Horizontal, Vietnamese::str(L"Đường dẫn"));
	mItemModel->setHeaderData(3, Qt::Horizontal, Vietnamese::str(L"Trạng thái"));
	tableView->setModel(mItemModel.get());
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

	folderProgressLineEdit->setVisible(false);
	progressBar->hide();

	auto it = GlobalVariables::mMapScaleProperties.begin();
	auto end = GlobalVariables::mMapScaleProperties.end();
	while (it != end)
	{
		const auto& scale = it.key();
		const auto& mapScaleProperty = it.value();
		mapScaleComboBox->addItem(mapScaleProperty.mName, QVariant::fromValue<MapScale>(scale));
		++it;
	}
	loadTablesFromDatabase();
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

	auto* scanner = new Scanner(dir, regExp);
	auto* thread = new QThread();
	scanner->moveToThread(thread);

	connect(scanner, SIGNAL(started()), this, SLOT(scannerStarted()));
	connect(scanner, SIGNAL(finished()), this, SLOT(scannerFinished()));
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
	folderProgressLineEdit->setVisible(true);
	auto rowCount = mItemModel->rowCount();
	mItemModel->removeRows(0, rowCount);
}

void ScanningWidget::scannerFinished() const
{
	folderProgressLineEdit->setVisible(false);
	QApplication::beep();
}

void ScanningWidget::scannerProgress(const QString& message) const
{
	folderProgressLineEdit->setText(message);
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
}

void ScanningWidget::store() const
{
	if (mItemModel->rowCount() == 0)
		return;

	auto storeDir = storeDirLineEdit->text();
	if (storeDir.trimmed().isEmpty())
		return;

	auto* copier = new Copier(mItemModel.get(), storeDir);
	auto* thread = new QThread();
	copier->moveToThread(thread);

	connect(copier, SIGNAL(started()), this, SLOT(copierStarted()));
	connect(copier, SIGNAL(finished()), this, SLOT(copierFinished()));
	connect(copier, SIGNAL(progressPath(const QString&)), this, SLOT(copierProgress(const QString&)));
	connect(copier, SIGNAL(progress(int)), this, SLOT(copierProgress(int)));

	connect(copier, SIGNAL(finished()), thread, SLOT(quit()));
	connect(copier, SIGNAL(finished()), copier, SLOT(deleteLater()));
	connect(thread, SIGNAL(started()), copier, SLOT(run()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}

void ScanningWidget::browseStoreDir()
{
	auto dir = QFileDialog::getExistingDirectory(this, Vietnamese::str(L"Chọn thư mục lưu"));
	if (!dir.isEmpty())
	{
		storeDirLineEdit->setText(dir);
	}
}

void ScanningWidget::copierStarted() const
{
	progressPathLabel->clear();
	progressBar->show();
	progressBar->setMaximum(mItemModel->rowCount());
	progressBar->setValue(0);
}

void ScanningWidget::copierFinished() const
{
	progressBar->hide();
	progressPathLabel->clear();
}

void ScanningWidget::copierProgress(const QString& path) const
{
	if (path.length() > 48)
		progressPathLabel->setText(path.left(24) + " ... " + path.right(24));
	else
		progressPathLabel->setText(path);
}

void ScanningWidget::copierProgress(int row) const
{
	progressBar->setValue(row + 1);
	mItemModel->setItem(row, 3, new QStandardItem(QIcon(":/icons/apply.svg"), "Xong"));
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
}

void ScanningWidget::loadTablesFromDatabase() const
{
}