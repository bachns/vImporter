#include "MainWindow.h"
#include "Utils.h"

#include <QtWidgets/QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char* argv[])
{
	Utils::setupDefaultLogger();
	QApplication a(argc, argv);
	QFile f(":/qdarkstyle/style.qss");
	if (!f.exists())
	{
		spdlog::get("logger")->info("Unable to set stylesheet, file not found");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}
	MainWindow w;
	w.show();

	return QApplication::exec();
}