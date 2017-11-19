#include <qlist.h>
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

QList<ICoffeeParam*> PressureMethod::GetParamsForRecording()
{
	QList<ICoffeeParam*> retVal =
	{
		&_deviceName,
		&_coffeWeight,
		&_cleaned,
		&_waterTemp,
		&_totalTime,
		&_waterAmount,
		&_desc
	};
	return  retVal;
}