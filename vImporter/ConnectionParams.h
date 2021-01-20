#ifndef CONNECTIONPARAMS_H
#define CONNECTIONPARAMS_H

#include <string>

class ConnectionParams
{
public:
	void load();
	void save() const;

	std::string mHost;
	int mPort = 0;
	std::string mDatabase;
	std::string mUser;
	std::string mPassword;
};

#endif