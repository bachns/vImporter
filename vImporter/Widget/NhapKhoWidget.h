#ifndef NHAPKHOWIDGET_H
#define NHAPKHOWIDGET_H

#include <QWidget>
#include <QMap>
#include <QString>
#include "ui_NhapKhoWidget.h"

class NhapKhoWidget : public QWidget, Ui::NhapKhoWidget
{
	Q_OBJECT

public:
	NhapKhoWidget(QWidget* parent = Q_NULLPTR);
	void reload();

private slots:
	void store();
	void browseStoreDir();
	void browseFtpDir();
	void copierStarted();
	void copierFinished() const;
	void copierProgress(const QString& path) const;
	void completeRow(int row, const QString& destination);
	void warnExists(int row);
	
	void themCongVan();
	void loadTenKhoTuLieu(int id);
	
private:
	QSharedPointer<QStandardItemModel> mItemModel;
	bool insertToDatabase(const QString& code, const QDate& date, const QString& destination);

	size_t m_id_tulieutype = 0;
	size_t m_id_tyletype = 0;
	QMap<QString, size_t> mHeQuyChieuType;
	QMap<QString, size_t> mPhuongPhapTLType;
	QString mScale;
};

#endif