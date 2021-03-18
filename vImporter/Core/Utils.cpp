#include "Utils.h"
#include <QDebug>
#include "Scanner.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/logger.h>

QMap<QString, QString> Utils::m50{
		{"I", "I"},
		{"1", "I"},
		{"II", "II"},
		{"2", "II"},
		{"III", "III"},
		{"3", "III"},
		{"IV", "IV"},
		{"4", "IV"} };

QMap<QString, QString> Utils::m25{
		{ "DB", "DB" },
		{ QString::fromStdWString(L"ĐB"), "DB" },
		{ "DN", "DN" },
		{ QString::fromStdWString(L"ĐN"), "DN"},
		{"TB", "TB"},
		{"TN", "TN"} };

QString Utils::adjustMapName(const QString& name, const QString& scale)
{
	static QRegExp re("\\s+|_+|-+");
	QStringList partRaws = name.toUpper().split(re);
	QStringList parts;
	for (const QString& partRaw : partRaws)
	{
		const QString& part = partRaw.trimmed();
		if (!part.isEmpty())
		{
			parts.append(part);
		}
	}

	//Các tỉ lệ từ 250K đến 1M
	if (scale == "1/250.000" || scale == "1/500.000" || scale == "1/1.000.000")
		return parts.join("-");

	if (scale == "1/100.000" && parts.size() == 1)
	{
		return parts.at(0);
	}

	if (scale == "1/50.000" && parts.size() == 2)
	{
		const QString& str = parts.at(1);
		if (m50.contains(str))
			return parts.at(0) + "-" + m50[str];

		return QString();
	}

	QStringList result;
	if (scale == "1/25.000" && parts.size() == 2) //xử lý trường hợp kiểu như sau: 6632-3TN, 6632-1TB
	{
		const QString& str = parts.at(1);
		const QString& middle = str.left(str.length() - 2);
		const QString& last = str.right(2);
		if (m50.contains(middle) && m25.contains(last))
		{
			result << parts.at(0) << m50[middle] << m25[last];
		}
	}

	else if (scale == "1/25.000" && parts.size() == 3)
	{
		const QString& middle = parts.at(1);
		const QString& last = parts.at(2);
		if (m50.contains(middle) && m25.contains(last))
		{
			result << parts.at(0) << m50[middle] << m25[last];
		}
	}
	return result.join("-");
}

void Utils::setupDefaultLogger()
{
	auto consoleLogger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	consoleLogger->set_level(spdlog::level::trace);

	auto maxSize = 1048576 * 5;
	auto maxFiles = 3;
	auto fileLogger = std::make_shared <spdlog::sinks::rotating_file_sink_mt>("logs/log.log", maxSize, maxFiles);
	fileLogger->set_level(spdlog::level::trace);

	auto logger = std::make_shared<spdlog::logger>("logger", spdlog::sinks_init_list{ consoleLogger, fileLogger });
	logger->set_level(spdlog::level::trace);
	spdlog::set_default_logger(logger);

	qInstallMessageHandler(Utils::messageHandler);
}

void Utils::messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	Q_UNUSED(context)

	switch (type)
	{
	case QtDebugMsg:
		spdlog::get("logger")->debug(msg.toStdString());
		break;

	case QtInfoMsg:
		spdlog::get("logger")->info(msg.toStdString());
		break;

	case QtWarningMsg:
		spdlog::get("logger")->warn(msg.toStdString());
		break;

	case QtCriticalMsg:
		spdlog::get("logger")->error(msg.toStdString());
		break;

	case QtFatalMsg:
		spdlog::get("logger")->critical(msg.toStdString());

	default:
		break;
	}
}