// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "NhomTuLieu-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/oracle/traits.hxx>
#include <odb/oracle/database.hxx>
#include <odb/oracle/transaction.hxx>
#include <odb/oracle/connection.hxx>
#include <odb/oracle/statement.hxx>
#include <odb/oracle/statement-cache.hxx>
#include <odb/oracle/simple-object-statements.hxx>
#include <odb/oracle/container-statements.hxx>
#include <odb/oracle/exceptions.hxx>
#include <odb/oracle/simple-object-result.hxx>

namespace odb
{
  // NhomTuLieu
  //

  struct access::object_traits_impl< ::NhomTuLieu, id_oracle >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      oracle::connection&,
      image_type&,
      id_image_type&,
      oracle::binding&,
      oracle::binding&)
    {
    }
  };

  access::object_traits_impl< ::NhomTuLieu, id_oracle >::id_type
  access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  id (const id_image_type& i)
  {
    oracle::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      oracle::value_traits<
          ::size_t,
          oracle::id_big_int >::set_value (
        id,
        i.id_value,
        i.id_size,
        i.id_indicator == -1);
    }

    return id;
  }

  access::object_traits_impl< ::NhomTuLieu, id_oracle >::id_type
  access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  id (const image_type& i)
  {
    oracle::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      oracle::value_traits<
          ::size_t,
          oracle::id_big_int >::set_value (
        id,
        i.mNhomTuLieuId_value,
        i.mNhomTuLieuId_size,
        i.mNhomTuLieuId_indicator == -1);
    }

    return id;
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  bind (oracle::bind* b,
        image_type& i,
        oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    std::size_t n (0);

    // mNhomTuLieuId
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = oracle::bind::number;
      b[n].buffer = i.mNhomTuLieuId_value;
      b[n].capacity = static_cast<ub4> (sizeof (i.mNhomTuLieuId_value));
      b[n].size = &i.mNhomTuLieuId_size;
      b[n].indicator = &i.mNhomTuLieuId_indicator;
      n++;
    }

    // mTenNhomTuLieu
    //
    b[n].type = oracle::bind::nstring;
    b[n].buffer = i.mTenNhomTuLieu_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.mTenNhomTuLieu_value));
    b[n].size = &i.mTenNhomTuLieu_size;
    b[n].indicator = &i.mTenNhomTuLieu_indicator;
    n++;
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  bind (oracle::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = oracle::bind::number;
    b[n].buffer = i.id_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.id_value));
    b[n].size = &i.id_size;
    b[n].indicator = &i.id_indicator;
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  init (image_type& i,
        const object_type& o,
        oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    // mTenNhomTuLieu
    //
    {
      ::QString const& v =
        o.mTenNhomTuLieu;

      bool is_null (true);
      std::size_t size (0);
      oracle::value_traits<
          ::QString,
          oracle::id_nstring >::set_image (
        i.mTenNhomTuLieu_value,
        sizeof (i.mTenNhomTuLieu_value),
        size,
        is_null,
        v);
      i.mTenNhomTuLieu_indicator = is_null ? -1 : 0;
      i.mTenNhomTuLieu_size = static_cast<ub2> (size);
    }
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // mNhomTuLieuId
    //
    {
      ::size_t& v =
        o.mNhomTuLieuId;

      oracle::value_traits<
          ::size_t,
          oracle::id_big_int >::set_value (
        v,
        i.mNhomTuLieuId_value,
        i.mNhomTuLieuId_size,
        i.mNhomTuLieuId_indicator == -1);
    }

    // mTenNhomTuLieu
    //
    {
      ::QString& v =
        o.mTenNhomTuLieu;

      oracle::value_traits<
          ::QString,
          oracle::id_nstring >::set_value (
        v,
        i.mTenNhomTuLieu_value,
        i.mTenNhomTuLieu_size,
        i.mTenNhomTuLieu_indicator == -1);
    }
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      std::size_t size (0);
      oracle::value_traits<
          ::size_t,
          oracle::id_big_int >::set_image (
        i.id_value,
        size,
        is_null,
        id);
      i.id_indicator = is_null ? -1 : 0;
      i.id_size = static_cast<ub2> (size);
    }
  }

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::persist_statement[] =
  "INSERT INTO \"NHOMTULIEU\" "
  "(\"NHOMTULIEUID\", "
  "\"TENNHOMTULIEU\") "
  "VALUES "
  "(\"NHOMTULIEU_seq\".nextval, :1) "
  "RETURNING \"NHOMTULIEUID\" INTO :2";

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::find_statement[] =
  "SELECT "
  "\"NHOMTULIEU\".\"NHOMTULIEUID\", "
  "\"NHOMTULIEU\".\"TENNHOMTULIEU\" "
  "FROM \"NHOMTULIEU\" "
  "WHERE \"NHOMTULIEU\".\"NHOMTULIEUID\"=:1";

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::update_statement[] =
  "UPDATE \"NHOMTULIEU\" "
  "SET "
  "\"TENNHOMTULIEU\"=:1 "
  "WHERE \"NHOMTULIEUID\"=:2";

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::erase_statement[] =
  "DELETE FROM \"NHOMTULIEU\" "
  "WHERE \"NHOMTULIEUID\"=:1";

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::query_statement[] =
  "SELECT "
  "\"NHOMTULIEU\".\"NHOMTULIEUID\", "
  "\"NHOMTULIEU\".\"TENNHOMTULIEU\" "
  "FROM \"NHOMTULIEU\"";

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::erase_query_statement[] =
  "DELETE FROM \"NHOMTULIEU\"";

  const char access::object_traits_impl< ::NhomTuLieu, id_oracle >::table_name[] =
  "\"NHOMTULIEU\"";

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    init (im, obj, statement_insert);

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.mNhomTuLieuId = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace oracle;
    using oracle::update_statement;

    callback (db, obj, callback_event::pre_update);

    oracle::transaction& tr (oracle::transaction::current ());
    oracle::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.mNhomTuLieuId);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    init (im, obj, statement_update);

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  erase (database& db, const id_type& id)
  {
    using namespace oracle;

    ODB_POTENTIALLY_UNUSED (db);

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::NhomTuLieu, id_oracle >::pointer_type
  access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  find (database& db, const id_type& id)
  {
    using namespace oracle;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      st.stream_result ();
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  reload (database& db, object_type& obj)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.mNhomTuLieuId);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace oracle;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::NhomTuLieu, id_oracle >::object_type >
  access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  query (database&, const query_base_type& q)
  {
    using namespace oracle;
    using odb::details::shared;
    using odb::details::shared_ptr;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) oracle::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::NhomTuLieu, id_oracle >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
