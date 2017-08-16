/**
    Calibration window

    @author Luca Costa
    @version 1
*/


#include <QDebug>
#include "helper.h"
#include "calibrate.h"
#include "ui_calibrate.h"
#include "calibrate.h"
#include "s_idle.h"
#include "mainwindow.h"

Calibrate::Calibrate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calibrate)
{
    ui->setupUi(this);
}

Calibrate::~Calibrate()
{
    delete ui;
}

void Calibrate::on_pushButton_clicked()
{
    emit(connect());

    ui->calibrationText->setText("Starting...");
    ui->calibrationText->append("Getting data...");

    emit(requestData());
}

void Calibrate::calc_par(QByteArray *data){
    QVector<double> x;
    QVector<double> y;


    parseASCII(&x,&y, data);

    QVector<double> par = least_square(&x,&y);
    QString m = QString::number(par.at(0));
    QString q = QString::number(par.at(1));

    emit(parameter(par));
    ui->calibrationText->append("calibration line:");
    ui->calibrationText->append(QString("y=%1x+%2").arg(m,q));
    ui->calibrationText->append("Calibration finished, please start the measuring now");


    //qDebug() << x;
    //qDebug() << y;

    ui->pushButton->hide();
}
