#include "ConnectionSettingDialog.h"
#include "OracleConnection.h"
#include "Vietnamese.h"

#include <spdlog/spdlog.h>
#include <odb/database.hxx>
#include <odb/oracle/database.hxx>

ConnectionSettingDialog::ConnectionSettingDialog(QWidget* parent)
	: QDialog(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);

	setupUi(this);
	setWindowFlag(Qt::WindowContextHelpButtonHint, false);
	setModal(true);
	mParams.load();
	hostLineEdit->setText(QString::fromStdString(mParams.mHost));
	portLineEdit->setText(QString::number(mParams.mPort));
	dbNameLineEdit->setText(QString::fromStdString(mParams.mDatabase));
	userLineEdit->setText(QString::fromStdString(mParams.mUser));
	passwordLineEdit->setText(QString::fromStdString(mParams.mPassword));

	connect(connectButton, &QPushButton::clicked, this, &ConnectionSettingDialog::testConnection);
	connect(okButton, &QPushButton::clicked, this, &ConnectionSettingDialog::apply);
	connect(cancelButton, &QPushButton::clicked, this, &ConnectionSettingDialog::close);
}

ConnectionSettingDialog::~ConnectionSettingDialog()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

const ConnectionParams& ConnectionSettingDialog::params() const
{
	return mParams;
}

void ConnectionSettingDialog::apply()
{
	spdlog::get("logger")->trace(__FUNCTION__);
	mParams.save();
	OracleConnection::connect();
	QDialog::accept();
}

void ConnectionSettingDialog::testConnection()
{
	spdlog::get("logger")->trace(__FUNCTION__);
	mParams.mHost = hostLineEdit->text().toStdString();
	mParams.mPort = portLineEdit->text().toInt();
	mParams.mDatabase = dbNameLineEdit->text().toStdString();
	mParams.mUser = userLineEdit->text().toStdString();
	mParams.mPassword = passwordLineEdit->text().toStdString();

	try
	{
		auto db = std::make_unique<odb::oracle::database>(
			mParams.mUser, mParams.mPassword,
			mParams.mDatabase, mParams.mHost, mParams.mPort);
		spdlog::get("logger")->info("Connected");
		noticeLabel->setText(Vietnamese::green(L"Kết nối thành công."));
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
		noticeLabel->setText(Vietnamese::red(L"Kết nối thất bại."));
	}
}