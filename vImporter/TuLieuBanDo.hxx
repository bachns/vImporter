#ifndef TULIEUBANDO_HXX
#define TULIEUBANDO_HXX

#include <QString>
#include <QDate>

class TuLieuBanDo
{
public:
	int mTuLieuBanDoId;
	int mTuLieuId;
	int mLoaiBanDoId;
	int mTinhId;
	QString mPhienHieuManh;
	QString mKhuDo;
	QString mTenManh;
	int mTyLeId;
	int mHeQuyChieuId;
	QString mHeDoCao;
	QString mLuoiChieu;
	QString mMuiChieu;
	QString mKinhTuyenTruc;
	QString mTaiLieuGoc;
	QString mTaiLieuPhu;
	QString mKhoangCaoDeu;
	QString mKhoangCaoDeuDs;
	int mPhuongPhapTlId;
	int mCoQuanTlId;
	QDate mThoiGianTl;
	QDate mThoiGianXb;
	int mCoQuanLuuGiuId;
	int mNguonVonId;
	double mDonGia;
	double mToaDoGocKhungX1;
	double mToaDoGocKhungY1;
	double mToaDoGocKhungX2;
	double mToaDoGocKhungY2;
	double mToaDoGocKhungX3;
	double mToaDoGocKhungY3;
	double mToaDoGocKhungX4;
	double mToaDoGocKhungY4;
	QString mDuongDanThuMuc;
	int mNguoiSuaId;
	QDate mNgayChinhSua;
	bool mTrangThai;
	int mHuyenId;
	int mDinhDangId;
};

#pragma db object(TuLieuBanDo) table("TULIEUBANDO")
#pragma db member(TuLieuBanDo::mTuLieuBanDoId) id auto column("TULIEUBANDOID")
#pragma db member(TuLieuBanDo::mTuLieuId) column("TULIEUID")
#pragma db member(TuLieuBanDo::mLoaiBanDoId) column("LOAIBANDOID")
#pragma db member(TuLieuBanDo::mTinhId) column("TINHID")
#pragma db member(TuLieuBanDo::mPhienHieuManh) type("NVARCHAR2(50)") column("PHIENHIEUMANH")
#pragma db member(TuLieuBanDo::mKhuDo) type("NVARCHAR2(100)") column("KHUDO")
#pragma db member(TuLieuBanDo::mTenManh) type("NVARCHAR2(50)") column("TENMANH")
#pragma db member(TuLieuBanDo::mTyLeId) column("TYLEID")
#pragma db member(TuLieuBanDo::mHeQuyChieuId) column("HEQUYCHIEUID")
#pragma db member(TuLieuBanDo::mHeDoCao) type("NVARCHAR2(50)") column("HEDOCAO")
#pragma db member(TuLieuBanDo::mLuoiChieu) type("NVARCHAR2(50)") column("LUOICHIEU")
#pragma db member(TuLieuBanDo::mMuiChieu) type("NVARCHAR2(50)") column("MUICHIEU")
#pragma db member(TuLieuBanDo::mKinhTuyenTruc) type("NVARCHAR2(50)") column("KINHTUYENTRUC")
#pragma db member(TuLieuBanDo::mTaiLieuGoc) type("NVARCHAR2(1600)") column("TAILIEUGOC")
#pragma db member(TuLieuBanDo::mTaiLieuPhu) type("NVARCHAR2(900)") column("TAILIEUPHU")
#pragma db member(TuLieuBanDo::mKhoangCaoDeu) type("NVARCHAR2(100)") column("KHOANGCAODEU")
#pragma db member(TuLieuBanDo::mKhoangCaoDeuDs) type("NVARCHAR2(100)") column("KHOANGCAODEUDS")
#pragma db member(TuLieuBanDo::mPhuongPhapTlId) column("PHUONGPHAPTLID")
#pragma db member(TuLieuBanDo::mCoQuanTlId) column("COQUANTLID")
#pragma db member(TuLieuBanDo::mThoiGianTl) column("THOIGIANTL")
#pragma db member(TuLieuBanDo::mThoiGianXb) column("THOIGIANXB")
#pragma db member(TuLieuBanDo::mCoQuanLuuGiuId) column("COQUANLUUGIUID")
#pragma db member(TuLieuBanDo::mNguonVonId) column("NGUONVONID")
#pragma db member(TuLieuBanDo::mDonGia) column("DONGIA")
#pragma db member(TuLieuBanDo::mToaDoGocKhungX1) column("TOADOGOCKHUNGX1")
#pragma db member(TuLieuBanDo::mToaDoGocKhungY1) column("TOADOGOCKHUNGY1")
#pragma db member(TuLieuBanDo::mToaDoGocKhungX2) column("TOADOGOCKHUNGX2")
#pragma db member(TuLieuBanDo::mToaDoGocKhungY2) column("TOADOGOCKHUNGY2")
#pragma db member(TuLieuBanDo::mToaDoGocKhungX3) column("TOADOGOCKHUNGX3")
#pragma db member(TuLieuBanDo::mToaDoGocKhungY3) column("TOADOGOCKHUNGY3")
#pragma db member(TuLieuBanDo::mToaDoGocKhungX4) column("TOADOGOCKHUNGX4")
#pragma db member(TuLieuBanDo::mToaDoGocKhungY4) column("TOADOGOCKHUNGY4")
#pragma db member(TuLieuBanDo::mDuongDanThuMuc) type("NVARCHAR2(100)") column("DUONGDANTHUMUC")
#pragma db member(TuLieuBanDo::mNguoiSuaId) column("NGUOISUAID")
#pragma db member(TuLieuBanDo::mNgayChinhSua) column("NGAYCHINHSUA")
#pragma db member(TuLieuBanDo::mTrangThai) column("TRANGTHAI")
#pragma db member(TuLieuBanDo::mHuyenId) column("HUYENID")
#pragma db member(TuLieuBanDo::mDinhDangId) column("DINHDANGID")

#endif