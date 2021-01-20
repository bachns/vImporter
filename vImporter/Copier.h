#ifndef COPIER_H
#define COPIER_H

#include <QObject>
#include <QStandardItemModel>

class Copier : public QObject
{
	Q_OBJECT

public:
	Copier(QStandardItemModel* model, const QString& storeDir);

private slots:
	void run();

signals:
	void started();
	void finished();
	void progressPath(const QString& path);
	void progress(int row);

private:
	QStandardItemModel* mItemModel = nullptr;
	QString mStoreDir;
	void copyDir(const QString& sourceDir, const QString& destinationDir);
	static QString adjustDateFormat(const QString& date);
};

#endif