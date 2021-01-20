#ifndef TULIEU_HXX
#define TULIEU_HXX

#include <QString>
#include <QDate>

class TuLieu
{
public:
	size_t mTuLieuId;
	size_t mTuLieuTypeId;
	QString mMaTuLieu;
	QString mTenTuLieu;
	double mDonGia;
	size_t mNguoiSuaID;
	QDate mNgayChinhSua;
	bool mTrangThai;
};

#pragma db object(TuLieu) table ("TULIEU")
#pragma db member(TuLieu::mTuLieuId) id auto column("TULIEUID")
#pragma db member(TuLieu::mTuLieuTypeId) column("TULIEUTYPEID")
#pragma db member(TuLieu::mMaTuLieu) column("MATULIEU")
#pragma db member(TuLieu::mTenTuLieu) column("TENTULIEU")
#pragma db member(TuLieu::mDonGia) column("DONGIA")
#pragma db member(TuLieu::mNguoiSuaID) column("NGUOISUAID")
#pragma db member(TuLieu::mNgayChinhSua) column("NGAYCHINHSUA")
#pragma db member(TuLieu::mTrangThai) column("TRANGTHAI")

#endif