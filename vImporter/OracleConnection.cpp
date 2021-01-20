#include "OracleConnection.h"
#include "ConnectionParams.h"

#include <spdlog/spdlog.h>
#include <odb/oracle/database.hxx>

std::shared_ptr<odb::database> OracleConnection::mDatabase = nullptr;

std::shared_ptr<odb::database> OracleConnection::database()
{
	if (mDatabase == nullptr)
		connect();

	return mDatabase;
}

void OracleConnection::connect()
{
	spdlog::get("logger")->debug(__FUNCTION__);

	ConnectionParams params;
	params.load();
	try
	{
		mDatabase = std::make_unique<odb::oracle::database>(
			params.mUser, params.mPassword,
			params.mDatabase, params.mHost, params.mPort,
			873, 873);
		spdlog::get("logger")->debug("Connected");
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
		spdlog::get("logger")->error("Failed");
	}
}