#include "TimeParam.h"
#include <QTime>
#include <QDebug>
ParamType TimeParam::GetParamType()
{
    return ParamType::TIME;
}

TimeParam::TimeParam(QString name, QString unit) : ICoffeeParam (name, unit)
{
	_value = QTime(0, 0, 0, 0);
}

QString TimeParam::ToString()
{
    return _value.toTime().toString("mm:ss") + " " + _unit;
}

void TimeParam::SetValue(QVariant value)
{
	if (value.toTime() == _value.toTime())
		return;
	qDebug() << "Nowa wartoœæ: " << value;
	_value = QTime(value.toInt() / 3600, (value.toInt() / 60) % 60, value.toInt() % 60, 0);
	if (OnValueChanged) OnValueChanged();
}
