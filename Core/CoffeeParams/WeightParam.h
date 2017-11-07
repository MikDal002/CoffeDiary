#ifndef WEIGHTPARAM_H
#define WEIGHTPARAM_H
#include "../ICoffeeParam.h"

class WeightParam : public ICoffeeParam
{
public:
    WeightParam(QString name, QString unit = "g");
    ParamType GetParamType() override;
};

#endif // WEIGHTPARAM_H
