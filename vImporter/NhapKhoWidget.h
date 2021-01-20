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

private:
};

#endif