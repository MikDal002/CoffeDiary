#ifndef ICOFFEPARAM_H
#define ICOFFEPARAM_H
#include <QVariant>
enum class ParamType
{
    TIME, //< określa czas
    WEIGHT, //< określa wagę
    TEMPERATURE, //< określa temperaturę
    BOOLEAN, //< Określa tak/nie
    SHORTANSW, //< Krótki opis
    DESCRITPION //< Długi opis
};
class ICoffeeParam
{
public:


    virtual ParamType GetParamType() = 0;
    virtual QString ToString();

    virtual QString GetParamName();
    virtual void SetParamName(QString name);

    virtual QVariant GetValue();
    virtual void SetValue(QVariant value);

    virtual QString GetUnit();
    virtual void SetUnit(QString unit);

protected:
    ICoffeeParam(QString name, QString unit);
    QVariant _value;
    QString _name;
    QString _unit;
    virtual ~ICoffeeParam() {}
};

#endif // ICOFFEPARAM_H
