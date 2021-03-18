#ifndef CONNECTIONPARAMS_H
#define CONNECTIONPARAMS_H

class QString;

class ConnectionParams
{
public:
	void load();
	void save() const;

	QString m_host;
	int m_port = 0;
	QString m_database;
	QString m_user;
	QString m_password;
};

#endif