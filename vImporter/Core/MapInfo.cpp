#include "MapInfo.h"
#include "Vietnamese.h"
#include <xlnt/xlnt.hpp>
#include <spdlog/spdlog.h>

QMap<QString, MapInfo> MapInfo::m25kInfo;
QMap<QString, MapInfo> MapInfo::m50kInfo;
QMap<QString, MapInfo> MapInfo::m100kInfo;
QMap<QString, MapInfo> MapInfo::m250kInfo;
QMap<QString, MapInfo> MapInfo::m500kInfo;
QMap<QString, MapInfo> MapInfo::m1mInfo;

void MapInfo::read()
{
	read("info/25k.xls", m25kInfo);
	read("info/50k.xls", m50kInfo);
	read("info/100k.xls", m100kInfo);
	read("info/250k.xls", m250kInfo);
	read("info/500k.xls", m500kInfo);
	read("info/1M.xls", m1mInfo);
}

MapInfo MapInfo::get25k(const QString& code)
{
	if (m25kInfo.contains(code))
		return m25kInfo[code];

	QString new_code = code;
	new_code.replace(Vietnamese::str(L"Đ"), "D");
	if (m25kInfo.contains(new_code))
		return m25kInfo[new_code];

	QString new_code2 = code;
	new_code2.replace("D", Vietnamese::str(L"Đ"));
	if (m25kInfo.contains(new_code2))
		return m25kInfo[new_code2];

	return {};
}

MapInfo MapInfo::get50k(const QString& code)
{
	return get(code, m50kInfo);
}

MapInfo MapInfo::get100k(const QString& code)
{
	return get(code, m100kInfo);
}

MapInfo MapInfo::get250k(const QString& code)
{
	return get(code, m250kInfo);
}

MapInfo MapInfo::get500k(const QString& code)
{
	return get(code, m500kInfo);
}

MapInfo MapInfo::get1M(const QString& code)
{
	return get(code, m1mInfo);
}

MapInfo MapInfo::get(const QString& code, const QString& scale)
{
	if (scale == "1/25.000")
		return get25k(code);
	
	if (scale == "1/50.000")
		return get50k(code);
	
	if (scale == "1/100.000")
		return get100k(code);

	if (scale == "1/250.000")
		return get250k(code);

	if (scale == "1/500.000")
		return get500k(code);
	
	if (scale == "1/1.000.000")
		return get1M(code);

	return {};
}

void MapInfo::read(const QString& file, QMap<QString, MapInfo>& out)
{
	out.clear();
	try
	{
		xlnt::workbook wb;
		wb.load(file.toStdString());
		auto sheet = wb.active_sheet();
		auto rows = sheet.rows();
		for (int i = 1; i < rows.length(); ++i)
		{
			MapInfo info;
			info.mMaSoUtm = QString::fromStdString(rows[i][0].to_string());
			info.mTenManh = QString::fromStdString(rows[i][1].to_string());
			info.mKhoangCaoDeu = QString::fromStdString(rows[i][2].to_string());
			info.mHeToaDo = QString::fromStdString(rows[i][3].to_string());
			info.mMuiChieu = QString::fromStdString(rows[i][4].to_string());
			info.mNamSanXuat = QString::fromStdString(rows[i][5].to_string());
			info.mPhuongPhapThanhLap = QString::fromStdString(rows[i][6].to_string());
			info.mMaSoVn2000 = QString::fromStdString(rows[i][7].to_string());
			out[info.mMaSoUtm] = info;
		}
		spdlog::get("logger")->info("Read info from {}", file.toStdString());
	}
	catch (const xlnt::exception& ex)
	{
		spdlog::get("logger")->error("Error reading {} {}", file.toStdString(), ex.what());
	}
}

MapInfo MapInfo::get(const QString& code, const QMap<QString, MapInfo>& map)
{
	if (map.contains(code))
		return map[code];

	return {};
}
