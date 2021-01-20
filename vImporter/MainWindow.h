#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <spdlog/spdlog.h>
#include "ui_MainWindow.h"
#include "ConnectionParams.h"

class MainWindow final : public QMainWindow, Ui::MainWindowClass
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void openSettingPage();

private:
	ConnectionParams mConnectionParams;
};

#endif