#include <QMessageBox>
#include "s_calibration.h"
#include "s_measure.h"

s_CALIBRATION::s_CALIBRATION(QObject *parent) : State(parent, "CALIBRATION")
{
}

void s_CALIBRATION::idle(MainWindow *p){

}

void s_CALIBRATION::calibration(MainWindow *p){

    if(p->cal_win->isHidden()){
        p->cal_win->show();
    }
    else{
        QString invState = "Already in the calibration State";
        QMessageBox::critical(0, "Invalid State", invState);

        qDebug() << invState;
    }

}


void s_CALIBRATION::measure(MainWindow *p){
    if(!p->cal_parameter.isEmpty()){
        p->setCurrent(new s_MEASURE(p));

        p->getCurrent();

        //change process function
        QObject::disconnect(p->tcpSocket, SIGNAL(readyRead()), p, SLOT(processCalibration()));
        QObject::connect(p->tcpSocket, SIGNAL(readyRead()), p, SLOT(processVoltimetry()));

        //signal to request data
        QObject::connect(this, SIGNAL(requestData()), p, SLOT(sendData()));

        //Request voltimetry
        emit(requestData());

        delete this;
    }
    else{
        QString invState = "Calibration not concluded";
        QMessageBox::critical(0, "Invalid State", invState);

        qDebug() << invState;
    }
}
