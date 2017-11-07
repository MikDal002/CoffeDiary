#include "GravitionMethod.h"

GravitationMethod::GravitationMethod()
{

}

QString GravitationMethod::GetName()
{
    return "Grawitacyjna";
}

QList<ICoffeeParam *> GravitationMethod::GetParams()
{
    QList<ICoffeeParam *> retVal;
    retVal.append(&_deviceName);
    retVal.append(&_waterTemp);
    retVal.append(&_coffeWeight);
    retVal.append(&_cleaned);
    retVal.append(&_mixed);
    retVal.append(&_waterAmount);
    retVal.append(&_preinfusionWaterAmount);
    retVal.append(&_preinfusionTime);
    retVal.append(&_totalTime);
    retVal.append(&_desc);

    return retVal;
}

//QString GravitationMethod::GetMailBody()
//{

//}
