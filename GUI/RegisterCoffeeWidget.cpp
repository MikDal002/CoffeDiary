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
	if (_currentTimeParam == 0) return;

	_currentTimeParam->SetValue(_startTime.secsTo(QDateTime::currentDateTime()));

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
	// wyczyœæ GUI.
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

	// Wyœwietl nowy parametr
	ICoffeeParam *param = _method->GetParamsForRecording().at(no);
	CoffeeParamSelector * cps = new CoffeeParamSelector(this, param);
	ui->vlCoffeeParam->addWidget(cps);

	// Je¿eli parametr typu Czas rozpocznij odliczanie.
	if (param->GetParamType() == ParamType::TIME)
	{
		if (!_timer.isActive())
		{
			_startTime = QDateTime::currentDateTime();
			_currentTimeParam = (TimeParam *)param;
			_timer.start(1000);
		}

	}

	return true;
}

void RegisterCoffeeWidget::on_pbNext_clicked()
{
	if (_paramsDone < _paramsTodo) renderParam(_paramsDone++);
	else
	{
		// Parzenie dobieg³o koñca.
	}
	ui->progressBar->setValue(_paramsDone);
}
