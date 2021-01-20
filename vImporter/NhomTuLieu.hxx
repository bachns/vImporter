#ifndef NHOMTULIEU_HXX
#define NHOMTULIEU_HXX

#include <QString>

class NhomTuLieu
{
public:
	size_t mNhomTuLieuId;
	QString mTenNhomTuLieu;
};

#pragma db object(NhomTuLieu) table("NHOMTULIEU")
#pragma db member(NhomTuLieu::mNhomTuLieuId) id auto column("NHOMTULIEUID")
#pragma db member(NhomTuLieu::mTenNhomTuLieu) type("NVARCHAR2(50)")  column("TENNHOMTULIEU")

#endif