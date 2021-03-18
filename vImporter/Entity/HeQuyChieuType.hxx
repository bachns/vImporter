#ifndef HEQUYCHIEUTYPE_HXX
#define HEQUYCHIEUTYPE_HXX

#include <QString>
#include <QDate>

#pragma db object table("HEQUYCHIEUTYPE")
class HeQuyChieuType
{
public:

#pragma db member id auto column("HEQUYCHIEUTYPEID")
	size_t mHeQuyChieuTypeId = 0;

#pragma db member type("NVARCHAR2(50)") column("MA")
	QString mMa;
	
#pragma db member type("NVARCHAR2(50)") column("MOTA")
	QString mMoTa;
	
#pragma db member column("NGUOISUAID")
	size_t mNguoiSuaId = 1060;

#pragma db member column("NGAYCHINHSUA")
	QDate mNgayChinhSua = QDate::currentDate();

#pragma db member column("TRANGTHAI")
	bool mTrangThai = true;
};

#endif
