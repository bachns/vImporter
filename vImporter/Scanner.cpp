#include <QDateTime>
#include "Scanner.h"
#include <QDirIterator>
#include <QRegExp>
#include <utility>

Scanner::Scanner(QString dir, QString regExp)
	: mDir(std::move(dir)), mRegExp(std::move(regExp))
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

Scanner::~Scanner()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

void Scanner::run()
{
	spdlog::get("logger")->debug(__FUNCTION__);

	emit started();
	QRegExp re(mRegExp);
	QDirIterator it(mDir, QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
	while (it.hasNext())
	{
		const auto& path = it.next();
		QFileInfo fileInfo(path);
		emit progressPath(path);
		const auto& name = fileInfo.baseName();
		if (re.exactMatch(name) && fileInfo.suffix().isEmpty())
		{
			const auto& lastModified = fileInfo.lastModified();
			emit detected(name, path, lastModified);
		}
	}
	emit finished();
}