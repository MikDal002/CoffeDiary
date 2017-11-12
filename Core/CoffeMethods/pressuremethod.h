#ifndef PRESSUREMETHOD_H
#define PRESSUREMETHOD_H
#include "../ICoffeeMethod.h"
#include "../CoffeeParams/AllCoffeParams.h"

class PressureMethod : public ICoffeeMethod
{
public:
    PressureMethod();
    QString GetName() override;
    QList<ICoffeeParam *> GetParams() override;
	QList<ICoffeeParam *> GetParamsForRecording() override;

private:
    DescParam       _deviceName = DescParam("Nazwa urządzenia");
    TemperatureParam _waterTemp = TemperatureParam("Temperatura wody");
    WeightParam     _coffeWeight = WeightParam("Waga przemiału");
    BooleanParam    _cleaned = BooleanParam("Przemiał przesiany");
    WeightParam     _waterAmount = WeightParam("Całkowita ilosć wody użyta do parzenia");
    TimeParam       _totalTime = TimeParam("Całkowity czas parzenia");
    DescParam       _desc = DescParam("Opis uzyskanej kawy");
};

#endif // PRESSUREMETHOD_H
