#ifndef THEMCONGVANDIALOG_H
#define THEMCONGVANDIALOG_H

#include <QDialog>
#include "ui_ThemCongVanDialog.h"

class ThemCongVanDialog : public QDialog, Ui::ThemCongVanDialog
{
	Q_OBJECT

public:
	ThemCongVanDialog(QWidget *parent = Q_NULLPTR);
	void reload();

private slots:
	void insert();

};

#endif