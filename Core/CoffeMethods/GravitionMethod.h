#ifndef GRAVITIONMETHOD_H
#define GRAVITIONMETHOD_H
#include "../ICoffeeMethod.h"
#include "../CoffeeParams/AllCoffeParams.h"

class GravitationMethod : public ICoffeeMethod
{
public:
    GravitationMethod();
    QString GetName() override;
    QList<ICoffeeParam *> GetParams() override;
	QList<ICoffeeParam *> GetParamsForRecording() override;

private:
    DescParam       _deviceName = DescParam("Nazwa urządzenia"); //
    TemperatureParam _waterTemp = TemperatureParam("Temperatura wody"); //
    WeightParam     _coffeWeight = WeightParam("Waga przemiału"); //
    BooleanParam    _cleaned = BooleanParam("Przemiał przesiany"); //
    BooleanParam    _mixed = BooleanParam("Przemiał zamieszany w trakcie preinfuzji"); //
    WeightParam     _waterAmount = WeightParam("Całkowita ilosć wody użyta do parzenia"); //
    WeightParam     _preinfusionWaterAmount = WeightParam("Ilość wody użyta do preinfuzji"); //
    TimeParam       _preinfusionTime = TimeParam("Czas trwania preinfuzji"); //
    TimeParam       _totalTime = TimeParam("Całkowity czas parzenia"); //
    DescParam       _desc = DescParam("Opis uzyskanej kawy"); //
};

#endif // GRAVITIONMETHOD_H
