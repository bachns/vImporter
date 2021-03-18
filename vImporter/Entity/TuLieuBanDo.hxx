#ifndef TULIEUBANDO_H
#define TULIEUBANDO_H

#include <QString>
#include <QDate>
#include <odb/nullable.hxx>

#pragma db object table("TULIEUBANDO")
class TuLieuBanDo
{
public:
	TuLieuBanDo() {}
	TuLieuBanDo(size_t id_tu_lieu, size_t id_ty_le,
		const QString& phien_hieu, const QString& ten_manh, const QString& khoang_caodeu, 
		size_t id_he_toado, const QString& mui_chieu,
		const QString& nam_sanxuat, const QDate& thoi_gian_luutru,
		size_t id_pp_thanhlap, const QString& duongdan_thumuc) :
		mTuLieuId(id_tu_lieu),
		mTyLeId(id_ty_le),
		mPhienHieuManh(phien_hieu),
		mTenManh(ten_manh),
		mKhoangCaoDeu(khoang_caodeu),
		mHeQuyChieuId(id_he_toado),
		mMuiChieu(mui_chieu),
		mThoiGianTl(QDate::fromString(QString("01-01-%1").arg(nam_sanxuat), "dd-MM-yyyy")),
		mThoiGianXb(thoi_gian_luutru),
		mPhuongPhapTlId(id_pp_thanhlap),
		mDuongDanThuMuc(duongdan_thumuc)
	{

	}

#pragma db id auto column("TULIEUBANDOID")
	size_t mTuLieuBanDoId = 0;

#pragma db column("TULIEUID")
	size_t mTuLieuId = 0;

#pragma db column("LOAIBANDOID")
	odb::nullable<int> mLoaiBanDoId;

#pragma db column("TINHID")
	odb::nullable<int> mTinhId;

#pragma db type("NVARCHAR2(50)") column("PHIENHIEUMANH")
	QString mPhienHieuManh;

#pragma db type("NVARCHAR2(100)") column("KHUDO")
	QString mKhuDo;

#pragma db type("NVARCHAR2(50)") column("TENMANH")
	QString mTenManh;

#pragma db column("TYLEID")
	size_t mTyLeId = 0;

#pragma db column("HEQUYCHIEUID")
	size_t mHeQuyChieuId = 0;

#pragma db type("NVARCHAR2(50)") column("HEDOCAO")
	QString mHeDoCao;

#pragma db type("NVARCHAR2(50)") column("LUOICHIEU")
	QString mLuoiChieu;

#pragma db type("NVARCHAR2(50)") column("MUICHIEU")
	QString mMuiChieu;

#pragma db type("NVARCHAR2(50)") column("KINHTUYENTRUC")
	QString mKinhTuyenTruc;

#pragma db type("NVARCHAR2(1600)") column("TAILIEUGOC")
	QString mTaiLieuGoc;

#pragma db type("NVARCHAR2(900)") column("TAILIEUPHU")
	QString mTaiLieuPhu;

#pragma db type("NVARCHAR2(100)") column("KHOANGCAODEU")
	QString mKhoangCaoDeu;

#pragma db type("NVARCHAR2(100)") column("KHOANGCAODEUDS")
	QString mKhoangCaoDeuDs;

#pragma db column("PHUONGPHAPTLID")
	size_t mPhuongPhapTlId = 0;

#pragma db column("COQUANTLID")
	size_t mCoQuanTlId = 1020; //Cục bản đồ

#pragma db column("THOIGIANTL")
	QDate mThoiGianTl;

#pragma db column("THOIGIANXB")
	QDate mThoiGianXb;

#pragma db column("COQUANLUUGIUID")
	size_t mCoQuanLuuGiuId = 1020;

#pragma db column("NGUONVONID")
	odb::nullable<int> mNguonVonId;

#pragma db column("DONGIA")
	double mDonGia = 0;

#pragma db column("TOADOGOCKHUNGX1")
	double mToaDoGocKhungX1 = 0;

#pragma db column("TOADOGOCKHUNGY1")
	double mToaDoGocKhungY1 = 0;

#pragma db column("TOADOGOCKHUNGX2")
	double mToaDoGocKhungX2 = 0;

#pragma db column("TOADOGOCKHUNGY2")
	double mToaDoGocKhungY2 = 0;

#pragma db column("TOADOGOCKHUNGX3")
	double mToaDoGocKhungX3 = 0;

#pragma db column("TOADOGOCKHUNGY3")
	double mToaDoGocKhungY3 = 0;

#pragma db column("TOADOGOCKHUNGX4")
	double mToaDoGocKhungX4 = 0;

#pragma db column("TOADOGOCKHUNGY4")
	double mToaDoGocKhungY4 = 0;

#pragma db type("NVARCHAR2(100)") column("DUONGDANTHUMUC")
	QString mDuongDanThuMuc;

#pragma db column("NGUOISUAID")
	size_t mNguoiSuaId = 1060; //auto-boot

#pragma db column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db column("TRANGTHAI")
	bool mTrangThai = true;

#pragma db column("HUYENID")
	size_t mHuyenId = 0;

#pragma db column("DINHDANGID")
	size_t mDinhDangId = 0;
};

#endif