#include <memory>
#include <spdlog/spdlog.h>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/oracle/database.hxx>
#include "Database.h"
#include "Vietnamese.h"
#include "ConnectionParams.h"

std::shared_ptr<odb::database> Database::m_database = {};

Database::Database(QObject* parent)
	: QObject(parent)
{
}

bool Database::connect()
{
	bool successful = false;
	try
	{
		ConnectionParams params;
		params.load();

		const std::string& user = params.m_user.toStdString();
		const std::string& password = params.m_password.toStdString();
		const std::string& datbase = params.m_database.toStdString();
		const std::string& host = params.m_host.toStdString();
		unsigned int port = params.m_port;
		
		m_database = make_shared<odb::oracle::database>(user, password, datbase, host, port, 873, 873);
		odb::transaction t(m_database->begin());
		t.rollback();

		successful = true;
		spdlog::get("logger")->info("Connected to database successfully");
	}
	catch (const odb::exception& e)
	{
		spdlog::get("logger")->error(e.what());
		successful = false;
	}

	return successful;
}
