#include "PhanLoaiTuLieuWidget.h"
#include "Vietnamese.h"
#include "ConnectionParams.h"
#include "Database.h"
#include "NhomTuLieu.hxx"
#include "NhomTuLieu-odb.hxx"
#include "TuLieuType.hxx"
#include "TuLieuType-odb.hxx"

#include <spdlog/spdlog.h>
#include <odb/transaction.hxx>

PhanLoaiTuLieuWidget::PhanLoaiTuLieuWidget(QWidget* parent)
	: QWidget(parent)
{
	setupUi(this);
}

size_t PhanLoaiTuLieuWidget::idLoadLoaiTuLieu() const
{
	int idx = loaiTuLieuComboBox->currentIndex();
	return loaiTuLieuComboBox->itemData(idx).toInt();
}

void PhanLoaiTuLieuWidget::reload()
{
	spdlog::get("logger")->debug("Load NhomTuLieu");
	disconnect(nhomTuLieuComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &PhanLoaiTuLieuWidget::loadLoaiTuLieu);

	try
	{
		auto db = Database::m_database;
		odb::transaction t(db->begin());

		using NhomTuLieuResult = odb::result<NhomTuLieu>;
		NhomTuLieuResult nhomtl(db->query<NhomTuLieu>("ORDER BY"+ odb::query<NhomTuLieu>::mTenNhomTuLieu));
		
		nhomTuLieuComboBox->clear();
		for (const auto& n : nhomtl)
			nhomTuLieuComboBox->addItem(n.mTenNhomTuLieu, n.mNhomTuLieuId);

		t.commit();
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
	}

	if (nhomTuLieuComboBox->count() > 0)
	{
		connect(nhomTuLieuComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
			this, &PhanLoaiTuLieuWidget::loadLoaiTuLieu);
		loadLoaiTuLieu(0);
	}
}

void PhanLoaiTuLieuWidget::loadLoaiTuLieu(int idx)
{
	spdlog::get("logger")->debug("Load TuLieuType");
	try
	{
		auto id = nhomTuLieuComboBox->itemData(idx).toInt();
		auto db = Database::m_database;
		odb::transaction t(db->begin());
		using TuLieuTypeQuery = odb::query<TuLieuType>;
		using TuLieuTypeResult = odb::result<TuLieuType>;
		TuLieuTypeResult tltype(db->query<TuLieuType>(TuLieuTypeQuery::mNhomTuLieu == id));
		loaiTuLieuComboBox->clear();
		for (const auto& type : tltype)
			loaiTuLieuComboBox->addItem(type.mMoTa, type.mTuLieuTypeId);
		
		t.commit();
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
	}
}