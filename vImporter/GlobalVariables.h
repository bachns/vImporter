#ifndef GLOBALVARIABLES_GLOBAL_H
#define GLOBALVARIABLES_GLOBAL_H

#include <QMetaType>
#include <QString>
#include <QMap>

enum class MapScale
{
	map25k, map50k, map100k, map250k, map500k, map1m
};

Q_DECLARE_METATYPE(MapScale)

class MapScaleProperty
{
public:
	MapScaleProperty() = default;
	MapScaleProperty(const QString& name, const QString& regExp)
		: mName(name), mRegExp(regExp) {}

	QString mName;
	QString mRegExp;
};

class GlobalVariables
{
public:
	GlobalVariables() = default;
	static QMap<MapScale, MapScaleProperty> mMapScaleProperties;
};

#endif