#include <QDebug>
#include <QDateTime>
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
    }


	
	Update();

    // zapamiętaj, że wartość jeszcze nie została zmieniona:
    _valueChanged = false;
	_value->OnValueChanged = std::bind(&CoffeeParamSelector::onSourceValueChanged, this);

		
}

bool CoffeeParamSelector::ValueWasSet()
{
    return _valueChanged;
}

CoffeeParamSelector::~CoffeeParamSelector()
{
    delete ui;
}

void CoffeeParamSelector::onSourceValueChanged(CoffeeParamSelector * selector)
{
	qDebug() << "Aktualizuje" << endl;
	selector->Update();
}
void CoffeeParamSelector::Update()
{
	// Znajduje się to tutaj ze względu na to, że zdarza się wyścig wątków i wywoływana jest wartośc nullptr
	if (_value == nullptr) return; 
	if (this == nullptr) return;

	switch (_value->GetParamType())
	{
	case ParamType::BOOLEAN:
		ui->hsBoolean->setValue(_value->GetValue().toInt());
		_activeWidget = ui->hzBoolean;
		break;
	case ParamType::DESCRITPION:
		ui->leDesc->setText(_value->GetValue().toString());
		_activeWidget = ui->leDesc;
		break;
	case ParamType::SHORTANSW:
		ui->leDesc->setText(_value->GetValue().toString());
		_activeWidget = ui->leDesc;
		break;
	case ParamType::TEMPERATURE:
		ui->dsbTemperature->setValue(_value->GetValue().toDouble());
		_activeWidget = ui->dsbTemperature;
		break;
	case ParamType::TIME:
		ui->teTime->setTime(_value->GetValue().toTime());
		_activeWidget = ui->hzTime;
		break;
	case ParamType::WEIGHT:
		ui->dsbWeight->setValue(_value->GetValue().toDouble());
		_activeWidget = ui->dsbWeight;
		break;
	default:
		return;
	}
	_activeWidget->setVisible(true);
	_valueChanged = true;
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
