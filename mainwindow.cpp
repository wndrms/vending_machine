#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    money_ = 0;
    setControl();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setControl()
{
    ui->lcdNumber->display(money_);
    ui->pbCoffee->setEnabled(money_ >= 100);
    ui->pbTea->setEnabled(money_ >= 150);
    ui->pbCola->setEnabled(money_ >= 200);
}
void MainWindow::on_pb500_clicked()
{
    money_ += 500;
    setControl();
}

void MainWindow::on_pb100_clicked()
{
    money_ += 100;
    setControl();
}

void MainWindow::on_pb50_clicked()
{
    money_ += 50;
    setControl();
}

void MainWindow::on_pb10_clicked()
{
    money_ += 10;
    setControl();
}

void MainWindow::on_pbCoffee_clicked()
{
    money_ -= 100;
    setControl();
}

void MainWindow::on_pbTea_clicked()
{
    money_ -= 150;
    setControl();
}

void MainWindow::on_pbCola_clicked()
{
    money_ -= 200;
    setControl();
}

void MainWindow::on_pbReset_clicked()
{
    QMessageBox box;
    int num500,num100,num50,num10;
    num500 = money_ / 500; money_ %= 500;
    num100 = money_ / 100; money_ %= 100;
    num50 = money_ / 50; money_ %= 50;
    num10 = money_ / 10; money_ %= 10;
    QString status = QString("500Won : %1\n100Won : %2\n50Won : %3\n10Won : %4").arg(num500).arg(num100).arg(num50).arg(num10);
    box.setText(status);
    box.exec();
    setControl();
}
