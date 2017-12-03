#include "RegisterCoffeeWidget.h"
#include "ui_RegisterCoffeeWidget.h"
#include <qcolor.h>
#include "../Core/ICoffeeParam.h"
#include <qobject.h>
#include "CoffeeParamSelector.h"
RegisterCoffeeWidget::RegisterCoffeeWidget(QWidget *parent, ICoffeeMethod * coffee)
	: QWidget(parent), ui(new Ui::RegisterCoffeeWidget)
{
	ui->setupUi(this);
	_method = coffee;

	_paramsTodo = coffee->GetParamsForRecording().length();
	QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
	setUpGUI();
}

RegisterCoffeeWidget::~RegisterCoffeeWidget()
{

}
void RegisterCoffeeWidget::timerTimeout()
{
	if (_currentTimeParam == nullptr) return;
	
	_currentTimeParam->SetValue(_startTime.secsTo(QDateTime::currentDateTime()));

}
void RegisterCoffeeWidget::invokeOnRegisteringEnd()
{
	if (OnRegisteringEnd)
	{
		OnRegisteringEnd();
	}
}
void RegisterCoffeeWidget::setUpGUI()
{
	QPalette pal = palette();

	// set black background
	pal.setColor(QPalette::Background, QColor("#5555ff"));
	this->setAutoFillBackground(true);
	this->setPalette(pal);
	this->show();

	ui->progressBar->setMaximum(_paramsTodo -1);
	ui->pbNext->setText("Rozpocznij");
}

bool RegisterCoffeeWidget::renderParam(uint32_t no)
{
	// wyczy�� GUI.
	while (ui->vlCoffeeParam->count() != 0)
	{
		QLayoutItem* child = ui->vlCoffeeParam->takeAt(0);
		if (child->layout() != 0)
		{
			// remove(child->layout()); // @todo
		}
		else if (child->widget() != 0)
		{
			delete child->widget();
		}

		delete child;
	}

	// Wy�wietl nowy parametr
	ICoffeeParam *param = _method->GetParamsForRecording().at(no);
	CoffeeParamSelector * cps = new CoffeeParamSelector(this, param);
	ui->vlCoffeeParam->addWidget(cps);

	// Je�eli parametr typu Czas rozpocznij odliczanie.
	if (param->GetParamType() == ParamType::TIME)
	{
		if (!_timer.isActive())
		{
			_startTime = QDateTime::currentDateTime();
			_timer.start(1000);
		}
		if (_currentTimeParam == nullptr)
		{
			_currentTimeParam = (TimeParam *)param;
		}

	}
	else
	{
		_timer.stop();
	}

	return true;
}

void RegisterCoffeeWidget::on_pbNext_clicked()
{
	_currentTimeParam = nullptr;
	if (_paramsDone < _paramsTodo)
	{
		ui->pbNext->setText("Dalej");
		renderParam(_paramsDone++);
	}
	else if (_paramsDone == _paramsTodo)
	{
		ui->pbNext->setText("Zako�cz");
		_paramsDone++;
	}
	else
	{
		this->close(); // Tutaj powinno by� co� w stylu wys�ania wiadomo�ci mailem.
		invokeOnRegisteringEnd();
	}
	ui->progressBar->setValue(_paramsDone);
}