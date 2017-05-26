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
    QVector<double> x = QVector<double>();
    QVector<double> y = QVector<double>();

    test_parseASCII(&x,&y);


    ui->calibrationText->setText("Starting...");
    ui->calibrationText->append("Getting data...");

    //TODO: keep value for next stage
    qDebug() << x;
    qDebug() << y;

}
