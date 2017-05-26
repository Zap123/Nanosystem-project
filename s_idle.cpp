#include <QDebug>
#include <QMessageBox>
#include "s_idle.h"
#include "s_calibration.h"



s_IDLE::s_IDLE()
{

}

void s_IDLE::idle(ProgramContext *p){
    qDebug() << "Test";
}

void s_IDLE::calibration(ProgramContext *p){
    qDebug() << "Moving to Calibration Phase";
    p->setCurrent(new s_CALIBRATION());

    delete this;
}


void s_IDLE::measure(ProgramContext *p){
    QString invStateError = "You must calibrate the sensor before measuring";

    qDebug() << invStateError;
    QMessageBox messageBox;
    messageBox.critical(0, "Invalid State", invStateError);
}
