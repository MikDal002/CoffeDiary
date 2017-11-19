#pragma once

#include <QWidget>
#include "../Core/ICoffeeMethod.h"
namespace Ui {
	class RegisterCoffeeWidget;
}
class RegisterCoffeeWidget : public QWidget
{
	Q_OBJECT

public:
	RegisterCoffeeWidget(QWidget *parent = 0, ICoffeeMethod * coffee = 0);
	~RegisterCoffeeWidget();

private slots:
    void on_pbNext_clicked();

private:
	Ui::RegisterCoffeeWidget *ui;
	ICoffeeMethod *_method;
	uint32_t _paramsTodo = 0;
	uint32_t _paramsDone = 0;
	void setUpGUI();
	bool renderParam(uint32_t no);
};
