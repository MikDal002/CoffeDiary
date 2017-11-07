#ifndef TEMPERATUREPARAM_H
#define TEMPERATUREPARAM_H
#include "../ICoffeeParam.h"

class TemperatureParam : public ICoffeeParam
{
public:
    ParamType GetParamType() override;
    TemperatureParam(QString name, QString unit = "°C");
};

#endif // TEMPERATUREPARAM_H
