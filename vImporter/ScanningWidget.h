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

signals:
	void finished(QSharedPointer<QStandardItemModel>) const;

private slots:
	void scan() const;
	void browseScanDir();
	void scannerStarted() const;
	void scannerFinished() const;
	void scannerProgress(const QString& message) const;
	void scannerDetection(const QString& name, const QString& path,
		const QDateTime& dateTime) const;

	void slotCustomMenuRequested(const QPoint& p);
	
private:
	QSharedPointer<QStandardItemModel> mItemModel;
	void saveTable();
	void setTotalLabel(int count) const;
};

#endif