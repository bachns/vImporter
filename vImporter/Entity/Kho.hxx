#ifndef KHO_HXX
#define KHO_HXX

#include <QString>
#include <QDate>

#pragma db object table("KHO")
class Kho
{
public:
#pragma db member id auto column("KHOID")
	size_t mKhoId = 0;

#pragma db member column("MAKHO") type("NVARCHAR2(50)")
	QString mMaKho;

#pragma db member column("TENKHO") type("NVARCHAR2(150)")
	QString mTenKho;

#pragma db member column("DIADIEM") type("NVARCHAR2(255)")
	QString mDiaDiem;

#pragma db member column("TULIEUSO")
	bool mTuLieuSo = true;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;

#pragma db member column("DULIEUDIADANH")
	size_t mDuLieuDiaDanh;
};

#endif