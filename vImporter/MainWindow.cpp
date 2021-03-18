#include "MainWindow.h"
#include "ConnectionSettingDialog.h"

#include <spdlog/spdlog.h>

#include <odb/database.hxx>
#include <odb/oracle/database.hxx>
#include <odb/transaction.hxx>

#include "MapInfo.h"
#include "NhomTuLieu.hxx"
#include "NhomTuLieu-odb.hxx"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setupUi(this);
	MapInfo::read();
	connect(bdsPageButton, &QPushButton::clicked, [this] { stackedWidget->setCurrentWidget(nhapKhoWidget); });
	connect(settingButton, &QPushButton::clicked, [this] { openSettingPage(); });
}

void MainWindow::openSettingPage()
{
	auto connDialog = std::make_unique<ConnectionSettingDialog>(this);
	if (connDialog->exec() == QDialog::Accepted)
	{
		mConnectionParams.save();
		nhapKhoWidget->reload();
	}
}