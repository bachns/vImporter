// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef TU_LIEU_ODB_HXX
#define TU_LIEU_ODB_HXX

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

#include "TuLieu.hxx"

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
  // TuLieu
  //
  template <>
  struct class_traits< ::TuLieu >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::TuLieu >
  {
    public:
    typedef ::TuLieu object_type;
    typedef ::QSharedPointer< ::TuLieu > pointer_type;
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
  // TuLieu
  //
  template <typename A>
  struct query_columns< ::TuLieu, id_oracle, A >
  {
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

    // mTuLieuTypeId
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mTuLieuTypeId_type_;

    static const mTuLieuTypeId_type_ mTuLieuTypeId;

    // mMaTuLieu
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mMaTuLieu_type_;

    static const mMaTuLieu_type_ mMaTuLieu;

    // mTenTuLieu
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::QString,
        oracle::id_nstring >::query_type,
      oracle::id_nstring >
    mTenTuLieu_type_;

    static const mTenTuLieu_type_ mTenTuLieu;

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

    // mNguoiSuaID
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::size_t,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    mNguoiSuaID_type_;

    static const mNguoiSuaID_type_ mNguoiSuaID;

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
  };

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mTuLieuId_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mTuLieuId (A::table_name, "\"TULIEUID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mTuLieuTypeId_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mTuLieuTypeId (A::table_name, "\"TULIEUTYPEID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mMaTuLieu_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mMaTuLieu (A::table_name, "\"MATULIEU\"", 0, 200);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mTenTuLieu_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mTenTuLieu (A::table_name, "\"TENTULIEU\"", 0, 600);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mDonGia_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mDonGia (A::table_name, "\"DONGIA\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mNguoiSuaID_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mNguoiSuaID (A::table_name, "\"NGUOISUAID\"", 0, 20);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mNgayChinhSua_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mNgayChinhSua (A::table_name, "\"NGAYCHINHSUA\"", 0);

  template <typename A>
  const typename query_columns< ::TuLieu, id_oracle, A >::mTrangThai_type_
  query_columns< ::TuLieu, id_oracle, A >::
  mTrangThai (A::table_name, "\"TRANGTHAI\"", 0, 1);

  template <typename A>
  struct pointer_query_columns< ::TuLieu, id_oracle, A >:
    query_columns< ::TuLieu, id_oracle, A >
  {
  };

  template <>
  class access::object_traits_impl< ::TuLieu, id_oracle >:
    public access::object_traits< ::TuLieu >
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
      // mTuLieuId
      //
      char mTuLieuId_value[12];
      ub2 mTuLieuId_size;
      sb2 mTuLieuId_indicator;

      // mTuLieuTypeId
      //
      char mTuLieuTypeId_value[12];
      ub2 mTuLieuTypeId_size;
      sb2 mTuLieuTypeId_indicator;

      // mMaTuLieu
      //
      char mMaTuLieu_value[200];
      ub2 mMaTuLieu_size;
      sb2 mMaTuLieu_indicator;

      // mTenTuLieu
      //
      char mTenTuLieu_value[600];
      ub2 mTenTuLieu_size;
      sb2 mTenTuLieu_indicator;

      // mDonGia
      //
      double mDonGia_value;
      sb2 mDonGia_indicator;

      // mNguoiSuaID
      //
      char mNguoiSuaID_value[12];
      ub2 mNguoiSuaID_size;
      sb2 mNguoiSuaID_indicator;

      // mNgayChinhSua
      //
      char mNgayChinhSua_value[7];
      sb2 mNgayChinhSua_indicator;

      // mTrangThai
      //
      unsigned int mTrangThai_value;
      sb2 mTrangThai_indicator;

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

    static const std::size_t column_count = 8UL;
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
  class access::object_traits_impl< ::TuLieu, id_common >:
    public access::object_traits_impl< ::TuLieu, id_oracle >
  {
  };

  // TuLieu
  //
}

#include "TuLieu-odb.ixx"

#include <odb/post.hxx>

#endif // TU_LIEU_ODB_HXX
