#ifndef COFFEEPARAMSELECTOR_H
#define COFFEEPARAMSELECTOR_H

#include <QWidget>
#include "../Core/ICoffeeParam.h"
namespace Ui {
class CoffeeParamSelector;
}

class CoffeeParamSelector : public QWidget
{
    Q_OBJECT

public:
    explicit CoffeeParamSelector(QWidget *parent = 0, ICoffeeParam * param = 0);
    ~CoffeeParamSelector();
private:
    ICoffeeParam * _value;
private slots:
    void on_hsBoolean_valueChanged(int value);

    void on_hsBoolean_sliderPressed();

    void on_leDesc_textChanged(const QString &arg1);

    void on_dsbWeight_valueChanged(double arg1);

    void on_dsbTemperature_valueChanged(double arg1);

    void on_teTime_timeChanged(const QTime &time);

private:
    Ui::CoffeeParamSelector *ui;
};

#endif // COFFEEPARAMSELECTOR_H
