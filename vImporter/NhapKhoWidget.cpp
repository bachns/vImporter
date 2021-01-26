#include "NhapKhoWidget.h"
#include "Vietnamese.h"
#include "GlobalVariables.h"
#include "Copier.h"

#include <QPointer>
#include <QThread>
#include <QFileDialog>
#include <spdlog/spdlog.h>

NhapKhoWidget::NhapKhoWidget(QWidget* parent)
	: QWidget(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);
	setupUi(this);
	progressBar->hide();

	connect(scanningWidget, &ScanningWidget::finished,
		[this](QSharedPointer<QStandardItemModel> model) { mItemModel = model; });

	connect(storeButton, &QPushButton::clicked, this, &NhapKhoWidget::store);
	connect(browseStoreDirButton, &QPushButton::clicked, this, &NhapKhoWidget::browseStoreDir);
}

NhapKhoWidget::~NhapKhoWidget()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

void NhapKhoWidget::reload()
{
	phanLoaiTuLieuWidget->reload();
}

void NhapKhoWidget::store() const
{
	if (mItemModel == nullptr && mItemModel->rowCount() == 0)
		return;

	auto storeDir = storeDirLineEdit->text();
	if (storeDir.trimmed().isEmpty())
		return;

	QPointer<Copier> copier(new Copier(mItemModel.get(), storeDir));
	QPointer<QThread> thread(new QThread());
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

void NhapKhoWidget::browseStoreDir()
{
	auto dir = QFileDialog::getExistingDirectory(this, Vietnamese::str(L"Chọn thư mục lưu"));
	if (!dir.isEmpty())
	{
		storeDirLineEdit->setText(dir);
	}
}

void NhapKhoWidget::copierStarted() const
{
	progressPathLabel->clear();
	progressBar->show();
	progressBar->setMaximum(mItemModel->rowCount());
	progressBar->setValue(0);
}

void NhapKhoWidget::copierFinished() const
{
	progressBar->hide();
	progressPathLabel->clear();
}

void NhapKhoWidget::copierProgress(const QString& path) const
{
	progressPathLabel->setText(path);
}

void NhapKhoWidget::copierProgress(int row) const
{
	progressBar->setValue(row + 1);
	mItemModel->setItem(row, 3, new QStandardItem(QIcon(":/icons/apply.svg"), "Xong"));
}