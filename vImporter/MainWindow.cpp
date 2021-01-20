#include "MainWindow.h"
#include "OracleConnection.h"
#include "ConnectionSettingDialog.h"

#include <spdlog/spdlog.h>

#include <odb/database.hxx>
#include <odb/oracle/database.hxx>
#include <odb/transaction.hxx>

#include "NhomTuLieu.hxx"
#include "NhomTuLieu-odb.hxx"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);
	setupUi(this);
	connect(settingButton, &QPushButton::clicked, [this] { openSettingPage(); });
}

MainWindow::~MainWindow()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

void MainWindow::openSettingPage()
{
	auto connDialog = std::make_unique<ConnectionSettingDialog>(this);
	if (connDialog->exec() == QDialog::Accepted)
	{
		mConnectionParams.load();
		nhapKhoWidget->reload();
	}
}