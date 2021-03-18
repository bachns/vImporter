#ifndef TULIEUTYPE_HXX
#define TULIEUTYPE_HXX

#include <QString>
#include <QDate>

#pragma db object table("TULIEUTYPE")
class TuLieuType
{
public:
#pragma db member id auto column("TULIEUTYPEID")
	size_t mTuLieuTypeId;

#pragma db member type("NVARCHAR2(50)") column("MA")
	QString mMa;

#pragma db member type("NVARCHAR2(255)") column("MOTA")
	QString mMoTa;

#pragma db member column("NHOMTULIEU")
	size_t mNhomTuLieu;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua;

#pragma db member column("TRANGTHAI")
	bool mTrangThai;
};

#endif