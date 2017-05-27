#include <QDebug>
#include "helper.h"
#include "calibrate.h"
#include "ui_calibrate.h"

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
    QVector<double> x;
    QVector<double> y;

    test_parseASCII(&x,&y);


    ui->calibrationText->setText("Starting...");
    ui->calibrationText->append("Getting data...");

    QVector<double> par;
    par = calibration_parameter(&x,&y);
    QString m = QString::number(par.at(0));
    QString q = QString::number(par.at(1));

    ui->calibrationText->append("calibration line:");
    ui->calibrationText->append(QString("y=%1x+%2").arg(m,q));
    ui->calibrationText->append("Calibration finished, start the measuring now");


    //TODO: keep value for next stage
    qDebug() << x;
    qDebug() << y;

}
