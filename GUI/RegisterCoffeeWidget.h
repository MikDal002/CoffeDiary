#pragma once

#include <QWidget>
#include <qdatetime.h>
#include <functional>
#include <qtimer.h>
#include "../Core/ICoffeeMethod.h"
#include "../Core/CoffeeParams/TimeParam.h"
namespace Ui {
	class RegisterCoffeeWidget;
}
class RegisterCoffeeWidget : public QWidget
{
	Q_OBJECT

public:
	RegisterCoffeeWidget(QWidget *parent = 0, ICoffeeMethod * coffee = 0);
	~RegisterCoffeeWidget();
	std::function<void()> OnRegisteringEnd;

private slots:
    void on_pbNext_clicked();
	void timerTimeout();

private:
	void invokeOnRegisteringEnd();
	TimeParam * _currentTimeParam;
	QTimer _timer;
	QDateTime _startTime;
	Ui::RegisterCoffeeWidget *ui;
	ICoffeeMethod *_method;
	uint32_t _paramsTodo = 0;
	uint32_t _paramsDone = 0;
	void setUpGUI();
	bool renderParam(uint32_t no);
};
