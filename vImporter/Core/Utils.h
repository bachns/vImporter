#ifndef UTILS_H
#define UTILS_H

#include <spdlog/spdlog.h>
#include <QString>
#include <QMap>

class Utils
{
public:
	Utils() = default;
	static QString adjustMapName(const QString& name, const QString& scale);
	static void setupDefaultLogger();
	static void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
	static QMap<QString, QString> m50;
	static QMap<QString, QString> m25;
};

#endif