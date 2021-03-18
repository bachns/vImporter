#ifndef MAPSHEETDB_H
#define MAPSHEETDB_H

#include "ui_ScanningWidget.h"

class QStandardItemModel;

class ScanningWidget final : public QWidget, Ui::ScanningWidget
{
	Q_OBJECT

public:
	explicit ScanningWidget(QWidget* parent = Q_NULLPTR);
	size_t idTyLeType() const;
	QString scaleText() const;

signals:
	void finished(QSharedPointer<QStandardItemModel>) const;

private slots:
	void scan();
	void browseScanDir();
	void scannerStarted() const;
	void scannerFinished() const;
	void scannerProgress(const QString& message) const;
	void scannerDetection(const QString& name, const QString& path,
		const QDateTime& dateTime) const;

	void slotCustomMenuRequested(const QPoint& p);
	void mapScaleComboBoxChanged(int index);
	
private:
	QSharedPointer<QStandardItemModel> mItemModel;
	void saveTable();
	void setTotalLabel(int count) const;
	void loadTyLeType();
	QMap<QString, QString> mRegExp;
	QString mScaleScan;
};

#endif