#include "ICoffeeParam.h"
#include <QDebug>

QVariant ICoffeeParam::GetValue()
{
    return _value;
}

void ICoffeeParam::SetValue(QVariant value)
{
    qDebug() << "Zmieniono wartośc Coffepara na: " << value.toString();
    if (value == _value)
        return;

    _value = value;
}

QString ICoffeeParam::GetUnit()
{
    return _unit;
}

void ICoffeeParam::SetUnit(QString unit)
{
    _unit = unit;
}

QString ICoffeeParam::ToString()
{
    return GetValue().toString() + " " + GetUnit();
}

QString ICoffeeParam::GetParamName()
{
    return _name;
}

void ICoffeeParam::SetParamName(QString name)
{
    if (name == _name)
        return;

    _name = name;
}

ICoffeeParam::ICoffeeParam(QString name, QString unit)
{
    _name = name;
    _unit = unit;
}
