#include "CoffeDiary.h"

#include <Core/CoffeMethods/GravitionMethod.h>
#include <Core/CoffeMethods/PressureMethod.h>


CoffeDiary::CoffeDiary()
{
    _coffeeMethods.append(new GravitationMethod());
    _coffeeMethods.append(new PressureMethod());
}

CoffeDiary::~CoffeDiary()
{
    foreach (ICoffeeMethod *foo, _coffeeMethods)
    {
        free(foo);
    }
}

QList<ICoffeeMethod *> CoffeDiary::GetAvailableCoffeMethods()
{
 return _coffeeMethods;
}
