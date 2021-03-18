#include "ThemCongVanDialog.h"
#include <spdlog/spdlog.h>
#include "Database.h"

#include "Kho.hxx"
#include "Kho-odb.hxx"
#include "NguoiKy.hxx"
#include "NguoiKy-odb.hxx"
#include "PhieuNhapKho.hxx"
#include "PhieuNhapKho-odb.hxx"

ThemCongVanDialog::ThemCongVanDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	setWindowFlag(Qt::WindowContextHelpButtonHint, false);
	setModal(true);
	ngayBanHanhDateEdit->setDate(QDate::currentDate());
	connect(okButton, &QPushButton::clicked, this, &ThemCongVanDialog::insert);
	connect(cancelButton, &QPushButton::clicked, this, &ThemCongVanDialog::close);
}

void ThemCongVanDialog::reload()
{
	spdlog::get("logger")->debug("Load CongVan");
	try
	{
		auto db = Database::m_database;
		odb::transaction t(db->begin());
		using KhoQuery = odb::query<Kho>;
		using KhoResult = odb::result<Kho>;
		KhoResult kho = db->query<Kho>(KhoQuery::mTuLieuSo == true);
		khoTuLieuComboBox->clear();
		for (const auto& k : kho)
			khoTuLieuComboBox->addItem(k.mTenKho, k.mKhoId);

		using NguoiKyResult = odb::result<NguoiKy>;
		NguoiKyResult nguoiki = db->query<NguoiKy>();
		nguoiKyComboBox->clear();
		for (const auto& n : nguoiki)
			nguoiKyComboBox->addItem(n.mTenNguoiKy, n.mNguoiKyId);

		t.commit();
	}
	catch (const odb::exception& e)
	{
		spdlog::get("logger")->error(e.what());
	}
}

void ThemCongVanDialog::insert()
{
	QString so_hieu = soHieuLineEdit->text().trimmed();
	if (so_hieu.isEmpty())
	{
		QDialog::reject();
		return;
	}
	
	const size_t id_kho = khoTuLieuComboBox->currentData().toInt();
	const QString& hoten_nguoiky = nguoiKyComboBox->currentText();
	const QDate& ngay_banhanh = ngayBanHanhDateEdit->date();
	
	try
	{
		auto db = Database::m_database;
		odb::transaction t(db->begin());
		auto phieu_nhapkho = make_unique<PhieuNhapKho>(id_kho, so_hieu, hoten_nguoiky, ngay_banhanh);
		db->persist(*phieu_nhapkho);
		t.commit();
		QDialog::accept();
	}
	catch (const odb::exception& e)
	{
		spdlog::get("logger")->error(e.what());
		QDialog::reject();
	}
}