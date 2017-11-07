#include "PressureMethod.h"

PressureMethod::PressureMethod()
{

}
QString PressureMethod::GetName()
{
    return "Ciśnieniowa";
}

QList<ICoffeeParam *> PressureMethod::GetParams()
{
    QList<ICoffeeParam *> retVal;
    retVal.append(&_deviceName);
    retVal.append(&_waterTemp);
    retVal.append(&_coffeWeight);
    retVal.append(&_cleaned);
    retVal.append(&_waterAmount);
    retVal.append(&_totalTime);
    retVal.append(&_desc);

    return retVal;
}

//QString PressureMethod::GetMailBody()
//{
//    QString retVal = "Parzenie metodą ciśnieniową: \r\n";
//    foreach (auto foo, GetParams())
//    {
//        retVal += foo->GetParamName() + ": " + foo->ToString() + "\r\n";
//    }

//    return retVal;
//}
