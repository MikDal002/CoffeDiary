#include "TemperatureParam.h"

ParamType TemperatureParam::GetParamType()
{
    return ParamType::TEMPERATURE;
}


TemperatureParam::TemperatureParam(QString name, QString unit) : ICoffeeParam (name, unit)
{

}
