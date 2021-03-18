#ifndef NHOMTULIEU_HXX
#define NHOMTULIEU_HXX

#include <QString>

#pragma db object table("NHOMTULIEU")
class NhomTuLieu
{
public:
#pragma db id auto column("NHOMTULIEUID")
	size_t mNhomTuLieuId;

#pragma db type("NVARCHAR2(50)") column("TENNHOMTULIEU")
	QString mTenNhomTuLieu;
};





#endif