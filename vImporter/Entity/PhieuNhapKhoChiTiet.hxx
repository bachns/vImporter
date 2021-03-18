#ifndef PHIEUNHAPKHOCHITIET_HXX
#define PHIEUNHAPKHOCHITIET_HXX

#include <QString>
#include <QDate>
#include <odb/nullable.hxx>

#pragma db object table("PHIEUNHAPKHOCHITIET")
class PhieuNhapKhoChiTiet
{
public:
	PhieuNhapKhoChiTiet() {}
	PhieuNhapKhoChiTiet(size_t id_phieunhapkho, size_t id_tulieu)
		: mPhieuNhapKhoId(id_phieunhapkho), mTuLieuId(id_tulieu)
	{}

#pragma db member id auto column("PHIEUNHAPKHOCHITIETID")
	size_t mPhieuNhapKhoChiTietId = 0;

#pragma db member column("PHIEUNHAPKHOID")
	size_t mPhieuNhapKhoId = 0;

#pragma db member column("TULIEUID")
	size_t mTuLieuId = 0;

#pragma db member column("DONVITINHTYPEID")
	size_t mDonViTinhTypeId = 4;

#pragma db member column("SOLUONGCHUNGTU")
	size_t mSoLuongChungTu = 1;

#pragma db member column("SOLUONGMOC")
	odb::nullable<int> mSoLuongMoc;

#pragma db member column("DONGIAMOC")
	odb::nullable<double> mDonGiaMoc;

#pragma db member column("SOLUONGMAU")
	size_t mSoLuongMau = 1;
	
#pragma db member column("DONGIAMAU")
	double mDonGiaMau = 0.0;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;

#pragma db member column("DIADANHID")
	odb::nullable<int> mDiaDanhId;
};
#endif