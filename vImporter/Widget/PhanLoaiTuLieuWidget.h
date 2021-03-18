#ifndef PHANLOAITULIEUWIDGET_H
#define PHANLOAITULIEUWIDGET_H

#include <QWidget>
#include "ui_PhanLoaiTuLieuWidget.h"

class PhanLoaiTuLieuWidget : public QWidget, Ui::PhanLoaiTuLieuWidget
{
	Q_OBJECT

public:
	explicit PhanLoaiTuLieuWidget(QWidget* parent = Q_NULLPTR);
	size_t idLoadLoaiTuLieu() const;
	void reload();

private slots:
	void loadLoaiTuLieu(int idx);

};

#endif