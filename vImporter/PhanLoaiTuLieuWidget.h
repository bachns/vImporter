#ifndef PHANLOAITULIEUWIDGET_H
#define PHANLOAITULIEUWIDGET_H

#include <QWidget>
#include "ui_PhanLoaiTuLieuWidget.h"

class PhanLoaiTuLieuWidget : public QWidget, Ui::PhanLoaiTuLieuWidget
{
	Q_OBJECT

public:
	PhanLoaiTuLieuWidget(QWidget* parent = Q_NULLPTR);
	~PhanLoaiTuLieuWidget();
	void reload();

private:
	void loadCongVan();
	void loadNhomTuLieu();
	void loadLoaiTuLieu(size_t nhomTuLieuId);
};

#endif