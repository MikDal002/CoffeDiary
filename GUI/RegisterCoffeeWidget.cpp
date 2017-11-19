#include "RegisterCoffeeWidget.h"
#include "ui_RegisterCoffeeWidget.h"

RegisterCoffeeWidget::RegisterCoffeeWidget(QWidget *parent, ICoffeeMethod * coffee)
	: QWidget(parent), ui(new Ui::RegisterCoffeeWidget)
{
	ui->setupUi(this);
	_method = coffee;

	_paramsTodo = coffee->GetParamsForRecording().length();
	setUpGUI();
}

RegisterCoffeeWidget::~RegisterCoffeeWidget()
{

}

void RegisterCoffeeWidget::setUpGUI()
{
	ui->progressBar->setMaximum(_paramsTodo);
	ui->pbNext->setText("Rozpocznij");
}

bool RegisterCoffeeWidget::renderParam(uint32_t no)
{
	
}

void RegisterCoffeeWidget::on_pbNext_clicked()
{
	renderParam(_paramsDone++);
}
