#ifndef TONKHO_HXX
#define TONKHO_HXX

#include <QString>
#include <QDate>
#include <odb/nullable.hxx>

#pragma db object table("TONKHO")
class TonKho
{
public:
	TonKho() = default;
	TonKho(size_t id_kho, size_t id_tulieu)
		: mKhoId(id_kho), mTuLieuId(id_tulieu)
	{
	}

#pragma db member id auto column("TONKHOID")
	size_t mTonKhoId = 0;

#pragma db member column("KHOID")
	size_t mKhoId = 0;

#pragma db member column("TULIEUID")
	size_t mTuLieuId = 0;

#pragma db member column("SOLUONGCHUNGTU")
	int mSoLuongChungTu = 1;

#pragma db member column("SOLUONGMOC")
	int soLuongMoc = 0;

#pragma db member column("SOLUONGMAU")
	int soLuongMau = 1;

#pragma db member column("NGUOISUAID")
	int mNguoiSuaID = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;

#pragma db member column("DIADANHID")
	odb::nullable<int> mDiaDanhId;
};



#endif