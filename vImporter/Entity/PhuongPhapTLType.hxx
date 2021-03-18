#ifndef PHUONGPHAPTLTYPE_HXX
#define PHUONGPHAPTLTYPE_HXX

#include <QString>
#include <QDate>

#pragma db object table("PHUONGPHAPTLTYPE")
class PhuongPhapTLType
{
public:

#pragma db member id auto column("PHUONGPHAPTLTYPEID")
	size_t mPhuongPhapTLTypeId;

#pragma db member type("NVARCHAR2(50)") column("MA")
	QString mMa;

#pragma db member type("NVARCHAR2(50)") column("MOTA")
	QString mMoTa;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua;

#pragma db member column("TRANGTHAI")
	bool mTrangThai;
};

#endif
