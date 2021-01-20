#ifndef TULIEUTYPE_HXX
#define TULIEUTYPE_HXX

#include <QString>
#include <QDate>

class TuLieuType
{
public:
	size_t mTuLieuTypeId;
	QString mMa;
	QString mMoTa;
	size_t mNhomTuLieu;
	size_t mNguoiSuaId;
	QDate mNgayChinhSua;
	bool mTrangThai;
};

#pragma db object(TuLieuType) table("TULIEUTYPE")
#pragma db member(TuLieuType::mTuLieuTypeId) id auto column("TULIEUTYPEID")
#pragma db member(TuLieuType::mMa) type("NVARCHAR2(50)") column("MA")
#pragma db member(TuLieuType::mMoTa) type("NVARCHAR2(50)") column("MOTA")
#pragma db member(TuLieuType::mNhomTuLieu) column("NHOMTULIEU")
#pragma db member(TuLieuType::mNguoiSuaId) column("NGUOISUAID")
#pragma db member(TuLieuType::mNgayChinhSua) column("NGAYCHINHSUA")
#pragma db member(TuLieuType::mTrangThai) column("TRANGTHAI")

#endif