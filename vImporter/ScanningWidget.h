#ifndef MAPSHEETDB_H
#define MAPSHEETDB_H

#include "ui_ScanningWidget.h"

class QStandardItemModel;

class ScanningWidget final : public QWidget, Ui::ScanningWidget
{
	Q_OBJECT

public:
	explicit ScanningWidget(QWidget* parent = Q_NULLPTR);
	~ScanningWidget() override;

private slots:
	void scan() const;
	void browseScanDir();
	void scannerStarted() const;
	void scannerFinished() const;
	void scannerProgress(const QString& message) const;
	void scannerDetection(const QString& name, const QString& path,
		const QDateTime& dateTime) const;

	void store() const;
	void browseStoreDir();
	void copierStarted() const;
	void copierFinished() const;
	void copierProgress(const QString& path) const;
	void copierProgress(int row) const;

	void saveTable();

private:
	std::unique_ptr<QStandardItemModel> mItemModel;
	void loadTablesFromDatabase() const;
};

#endif