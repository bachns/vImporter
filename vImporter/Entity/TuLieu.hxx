#ifndef TULIEU_HXX
#define TULIEU_HXX

#include <QString>
#include <QDate>

#pragma db object table ("TULIEU")
class TuLieu
{
public:
	TuLieu() {}
	TuLieu(size_t id_tulieutype, const QString& ma_tu_lieu, const QString& ten_tu_lieu) :
		mTuLieuTypeId(id_tulieutype), mMaTuLieu(ma_tu_lieu), mTenTuLieu(ten_tu_lieu)
	{
	}

#pragma db member id auto column("TULIEUID")
	size_t mTuLieuId = 0;

#pragma db member column("TULIEUTYPEID")
	size_t mTuLieuTypeId = 0;

#pragma db member type("NVARCHAR2(50)") column("MATULIEU")
	QString mMaTuLieu;

#pragma db member type("NVARCHAR2(150)") column("TENTULIEU")
	QString mTenTuLieu;

#pragma db member column("DONGIA")
	double mDonGia = 0;

#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaID = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;
};

#endif