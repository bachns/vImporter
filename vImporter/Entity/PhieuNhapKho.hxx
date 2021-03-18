#ifndef PHIEUNHAPKHO_HXX
#define PHIEUNHAPKHO_HXX

#include <QString>
#include <QDate>

#pragma db object table("PHIEUNHAPKHO")
class PhieuNhapKho
{

public:
	PhieuNhapKho(){}
	PhieuNhapKho(size_t id_kho, const QString& so_cv, const QString& nguoi_ki, const QDate& ngay_ki)
		: mKhoId(id_kho)
		, mSoPhieu(so_cv)
		, mTenNguoiGiao(nguoi_ki)
		, mNgayNhapKho(ngay_ki)
	{}

#pragma db member id auto column("PHIEUNHAPKHOID")
	size_t mPhieuNhapKhoId = 0;

#pragma db member column("KHOID")
	size_t mKhoId = 0;

#pragma db member column("DANHMUCCOQUANTYPEID")
	size_t mDanhMucCoQuanTypeId = 1020;

#pragma db member column("SOPHIEU") type("NVARCHAR2(50)") 
	QString mSoPhieu;

#pragma db member column("TENNGUOIGIAO") type("NVARCHAR2(50)")
	QString mTenNguoiGiao;

#pragma db member column("NGAYNHAPKHO")
	QDate mNgayNhapKho;

#pragma db member column("GHICHU") type("NVARCHAR2(255)")
	QString mGhiChu;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;
};


#endif