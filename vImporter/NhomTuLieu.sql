/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "NHOMTULIEU" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "NHOMTULIEU_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
END;
/

CREATE TABLE "NHOMTULIEU" (
  "NHOMTULIEUID" NUMBER(20) NOT NULL PRIMARY KEY,
  "TENNHOMTULIEU" NVARCHAR2(50) NULL);

CREATE SEQUENCE "NHOMTULIEU_seq"
  START WITH 1 INCREMENT BY 1;

EXIT;
