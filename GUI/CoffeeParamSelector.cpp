#include <QDebug>
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
        ui->hsBoolean->setValue(true);
        ui->hsBoolean->setValue(false); // potrzeba dwa razy aby dobrze ustawiła się wartość QLabel
        _activeWidget = ui->hzBoolean;
        break;
    case ParamType::DESCRITPION:
        ui->leDesc->setText(param->GetValue().toString());
        _activeWidget = ui->leDesc;
        break;
    case ParamType::SHORTANSW:
        ui->leDesc->setText(param->GetValue().toString());
        _activeWidget = ui->leDesc;
        break;
    case ParamType::TEMPERATURE:
        _activeWidget = ui->dsbTemperature;
        break;
    case ParamType::TIME:
        _activeWidget = ui->hzTime;
        break;
    case ParamType::WEIGHT:
        _activeWidget = ui->dsbWeight;
        break;
    default:
        return;
    }
    _activeWidget->setVisible(true);
    // zapamiętaj, że wartość jeszcze nie została zmieniona:
    _valueChanged = false;
}

bool CoffeeParamSelector::ValueWasSet()
{
    return _valueChanged;
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
    _valueChanged = true;
}

void CoffeeParamSelector::on_hsBoolean_sliderPressed()
{
    ui->hsBoolean->setValue(!ui->hsBoolean->value());
}

void CoffeeParamSelector::on_leDesc_textChanged(const QString &arg1)
{
    _value->SetValue(arg1);
    _valueChanged = true;
}

void CoffeeParamSelector::on_dsbWeight_valueChanged(double arg1)
{
    _value->SetValue(arg1);
    _valueChanged = true;
}

void CoffeeParamSelector::on_dsbTemperature_valueChanged(double arg1)
{
    _value->SetValue(arg1);
    _valueChanged = true;
}

void CoffeeParamSelector::on_teTime_timeChanged(const QTime &time)
{
    _value->SetValue(time);
    _valueChanged = true;
}
