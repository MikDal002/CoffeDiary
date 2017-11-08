#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <GUI/CoffeeParamSelector.h>
#include <QDateTime>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach (ICoffeeMethod * foo, _coffeDiary.GetAvailableCoffeMethods())
    {
        ui->cbCoffeMethods->addItem(foo->GetName());
    }
    ui->cbCoffeMethods->setCurrentIndex(-1);
    SendStartBtnsVisibility(false);
    ui->pbBegin->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbBegin_clicked()
{
    int selected = ui->cbCoffeMethods->currentIndex();
    if (selected < 0) return; // @error

    QLayoutItem* child;
    while(ui->PropertiesLayout->count()!=0)
    {
        child = ui->PropertiesLayout->takeAt(0);
        if(child->layout() != 0)
        {
            // remove(child->layout()); // @todo
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }

    int row = 0;
    ICoffeeMethod * method = _coffeDiary.GetAvailableCoffeMethods().at(selected);

    foreach (ICoffeeParam * foo, method->GetParams())
    {
        ui->PropertiesLayout->addWidget(new CoffeeParamSelector(this, foo), row/2, row%2);
        row += 1;
    }
    setDescriptionString();
    SendStartBtnsVisibility(true);
}

void MainWindow::SendStartBtnsVisibility(bool isVisible)
{
    ui->lbDescription->setVisible(isVisible);
    ui->pbStart->setEnabled(false);
    ui->pbStart->setVisible(isVisible);
    ui->pbSendMail->setEnabled(isVisible);
    ui->pbSendMail->setVisible(isVisible);
}

void MainWindow::setDescriptionString()
{
    if (ui->rbPlanNewCoffe->isChecked())
    {
        ui->lbDescription->setText("Ustawione parametry będą potem wykorzystane do przeprowadzenia Cię przez proces parzenia po naciśnięciu przycisku \"Rozpocznij\"");
    }
    else if (ui->rbRecordnewCoffe->isChecked())
    {
        ui->lbDescription->setText("Po naciśnięciu przycisku \"Rozpocznij\" zacznie się pomiar czasu i automatycznie zostaną uzupełnione dane na temat całkowitego czasu parzenia");
    }
    else
    {
        return;
    }
}

void MainWindow::on_pbSendMail_clicked()
{
    QString content = QString("mailto:?to=&subject=Dziennik kawowy z dnia %1&body=%2")
            .arg(QDateTime::currentDateTime().toString(Qt::SystemLocaleLongDate))
            .arg(_coffeDiary.GetAvailableCoffeMethods().at(ui->cbCoffeMethods->currentIndex())->GetMailBody());
    QDesktopServices::openUrl(QUrl(content, QUrl::TolerantMode));
}

void MainWindow::on_cbCoffeMethods_currentIndexChanged(int index)
{
    if (index > -1)
    {
        ui->rbPlanNewCoffe->setEnabled(true);
        ui->rbRecordnewCoffe->setEnabled(true);
    }
    else
    {
        ui->rbPlanNewCoffe->setEnabled(false);
        ui->rbRecordnewCoffe->setEnabled(false);
    }
}

void MainWindow::on_rbPlanNewCoffe_clicked()
{
    ui->pbBegin->setEnabled(true);
}

void MainWindow::on_rbRecordnewCoffe_clicked()
{
    ui->pbBegin->setEnabled(true);
}
