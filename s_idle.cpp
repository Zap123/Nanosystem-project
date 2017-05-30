#include <QDebug>
#include <QMessageBox>
#include "s_idle.h"
#include "s_calibration.h"



s_IDLE::s_IDLE(QObject *parent) : State(parent, "IDLE")
{
}

void s_IDLE::idle(MainWindow *p){
    qDebug() << "Test";
}

void s_IDLE::calibration(MainWindow *p){
    p->setCurrent(new s_CALIBRATION(p));
    p->showCalibrationDialog();

    p->getCurrent();

    delete this;
}


void s_IDLE::measure(MainWindow *p){
    QString invStateError = "You must calibrate the sensor before measuring";

    qDebug() << invStateError;
    QMessageBox::critical(0, "Invalid State", invStateError);
}
