#ifndef COFFEDIARY_H
#define COFFEDIARY_H

#include <QList>
#include "ICoffeeMethod.h"

class CoffeDiary
{
public:
    CoffeDiary();
    ~CoffeDiary();
    QList<ICoffeeMethod *> GetAvailableCoffeMethods();
private:
    QList<ICoffeeMethod *> _coffeeMethods;
};

#endif // COFFEDIARY_H
