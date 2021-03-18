#ifndef DATABASE_H
#define DATABASE_H

#include <memory>
#include <QObject>
#include <odb/database.hxx>

using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;

class Database : public QObject
{
	Q_OBJECT

public:
	Database(QObject *parent);
	static bool connect();
	static shared_ptr<odb::database> m_database;
};

#endif