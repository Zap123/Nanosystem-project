/**
    Measure State of the State Machine

    @author Luca Costa
    @version 1
*/

#include "s_measure.h"
#include <QMessageBox>

s_MEASURE::s_MEASURE(QObject *parent): State(parent, "MEASURE")
{
}

void s_MEASURE::calibration(MainWindow *p){
    QString invStateError = "You have already calibrated your sensor";

    qDebug() << invStateError;
    QMessageBox::critical(0, "Invalid State", invStateError);
}

void s_MEASURE::measure(MainWindow *p){

}

void s_MEASURE::idle(MainWindow *p){

}
