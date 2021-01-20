#include "PhanLoaiTuLieuWidget.h"
#include "Vietnamese.h"
#include "ConnectionParams.h"
#include "OracleConnection.h"
#include "NhomTuLieu.hxx"
#include "NhomTuLieu-odb.hxx"
#include "TuLieuType.hxx"
#include "TuLieuType-odb.hxx"

#include <spdlog/spdlog.h>
#include <odb/transaction.hxx>

PhanLoaiTuLieuWidget::PhanLoaiTuLieuWidget(QWidget* parent)
	: QWidget(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);
	setupUi(this);
	reload();
	connect(nhomTuLieuComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
		[this](int index)
		{
			size_t id = nhomTuLieuComboBox->itemData(index).toInt();
			this->loadLoaiTuLieu(id);
		});
}

PhanLoaiTuLieuWidget::~PhanLoaiTuLieuWidget()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

void PhanLoaiTuLieuWidget::reload()
{
	loadCongVan();
	loadNhomTuLieu();
}

void PhanLoaiTuLieuWidget::loadCongVan()
{
	spdlog::get("logger")->debug(__FUNCTION__);
	try
	{
		auto db = OracleConnection::database();
		odb::transaction t(db->begin());
		using result_t = odb::result<NhomTuLieu>;
		result_t r(db->query<NhomTuLieu>());

		nhomTuLieuComboBox->clear();
		for (result_t::iterator it = r.begin(); it != r.end(); ++it)
		{
			if (it->mTenNhomTuLieu.isEmpty())
				continue;

			nhomTuLieuComboBox->addItem(it->mTenNhomTuLieu, it->mNhomTuLieuId);
		}
		t.commit();
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
	}
}

void PhanLoaiTuLieuWidget::loadNhomTuLieu()
{
	spdlog::get("logger")->debug(__FUNCTION__);
	try
	{
		auto db = OracleConnection::database();
		odb::transaction t(db->begin());
		using result_t = odb::result<NhomTuLieu>;
		result_t r(db->query<NhomTuLieu>());

		nhomTuLieuComboBox->clear();
		for (result_t::iterator it = r.begin(); it != r.end(); ++it)
		{
			if (it->mTenNhomTuLieu.isEmpty())
				continue;

			nhomTuLieuComboBox->addItem(it->mTenNhomTuLieu, it->mNhomTuLieuId);
		}
		t.commit();
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
	}
}

void PhanLoaiTuLieuWidget::loadLoaiTuLieu(size_t nhomTuLieuId)
{
	spdlog::get("logger")->debug("{}({})", __FUNCTION__, nhomTuLieuId);
	try
	{
		auto db = OracleConnection::database();
		odb::transaction t(db->begin());
		using query_t = odb::query<TuLieuType>;
		using result_t = odb::result<TuLieuType>;
		result_t r(db->query<TuLieuType>(query_t::mNhomTuLieu == nhomTuLieuId));

		loaiTuLieuComboBox->clear();
		for (result_t::iterator it = r.begin(); it != r.end(); ++it)
		{
			if (it->mMa.isEmpty())
				continue;

			loaiTuLieuComboBox->addItem(it->mMoTa, it->mTuLieuTypeId);
		}
		t.commit();
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
	}
}