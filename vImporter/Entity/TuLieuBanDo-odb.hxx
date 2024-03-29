// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef TU_LIEU_BAN_DO_ODB_HXX
#define TU_LIEU_BAN_DO_ODB_HXX

// Begin prologue.
//
#include <odb/qt/version.hxx>
#if ODB_QT_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-qt interface versions
#endif
#include <odb/qt/basic/oracle/qstring-traits.hxx>
#include <odb/qt/basic/oracle/qbyte-array-traits.hxx>
#include <odb/qt/basic/oracle/quuid-traits.hxx>
#include <odb/qt/containers/qhash-traits.hxx>
#include <odb/qt/containers/qlist-traits.hxx>
#include <odb/qt/containers/qlinked-list-traits.hxx>
#include <odb/qt/containers/qmap-traits.hxx>
#include <odb/qt/containers/qset-traits.hxx>
#include <odb/qt/containers/qvector-traits.hxx>
#include <odb/qt/date-time/oracle/qdate-traits.hxx>
#include <odb/qt/date-time/oracle/qtime-traits.hxx>
#include <odb/qt/date-time/oracle/qdate-time-traits.hxx>
#include <QtCore/QSharedPointer>
#include <odb/qt/smart-ptr/pointer-traits.hxx>
#include <odb/qt/smart-ptr/wrapper-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "TuLieuBanDo.hxx"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // TuLieuBanDo
  //
  template <>
  struct class_traits< ::TuLieuBanDo >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::TuLieuBanDo >
  {
    public:
    typedef ::TuLieuBanDo object_type;
    typedef ::std::shared_ptr< ::TuLieuBanDo > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::size_t id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/oracle/version.hxx>
#include <odb/oracle/forward.hxx>
#include <odb/oracle/binding.hxx>
#include <odb/oracle/oracle-types.hxx>
#include <odb/oracle/query.hxx>

namespace odb
{
  // TuLieuBanDo
  //
  template <typename A>
  struct query_columns< ::TuLieuBanDo, id_oracle, A >
  {
    // mTuLieuBanDoId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mTuLieuBanDoId_type_;

    static const mTuLieuBanDoId_type_ mTuLieuBanDoId;

    // mTuLieuId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mTuLieuId_type_;

    static const mTuLieuId_type_ mTuLieuId;

    // mLoaiBanDoId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        int,
        oracle::id_int32 >::query_type,
      oracle::id_int32 >
    mLoaiBanDoId_type_;

    static const mLoaiBanDoId_type_ mLoaiBanDoId;

    // mTinhId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        int,
        oracle::id_int32 >::query_type,
      oracle::id_int32 >
    mTinhId_type_;

    static const mTinhId_type_ mTinhId;

    // mPhienHieuManh
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mPhienHieuManh_type_;

    static const mPhienHieuManh_type_ mPhienHieuManh;

    // mKhuDo
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mKhuDo_type_;

    static const mKhuDo_type_ mKhuDo;

    // mTenManh
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mTenManh_type_;

    static const mTenManh_type_ mTenManh;

    // mTyLeId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mTyLeId_type_;

    static const mTyLeId_type_ mTyLeId;

    // mHeQuyChieuId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mHeQuyChieuId_type_;

    static const mHeQuyChieuId_type_ mHeQuyChieuId;

    // mHeDoCao
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mHeDoCao_type_;

    static const mHeDoCao_type_ mHeDoCao;

    // mLuoiChieu
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mLuoiChieu_type_;

    static const mLuoiChieu_type_ mLuoiChieu;

    // mMuiChieu
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mMuiChieu_type_;

    static const mMuiChieu_type_ mMuiChieu;

    // mKinhTuyenTruc
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mKinhTuyenTruc_type_;

    static const mKinhTuyenTruc_type_ mKinhTuyenTruc;

    // mTaiLieuGoc
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mTaiLieuGoc_type_;

    static const mTaiLieuGoc_type_ mTaiLieuGoc;

    // mTaiLieuPhu
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mTaiLieuPhu_type_;

    static const mTaiLieuPhu_type_ mTaiLieuPhu;

    // mKhoangCaoDeu
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mKhoangCaoDeu_type_;

    static const mKhoangCaoDeu_type_ mKhoangCaoDeu;

    // mKhoangCaoDeuDs
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mKhoangCaoDeuDs_type_;

    static const mKhoangCaoDeuDs_type_ mKhoangCaoDeuDs;

    // mPhuongPhapTlId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mPhuongPhapTlId_type_;

    static const mPhuongPhapTlId_type_ mPhuongPhapTlId;

    // mCoQuanTlId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mCoQuanTlId_type_;

    static const mCoQuanTlId_type_ mCoQuanTlId;

    // mThoiGianTl
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QDate,
        oracle::id_date >::query_type,
      oracle::id_date >
    mThoiGianTl_type_;

    static const mThoiGianTl_type_ mThoiGianTl;

    // mThoiGianXb
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QDate,
        oracle::id_date >::query_type,
      oracle::id_date >
    mThoiGianXb_type_;

    static const mThoiGianXb_type_ mThoiGianXb;

    // mCoQuanLuuGiuId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mCoQuanLuuGiuId_type_;

    static const mCoQuanLuuGiuId_type_ mCoQuanLuuGiuId;

    // mNguonVonId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        int,
        oracle::id_int32 >::query_type,
      oracle::id_int32 >
    mNguonVonId_type_;

    static const mNguonVonId_type_ mNguonVonId;

    // mDonGia
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mDonGia_type_;

    static const mDonGia_type_ mDonGia;

    // mToaDoGocKhungX1
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungX1_type_;

    static const mToaDoGocKhungX1_type_ mToaDoGocKhungX1;

    // mToaDoGocKhungY1
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungY1_type_;

    static const mToaDoGocKhungY1_type_ mToaDoGocKhungY1;

    // mToaDoGocKhungX2
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungX2_type_;

    static const mToaDoGocKhungX2_type_ mToaDoGocKhungX2;

    // mToaDoGocKhungY2
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungY2_type_;

    static const mToaDoGocKhungY2_type_ mToaDoGocKhungY2;

    // mToaDoGocKhungX3
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungX3_type_;

    static const mToaDoGocKhungX3_type_ mToaDoGocKhungX3;

    // mToaDoGocKhungY3
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungY3_type_;

    static const mToaDoGocKhungY3_type_ mToaDoGocKhungY3;

    // mToaDoGocKhungX4
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungX4_type_;

    static const mToaDoGocKhungX4_type_ mToaDoGocKhungX4;

    // mToaDoGocKhungY4
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        double,
        oracle::id_double >::query_type,
      oracle::id_double >
    mToaDoGocKhungY4_type_;

    static const mToaDoGocKhungY4_type_ mToaDoGocKhungY4;

    // mDuongDanThuMuc
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mDuongDanThuMuc_type_;

    static const mDuongDanThuMuc_type_ mDuongDanThuMuc;

    // mNguoiSuaId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mNguoiSuaId_type_;

    static const mNguoiSuaId_type_ mNguoiSuaId;

    // mNgayChinhSua
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QDate,
        oracle::id_date >::query_type,
      oracle::id_date >
    mNgayChinhSua_type_;

    static const mNgayChinhSua_type_ mNgayChinhSua;

    // mTrangThai
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        bool,
        oracle::id_int32 >::query_type,
      oracle::id_int32 >
    mTrangThai_type_;

    static const mTrangThai_type_ mTrangThai;

    // mHuyenId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mHuyenId_type_;

    static const mHuyenId_type_ mHuyenId;

    // mDinhDangId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mDinhDangId_type_;

    static const mDinhDangId_type_ mDinhDangId;
  };

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTuLieuBanDoId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTuLieuBanDoId (A::table_name, "\"TULIEUBANDOID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTuLieuId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTuLieuId (A::table_name, "\"TULIEUID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mLoaiBanDoId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mLoaiBanDoId (A::table_name, "\"LOAIBANDOID\"", 0, 10);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTinhId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTinhId (A::table_name, "\"TINHID\"", 0, 10);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mPhienHieuManh_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mPhienHieuManh (A::table_name, "\"PHIENHIEUMANH\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mKhuDo_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mKhuDo (A::table_name, "\"KHUDO\"", 0, 400);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTenManh_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTenManh (A::table_name, "\"TENMANH\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTyLeId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTyLeId (A::table_name, "\"TYLEID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mHeQuyChieuId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mHeQuyChieuId (A::table_name, "\"HEQUYCHIEUID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mHeDoCao_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mHeDoCao (A::table_name, "\"HEDOCAO\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mLuoiChieu_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mLuoiChieu (A::table_name, "\"LUOICHIEU\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mMuiChieu_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mMuiChieu (A::table_name, "\"MUICHIEU\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mKinhTuyenTruc_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mKinhTuyenTruc (A::table_name, "\"KINHTUYENTRUC\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTaiLieuGoc_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTaiLieuGoc (A::table_name, "\"TAILIEUGOC\"", 0, 4000);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTaiLieuPhu_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTaiLieuPhu (A::table_name, "\"TAILIEUPHU\"", 0, 3600);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mKhoangCaoDeu_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mKhoangCaoDeu (A::table_name, "\"KHOANGCAODEU\"", 0, 400);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mKhoangCaoDeuDs_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mKhoangCaoDeuDs (A::table_name, "\"KHOANGCAODEUDS\"", 0, 400);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mPhuongPhapTlId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mPhuongPhapTlId (A::table_name, "\"PHUONGPHAPTLID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mCoQuanTlId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mCoQuanTlId (A::table_name, "\"COQUANTLID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mThoiGianTl_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mThoiGianTl (A::table_name, "\"THOIGIANTL\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mThoiGianXb_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mThoiGianXb (A::table_name, "\"THOIGIANXB\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mCoQuanLuuGiuId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mCoQuanLuuGiuId (A::table_name, "\"COQUANLUUGIUID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mNguonVonId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mNguonVonId (A::table_name, "\"NGUONVONID\"", 0, 10);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mDonGia_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mDonGia (A::table_name, "\"DONGIA\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungX1_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungX1 (A::table_name, "\"TOADOGOCKHUNGX1\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungY1_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungY1 (A::table_name, "\"TOADOGOCKHUNGY1\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungX2_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungX2 (A::table_name, "\"TOADOGOCKHUNGX2\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungY2_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungY2 (A::table_name, "\"TOADOGOCKHUNGY2\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungX3_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungX3 (A::table_name, "\"TOADOGOCKHUNGX3\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungY3_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungY3 (A::table_name, "\"TOADOGOCKHUNGY3\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungX4_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungX4 (A::table_name, "\"TOADOGOCKHUNGX4\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mToaDoGocKhungY4_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mToaDoGocKhungY4 (A::table_name, "\"TOADOGOCKHUNGY4\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mDuongDanThuMuc_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mDuongDanThuMuc (A::table_name, "\"DUONGDANTHUMUC\"", 0, 400);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mNguoiSuaId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mNguoiSuaId (A::table_name, "\"NGUOISUAID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mNgayChinhSua_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mNgayChinhSua (A::table_name, "\"NGAYCHINHSUA\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mTrangThai_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mTrangThai (A::table_name, "\"TRANGTHAI\"", 0, 1);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mHuyenId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mHuyenId (A::table_name, "\"HUYENID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieuBanDo, id_oracle, A >::mDinhDangId_type_
  query_columns< ::TuLieuBanDo, id_oracle, A >::
  mDinhDangId (A::table_name, "\"DINHDANGID\"", 0, 20);

  template <typename A>
  struct pointer_query_columns< ::TuLieuBanDo, id_oracle, A >:
    query_columns< ::TuLieuBanDo, id_oracle, A >
  {
  };

  template <>
  class access::object_traits_impl< ::TuLieuBanDo, id_oracle >:
    public access::object_traits< ::TuLieuBanDo >
  {
    public:
    static const std::size_t batch = 1UL;

    struct id_image_type
    {
      char id_value[12];
      ub2 id_size;
      sb2 id_indicator;

      std::size_t version;
    };

    struct image_type
    {
      // mTuLieuBanDoId
      //
      char mTuLieuBanDoId_value[12];
      ub2 mTuLieuBanDoId_size;
      sb2 mTuLieuBanDoId_indicator;

      // mTuLieuId
      //
      char mTuLieuId_value[12];
      ub2 mTuLieuId_size;
      sb2 mTuLieuId_indicator;

      // mLoaiBanDoId
      //
      int mLoaiBanDoId_value;
      sb2 mLoaiBanDoId_indicator;

      // mTinhId
      //
      int mTinhId_value;
      sb2 mTinhId_indicator;

      // mPhienHieuManh
      //
      char mPhienHieuManh_value[200];
      ub2 mPhienHieuManh_size;
      sb2 mPhienHieuManh_indicator;

      // mKhuDo
      //
      char mKhuDo_value[400];
      ub2 mKhuDo_size;
      sb2 mKhuDo_indicator;

      // mTenManh
      //
      char mTenManh_value[200];
      ub2 mTenManh_size;
      sb2 mTenManh_indicator;

      // mTyLeId
      //
      char mTyLeId_value[12];
      ub2 mTyLeId_size;
      sb2 mTyLeId_indicator;

      // mHeQuyChieuId
      //
      char mHeQuyChieuId_value[12];
      ub2 mHeQuyChieuId_size;
      sb2 mHeQuyChieuId_indicator;

      // mHeDoCao
      //
      char mHeDoCao_value[200];
      ub2 mHeDoCao_size;
      sb2 mHeDoCao_indicator;

      // mLuoiChieu
      //
      char mLuoiChieu_value[200];
      ub2 mLuoiChieu_size;
      sb2 mLuoiChieu_indicator;

      // mMuiChieu
      //
      char mMuiChieu_value[200];
      ub2 mMuiChieu_size;
      sb2 mMuiChieu_indicator;

      // mKinhTuyenTruc
      //
      char mKinhTuyenTruc_value[200];
      ub2 mKinhTuyenTruc_size;
      sb2 mKinhTuyenTruc_indicator;

      // mTaiLieuGoc
      //
      char mTaiLieuGoc_value[4000];
      ub2 mTaiLieuGoc_size;
      sb2 mTaiLieuGoc_indicator;

      // mTaiLieuPhu
      //
      char mTaiLieuPhu_value[3600];
      ub2 mTaiLieuPhu_size;
      sb2 mTaiLieuPhu_indicator;

      // mKhoangCaoDeu
      //
      char mKhoangCaoDeu_value[400];
      ub2 mKhoangCaoDeu_size;
      sb2 mKhoangCaoDeu_indicator;

      // mKhoangCaoDeuDs
      //
      char mKhoangCaoDeuDs_value[400];
      ub2 mKhoangCaoDeuDs_size;
      sb2 mKhoangCaoDeuDs_indicator;

      // mPhuongPhapTlId
      //
      char mPhuongPhapTlId_value[12];
      ub2 mPhuongPhapTlId_size;
      sb2 mPhuongPhapTlId_indicator;

      // mCoQuanTlId
      //
      char mCoQuanTlId_value[12];
      ub2 mCoQuanTlId_size;
      sb2 mCoQuanTlId_indicator;

      // mThoiGianTl
      //
      char mThoiGianTl_value[7];
      sb2 mThoiGianTl_indicator;

      // mThoiGianXb
      //
      char mThoiGianXb_value[7];
      sb2 mThoiGianXb_indicator;

      // mCoQuanLuuGiuId
      //
      char mCoQuanLuuGiuId_value[12];
      ub2 mCoQuanLuuGiuId_size;
      sb2 mCoQuanLuuGiuId_indicator;

      // mNguonVonId
      //
      int mNguonVonId_value;
      sb2 mNguonVonId_indicator;

      // mDonGia
      //
      double mDonGia_value;
      sb2 mDonGia_indicator;

      // mToaDoGocKhungX1
      //
      double mToaDoGocKhungX1_value;
      sb2 mToaDoGocKhungX1_indicator;

      // mToaDoGocKhungY1
      //
      double mToaDoGocKhungY1_value;
      sb2 mToaDoGocKhungY1_indicator;

      // mToaDoGocKhungX2
      //
      double mToaDoGocKhungX2_value;
      sb2 mToaDoGocKhungX2_indicator;

      // mToaDoGocKhungY2
      //
      double mToaDoGocKhungY2_value;
      sb2 mToaDoGocKhungY2_indicator;

      // mToaDoGocKhungX3
      //
      double mToaDoGocKhungX3_value;
      sb2 mToaDoGocKhungX3_indicator;

      // mToaDoGocKhungY3
      //
      double mToaDoGocKhungY3_value;
      sb2 mToaDoGocKhungY3_indicator;

      // mToaDoGocKhungX4
      //
      double mToaDoGocKhungX4_value;
      sb2 mToaDoGocKhungX4_indicator;

      // mToaDoGocKhungY4
      //
      double mToaDoGocKhungY4_value;
      sb2 mToaDoGocKhungY4_indicator;

      // mDuongDanThuMuc
      //
      char mDuongDanThuMuc_value[400];
      ub2 mDuongDanThuMuc_size;
      sb2 mDuongDanThuMuc_indicator;

      // mNguoiSuaId
      //
      char mNguoiSuaId_value[12];
      ub2 mNguoiSuaId_size;
      sb2 mNguoiSuaId_indicator;

      // mNgayChinhSua
      //
      char mNgayChinhSua_value[7];
      sb2 mNgayChinhSua_indicator;

      // mTrangThai
      //
      unsigned int mTrangThai_value;
      sb2 mTrangThai_indicator;

      // mHuyenId
      //
      char mHuyenId_value[12];
      ub2 mHuyenId_size;
      sb2 mHuyenId_indicator;

      // mDinhDangId
      //
      char mDinhDangId_value[12];
      ub2 mDinhDangId_size;
      sb2 mDinhDangId_indicator;

      std::size_t version;

      oracle::change_callback change_callback_;

      oracle::change_callback*
      change_callback ()
      {
        return &change_callback_;
      }
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static void
    bind (oracle::bind*,
          image_type&,
          oracle::statement_kind);

    static void
    bind (oracle::bind*, id_image_type&);

    static void
    init (image_type&,
          const object_type&,
          oracle::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef oracle::object_statements<object_type> statements_type;

    typedef oracle::query_base query_base_type;

    static const std::size_t column_count = 38UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::TuLieuBanDo, id_common >:
    public access::object_traits_impl< ::TuLieuBanDo, id_oracle >
  {
  };

  // TuLieuBanDo
  //
}

#include "TuLieuBanDo-odb.ixx"

#include <odb/post.hxx>

#endif // TU_LIEU_BAN_DO_ODB_HXX
