#include "WeightParam.h"

WeightParam::WeightParam(QString name, QString unit) : ICoffeeParam (name, unit)
{

}

ParamType WeightParam::GetParamType()
{
    return ParamType::WEIGHT;
}
