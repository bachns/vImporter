#ifndef NGUOIKY_HXX
#define NGUOIKY_HXX

#include <QString>
#include <QDate>

#pragma db object table("NGUOIKY")
class NguoiKy
{

public:
#pragma db member id auto column("NGUOIKYID")
	size_t mNguoiKyId = 0;

#pragma db member column("TENNGUOIKY") type("NVARCHAR2(255)")
	QString mTenNguoiKy;

#pragma db member column("EMAIL") type("NVARCHAR2(255)")
	QString mEmail;

#pragma db member column("DIENTHOAI") type("NVARCHAR2(255)")
	QString mDienThoai;

#pragma db member column("CHUCVU") type("NVARCHAR2(255)")
	QString mChucVu;

#pragma db member column("TENCOQUAN") type("NVARCHAR2(255)")
	QString mTenCoQuan;

#pragma db member column("DIACHI") type("NVARCHAR2(255)")
	QString mDiaChi;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;
};

#endif
