#ifndef TYLETYPE_HXX
#define TYLETYPE_HXX

#include <QString>
#include <QDate>

#pragma db object table("TYLETYPE")
class TyLeType
{
public:

#pragma db member id auto column("TYLETYPEID")
	size_t mTyLeTypeId;

#pragma db member type("NVARCHAR2(50)") column("MA")
	QString mMa;
	
#pragma db member column("LOAITYLE")
	size_t mLoaiTyLe;
		
#pragma db member type("NVARCHAR2(50)") column("MOTA")
	QString mMoTa;
		
#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua;

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;
};

#endif