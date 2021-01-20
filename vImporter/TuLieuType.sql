/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TULIEUTYPE" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TULIEUTYPE_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
END;
/

CREATE TABLE "TULIEUTYPE" (
  "TULIEUTYPEID" NUMBER(20) NOT NULL PRIMARY KEY,
  "MA" NVARCHAR2(50) NULL,
  "MOTA" NVARCHAR2(50) NULL,
  "NHOMTULIEU" NUMBER(20) NOT NULL,
  "NGUOISUAID" NUMBER(20) NOT NULL,
  "NGAYCHINHSUA" DATE NULL,
  "TRANGTHAI" NUMBER(1) NOT NULL);

CREATE SEQUENCE "TULIEUTYPE_seq"
  START WITH 1 INCREMENT BY 1;

EXIT;
