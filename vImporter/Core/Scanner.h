#ifndef SCANNER_H
#define SCANNER_H

#include <spdlog/spdlog.h>
#include <QObject>
#include <QString>
#include <QDateTime>

class Scanner final : public QObject
{
	Q_OBJECT

public:
	Scanner(QString dir, QString regExp);

private slots:
	void run();

signals:
	void started();
	void finished();
	void progressPath(const QString& path);
	void detected(const QString& name, const QString& path, const QDateTime& lastModified);

private:
	QString mDir;
	QString mRegExp;

	static QDateTime dateTimeModified(const QString& folder);
};

#endif