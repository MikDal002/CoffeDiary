#include "CoffeeParamSelector.h"
#include "ui_CoffeeParamSelector.h"

CoffeeParamSelector::CoffeeParamSelector(QWidget *parent, ICoffeeParam * param) :
    QWidget(parent),
    ui(new Ui::CoffeeParamSelector)
{
    ui->setupUi(this);

    _value = param;
    ui->lbTitle->setText(param->GetParamName());
    for (int i = 0; i < ui->vlParams->count(); ++i)
    {
        // @todo Tutaj możliwe jest zwrócenie przez widget() NULL.
        ui->vlParams->itemAt(i)->widget()->setVisible(false);
        //QWidget * widget = (QWidget *)foo;

        //widget->setVisible(false);
    }

    switch (param->GetParamType())
    {
    case ParamType::BOOLEAN:
        ui->hzBoolean->setVisible(true);
        ui->hsBoolean->setValue(false);
        break;
    case ParamType::DESCRITPION:
        ui->leDesc->setText(param->GetValue().toString());
        ui->leDesc->setVisible(true);
        break;
    case ParamType::SHORTANSW:
        ui->leDesc->setText(param->GetValue().toString());
        ui->leDesc->setVisible(true);
        break;
    case ParamType::TEMPERATURE:
        ui->dsbTemperature->setVisible(true);
        break;
    case ParamType::TIME:
        ui->hzTime->setVisible(true);
        break;
    case ParamType::WEIGHT:
        ui->dsbWeight->setVisible(true);
        break;
    default:
        break;
    }
}

CoffeeParamSelector::~CoffeeParamSelector()
{
    delete ui;
}

void CoffeeParamSelector::on_hsBoolean_valueChanged(int value)
{
    if (value)
        ui->lbSlider->setText("TAK");
    else
        ui->lbSlider->setText("NIE");

    _value->SetValue(value);
}

void CoffeeParamSelector::on_hsBoolean_sliderPressed()
{
    ui->hsBoolean->setValue(!ui->hsBoolean->value());
}

void CoffeeParamSelector::on_leDesc_textChanged(const QString &arg1)
{
    _value->SetValue(arg1);
}

void CoffeeParamSelector::on_dsbWeight_valueChanged(double arg1)
{
    _value->SetValue(arg1);
}

void CoffeeParamSelector::on_dsbTemperature_valueChanged(double arg1)
{
    _value->SetValue(arg1);
}

void CoffeeParamSelector::on_teTime_timeChanged(const QTime &time)
{
    _value->SetValue(time);
}
