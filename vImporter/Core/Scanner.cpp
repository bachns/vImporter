#include "Scanner.h"
#include <QDirIterator>
#include <QRegExp>
#include <utility>

Scanner::Scanner(QString dir, QString regExp)
	: mDir(std::move(dir)), mRegExp(std::move(regExp))
{
}

void Scanner::run()
{
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
			const auto& lastModified = dateTimeModified(path);
			emit detected(name, path, lastModified);
			spdlog::get("logger")->debug("Detect [{}] [{}] [{}]", name.toStdString(),
				lastModified.toString("dd-MM-yyyy").toStdString(), path.toStdString());
		}
	}
	emit finished();
}

QDateTime Scanner::dateTimeModified(const QString& folder)
{
	QDateTime current = QDateTime::currentDateTime();
	QDirIterator it(folder, QStringList() << "*.doc" << "*.docx" << "*.pdf", QDir::Files, QDirIterator::Subdirectories);
	while (it.hasNext())
	{
		QFileInfo fileInfo(it.next());
		const QDateTime& fileDateTime = fileInfo.lastModified();
		if (current > fileDateTime)
			current = fileDateTime;
	}
	return current;
}