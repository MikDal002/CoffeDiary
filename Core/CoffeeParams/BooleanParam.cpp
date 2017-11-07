#include "BooleanParam.h"

ParamType BooleanParam::GetParamType()
{
    return ParamType::BOOLEAN;
}

BooleanParam::BooleanParam(QString name, QString unit) : ICoffeeParam(name, unit)
{

}

QString BooleanParam::ToString()
{
    return _value.toBool() ? "TAK" : "NIE";
}
