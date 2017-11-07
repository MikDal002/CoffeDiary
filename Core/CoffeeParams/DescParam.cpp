#include "DescParam.h"

ParamType DescParam::GetParamType()
{
 return ParamType::DESCRITPION;
}

DescParam::DescParam(QString name, QString unit) : ICoffeeParam (name, unit)
{

}

QString DescParam::ToString()
{
    return GetValue().toString();
}
