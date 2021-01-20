#include "ConnectionParams.h"

#include "SimpleCrypt.h"
#include <spdlog/spdlog.h>
#include <QSettings>

void ConnectionParams::load()
{
	spdlog::get("logger")->trace(__FUNCTION__);
	QSettings settings("BachNguyen", "vImporter");
	mHost = settings.value("HostName", "localhost").toString().toStdString();
	mPort = settings.value("Port", 1521).toInt();
	mDatabase = settings.value("DatabaseName", QString()).toString().toStdString();
	mUser = settings.value("User", QString()).toString().toStdString();
	mPassword = "";

	auto cypherPassword = settings.value("Password", QString()).toString();
	SimpleCrypt crypto(Q_UINT64_C(0x23f75bac40f50d89));
	if (!cypherPassword.isEmpty())
	{
		mPassword = crypto.decryptToString(cypherPassword).toStdString();
	}
}

void ConnectionParams::save() const
{
	spdlog::get("logger")->trace(__FUNCTION__);
	SimpleCrypt crypto(Q_UINT64_C(0x23f75bac40f50d89));
	auto cypherPassword = crypto.encryptToString(QString::fromStdString(mPassword));
	QSettings settings("BachNguyen", "vImporter");
	settings.setValue("HostName", QString::fromStdString(mHost));
	settings.setValue("Port", mPort);
	settings.setValue("DatabaseName", QString::fromStdString(mDatabase));
	settings.setValue("User", QString::fromStdString(mUser));
	settings.setValue("Password", cypherPassword);
}