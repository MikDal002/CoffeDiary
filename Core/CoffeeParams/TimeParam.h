#ifndef TIMEPARAM_H
#define TIMEPARAM_H
#include "../ICoffeeParam.h"

class TimeParam : public ICoffeeParam
{
public:
    ParamType GetParamType() override;
    TimeParam(QString name, QString unit = "mm:ss");
    QString ToString() override;
};

#endif // TIMEPARAM_H
