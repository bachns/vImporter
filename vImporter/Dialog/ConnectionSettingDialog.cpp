#include "ConnectionSettingDialog.h"
#include "Vietnamese.h"
#include "Database.h"
#include <spdlog/spdlog.h>
#include <odb/database.hxx>
#include <odb/oracle/database.hxx>
#include "Database.h"

ConnectionSettingDialog::ConnectionSettingDialog(QWidget* parent)
	: QDialog(parent)
{
	setupUi(this);
	setWindowFlag(Qt::WindowContextHelpButtonHint, false);
	setModal(true);
	mParams.load();
	hostLineEdit->setText(mParams.m_host);
	portLineEdit->setText(QString::number(mParams.m_port));
	dbNameLineEdit->setText(mParams.m_database);
	userLineEdit->setText(mParams.m_user);
	passwordLineEdit->setText(mParams.m_password);

	connect(connectButton, &QPushButton::clicked, this, &ConnectionSettingDialog::testConnection);
	connect(okButton, &QPushButton::clicked, this, &ConnectionSettingDialog::apply);
	connect(cancelButton, &QPushButton::clicked, this, &ConnectionSettingDialog::close);
}

const ConnectionParams& ConnectionSettingDialog::params() const
{
	return mParams;
}

int ConnectionSettingDialog::setup()
{
	auto dialog = make_unique<ConnectionSettingDialog>();
	return dialog->exec();
}

void ConnectionSettingDialog::apply()
{
	mParams.save();

	const std::string& user = mParams.m_user.toStdString();
	const std::string& password = mParams.m_password.toStdString();
	const std::string& database = mParams.m_database.toStdString();
	const std::string& host = mParams.m_host.toStdString();
	const int port = mParams.m_port;

	Database::m_database = make_shared<odb::oracle::database>(user, password, database, host, port, 873, 873);
	
	if (mSuccessful)
		QDialog::accept();
	else
		QDialog::reject();
}

void ConnectionSettingDialog::testConnection()
{
	mParams.m_host = hostLineEdit->text();
	mParams.m_port = portLineEdit->text().toInt();
	mParams.m_database = dbNameLineEdit->text();
	mParams.m_user = userLineEdit->text();
	mParams.m_password = passwordLineEdit->text();

	try
	{
		const std::string& user = mParams.m_user.toStdString();
		const std::string& password = mParams.m_password.toStdString();
		const std::string& database = mParams.m_database.toStdString();
		const std::string& host = mParams.m_host.toStdString();
		const int port = mParams.m_port;

		auto db = make_unique<odb::oracle::database>(user, password, database, host, port, 873, 873);
		odb::transaction t(db->begin());
		t.rollback();

		mSuccessful = true;
		spdlog::get("logger")->debug("Test connection: Ok");
		noticeLabel->setText(Vietnamese::green(L"Kết nối thành công."));
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->debug("Test connection: Failed {}", ex.what());
		noticeLabel->setText(Vietnamese::red(L"Kết nối thất bại."));
	}
}