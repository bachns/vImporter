#include <QString>
#include <QMap>
#include <QFile>
#include <QTextStream>

#include "SimpleCrypt.h"
#include "ConnectionParams.h"

void ConnectionParams::load()
{
	QMap<QString, QString> config;
	config.insert("host", "localhost");
	config.insert("port", "1521");
	config.insert("database", "GIS");
	config.insert("user", "admin");
	config.insert("password", "123456");

	QFile file("connection.ini");
	if (file.open(QIODevice::Text | QIODevice::ReadOnly))
	{
		QTextStream reader(&file);
		while (reader.atEnd() == false)
		{
			const QString& line = reader.readLine();
			QStringList parts = line.split(":");
			if (parts.size() == 2)
				config[parts[0].trimmed()] = parts[1].trimmed();
		}
		file.close();
	}

	m_host = config["host"];
	m_port = config["port"].toInt();
	m_database = config["database"];
	m_user = config["user"];

	auto cypherPassword = config["password"];
	SimpleCrypt crypto(Q_UINT64_C(0x23f75bac40f50d89));
	m_password = crypto.decryptToString(cypherPassword);
}

void ConnectionParams::save() const
{
	QFile file("connection.ini");
	if (file.open(QIODevice::Text | QIODevice::WriteOnly))
	{
		QTextStream writer(&file);
		writer << "host:" << m_host << "\n";
		writer << "port:" << m_port << "\n";
		writer << "database:" << m_database << "\n";
		writer << "user:" << m_user << "\n";

		SimpleCrypt crypto(Q_UINT64_C(0x23f75bac40f50d89));
		auto cypherPassword = crypto.encryptToString(m_password);
		writer << "password:" << cypherPassword;

		file.close();
	}

	
}