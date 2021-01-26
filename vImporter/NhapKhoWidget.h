#ifndef NHAPKHOWIDGET_H
#define NHAPKHOWIDGET_H

#include <QWidget>
#include "ui_NhapKhoWidget.h"

class NhapKhoWidget : public QWidget, Ui::NhapKhoWidget
{
	Q_OBJECT

public:
	NhapKhoWidget(QWidget* parent = Q_NULLPTR);
	~NhapKhoWidget();
	void reload();

private slots:
	void store() const;
	void browseStoreDir();
	void copierStarted() const;
	void copierFinished() const;
	void copierProgress(const QString& path) const;
	void copierProgress(int row) const;

private:
	QSharedPointer<QStandardItemModel> mItemModel;
};

#endif