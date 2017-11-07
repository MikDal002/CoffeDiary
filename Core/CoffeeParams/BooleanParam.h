#ifndef BOOLEANPARAM_H
#define BOOLEANPARAM_H
#include "../ICoffeeParam.h"

class BooleanParam : public ICoffeeParam
{
public:
    ParamType GetParamType() override;
    BooleanParam(QString name, QString unit = "N/A");
    QString ToString() override;
};

#endif // BOOLEANPARAM_H
