#include "TimeParam.h"
#include <QTime>
ParamType TimeParam::GetParamType()
{
    return ParamType::TIME;
}

TimeParam::TimeParam(QString name, QString unit) : ICoffeeParam (name, unit)
{

}

QString TimeParam::ToString()
{
    return _value.toTime().toString("mm:ss") + " " + _unit;
}
