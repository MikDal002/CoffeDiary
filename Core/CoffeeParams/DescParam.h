#ifndef DESCPARAM_H
#define DESCPARAM_H
#include "../ICoffeeParam.h"

class DescParam : public ICoffeeParam
{
public:
    ParamType GetParamType() override;
    DescParam(QString name, QString unit = "N/A");
    QString ToString() override;
};

#endif // DESCPARAM_H
