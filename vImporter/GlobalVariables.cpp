#include "GlobalVariables.h"

namespace regexp
{
	const QString map25k = "\\d{4}(\\s+|_+|-+)*(i{1,3}|I{1,3}|1|2|3|4|iv|IV)(\\s+|_+|-+)*(DB|\\x0110B|TB|DN|\\x0110N|TN)(\\s+|_+|-+)*";
	const QString map50k = "\\d{4}(\\s+|_+|-+)*(i{1,3}|I{1,3}|1|2|3|4|iv|IV)(\\s+|_+|-+)*";
	const QString map100k = "\\d{4}(\\s+|_+|-+)*";
	const QString map250k = "[A-Za-z]{2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*";
	const QString map500k = "[A-Za-z]{2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*(a|A|b|B|c|C|d|D)(\\s+|_+|-+)*";
	const QString map1m = "[A-Za-z]{2}(\\s+|_+|-+)*\\d{1,2}(\\s+|_+|-+)*";
}

QMap<MapScale, MapScaleProperty> GlobalVariables::mMapScaleProperties =
{
	{MapScale::map25k, MapScaleProperty("25.000", regexp::map25k)},
	{MapScale::map50k, MapScaleProperty("50.000", regexp::map50k)},
	{MapScale::map100k, MapScaleProperty("100.000", regexp::map100k)},
	{MapScale::map250k, MapScaleProperty("250.000", regexp::map250k)},
	{MapScale::map500k, MapScaleProperty("500.000", regexp::map500k)},
	{MapScale::map1m, MapScaleProperty("1.000.000", regexp::map1m)}
};

