#ifndef ORACLECONNECTION_H
#define ORACLECONNECTION_H

#include <odb/database.hxx>
class OracleConnection
{
public:
	static void connect();
	static std::shared_ptr<odb::database> database();

private:
	static std::shared_ptr<odb::database> mDatabase;
};

#endif