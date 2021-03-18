#ifndef MAPINFO_H
#define MAPINFO_H

#include <QString>
#include <QStringList>
#include <QMap>

class MapInfo
{
public:
	static void read();
	static MapInfo get25k(const QString& code);
	static MapInfo get50k(const QString& code);
	static MapInfo get100k(const QString& code);
	static MapInfo get250k(const QString& code);
	static MapInfo get500k(const QString& code);
	static MapInfo get1M(const QString& code);
	static MapInfo get(const QString& code, const QString& scale);

	QString mMaSoUtm;
	QString mTenManh;
	QString mKhoangCaoDeu;
	QString mHeToaDo;
	QString mMuiChieu;
	QString mNamSanXuat;
	QString mPhuongPhapThanhLap;
	QString mMaSoVn2000;
	
private:
	static void read(const QString& file, QMap<QString, MapInfo>& out);
	static QMap<QString, MapInfo> m25kInfo;
	static QMap<QString, MapInfo> m50kInfo;
	static QMap<QString, MapInfo> m100kInfo;
	static QMap<QString, MapInfo> m250kInfo;
	static QMap<QString, MapInfo> m500kInfo;
	static QMap<QString, MapInfo> m1mInfo;
	static MapInfo get(const QString& code, const QMap<QString, MapInfo>& map);
};

#endif