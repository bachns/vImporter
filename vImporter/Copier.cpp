#include "Copier.h"
#include <QDirIterator>

Copier::Copier(QStandardItemModel* model, const QString& storeDir)
	: mItemModel(model), mStoreDir(storeDir)
{
}

QString Copier::adjustDateFormat(const QString& date)
{
	return date.right(4) + "_" + date.mid(3, 2) + "_" + date.left(2);
}

void Copier::copyDir(const QString& sourceDir, const QString& destinationDir)
{
	QDir dir(sourceDir);
	if (!dir.exists())
		return;

	QStringList subDirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
	for(const QString& subDir : subDirs)
	{
		QString sourceSubDir = sourceDir + "/" + subDir;
		QString destinationSubDir = destinationDir + "/" + subDir;
		dir.mkpath(destinationSubDir);
		copyDir(sourceSubDir, destinationSubDir);
	}

	QStringList files = dir.entryList(QDir::Files);
	for (const QString& file : files)
	{
		QString source = sourceDir + "/" + file;
		QString destination = destinationDir + "/" + file;
		QFile::copy(source, destination);
		emit progressPath(destination);
	}
}

void Copier::run()
{
	if (mItemModel == nullptr)
	{
		qDebug("mItemModel is nullptr");
		return;
	}

	emit started();
	auto rowCount = mItemModel->rowCount();
	for (int row = 0; row < rowCount; ++row)
	{
		const QString& name = mItemModel->item(row, 0)->text();
		const QString& date = adjustDateFormat(mItemModel->item(row, 1)->text());
		const QString& source = mItemModel->item(row, 2)->text();
		const QString& destination = mStoreDir + "/" + name + "/" + date;

		copyDir(source, destination);
		emit progress(row);
	}
	emit finished();
}
