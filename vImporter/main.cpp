#include <QtWidgets/QApplication>
#include <QTextStream>
#include <QFile>
#include "MainWindow.h"
#include "ConnectionSettingDialog.h"
#include "Utils.h"
#include "Database.h"

int main(int argc, char* argv[])
{
	Utils::setupDefaultLogger();
	QApplication a(argc, argv);
	QFile f(":/qdarkstyle/style.qss");
	if (!f.exists())
	{
		spdlog::get("logger")->warn("Unable to set stylesheet, file not found");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	if (!Database::connect() && ConnectionSettingDialog::setup() != QDialog::Accepted)
	{
		spdlog::get("logger")->error("Cannot connect to database");
		return 1;
	}

	MainWindow w;
	w.showMaximized();
	return QApplication::exec();
}