#ifndef CONNECTIONSETTINGDIALOG_H
#define CONNECTIONSETTINGDIALOG_H

#include "ui_ConnectionSettingDialog.h"
#include "ConnectionParams.h"

class ConnectionSettingDialog final : public QDialog, Ui::ConnectionSettingDialog
{
	Q_OBJECT

public:
	explicit ConnectionSettingDialog(QWidget* parent = Q_NULLPTR);
	~ConnectionSettingDialog() override;
	const ConnectionParams& params() const;

private slots:
	void testConnection();
	void apply();

private:

	ConnectionParams mParams;
};

#endif