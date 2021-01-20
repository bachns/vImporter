#ifndef TULIEUBANDO_H
#define TULIEUBANDO_H

#include <QString>
#include <QDate>

#pragma db object table("TULIEUBANDO")
class TuLieuBanDo
{
public:
#pragma db id column("TULIEUBANDOID")
	int mTuLieuBanDoId;

#pragma db column("TULIEUID")
	int mTuLieuId;

#pragma db column("LOAIBANDOID")
	int mLoaiBanDoId;

#pragma db column("TINHID")
	int mTinhId;

#pragma db column("PHIENHIEUMANH")
	QString mPhienHieuManh;

#pragma db column("KHUDO")
	QString mKhuDo;

#pragma db column("TENMANH")
	QString mTenManh;

#pragma db column("TYLEID")
	int mTyLeId;

#pragma db column("HEQUYCHIEUID")
	int mHeQuyChieuId;

#pragma db column("HEDOCAO")
	QString mHeDoCao;

#pragma db column("LUOICHIEU")
	QString mLuoiChieu;

#pragma db column("MUICHIEU")
	QString mMuiChieu;

#pragma db column("KINHTUYENTRUC")
	QString mKinhTuyenTruc;

#pragma db column("TAILIEUGOC")
	QString mTaiLieuGoc;

#pragma db column("TAILIEUPHU")
	QString mTaiLieuPhu;

#pragma db column("KHOANGCAODEU")
	QString mKhoangCaoDeu;

#pragma db column("KHOANGCAODEUDS")
	QString mKhoangCaoDeuDs;

#pragma db column("PHUONGPHAPTLID")
	int mPhuongPhapTlId;

#pragma db column("COQUANTLID")
	int mCoQuanTlId;

#pragma db column("THOIGIANTL")
	QDate mThoiGianTl;

#pragma db column("THOIGIANXB")
	QDate mThoiGianXb;

#pragma db column("COQUANLUUGIUID")
	int mCoQuanLuuGiuId;

#pragma db column("NGUONVONID")
	int mNguonVonId;

#pragma db column("DONGIA")
	double mDonGia;

#pragma db column("TOADOGOCKHUNGX1")
	double mToaDoGocKhungX1;

#pragma db column("TOADOGOCKHUNGY1")
	double mToaDoGocKhungY1;

#pragma db column("TOADOGOCKHUNGX2")
	double mToaDoGocKhungX2;

#pragma db column("TOADOGOCKHUNGY2")
	double mToaDoGocKhungY2;

#pragma db column("TOADOGOCKHUNGX3")
	double mToaDoGocKhungX3;

#pragma db column("TOADOGOCKHUNGY3")
	double mToaDoGocKhungY3;

#pragma db column("TOADOGOCKHUNGX4")
	double mToaDoGocKhungX4;

#pragma db column("TOADOGOCKHUNGY4")
	double mToaDoGocKhungY4;

#pragma db column("DUONGDANTHUMUC")
	QString mDuongDanThuMuc;

#pragma db column("NGUOISUAID")
	int mNguoiSuaId;

#pragma db column("NGAYCHINHSUA")
	QDate mNgayChinhSua;

#pragma db column("TRANGTHAI")
	bool mTrangThai;

#pragma db column("HUYENID")
	int mHuyenId;

#pragma db column("DINHDANGID")
	int mDinhDangId;
};

#endif