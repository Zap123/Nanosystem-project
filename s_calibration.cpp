#include <QMessageBox>
#include "s_calibration.h"

s_CALIBRATION::s_CALIBRATION(QObject *parent) : State(parent, "CALIBRATION")
{
    this->setObjectName("IDLE");
    w = new Calibrate((QWidget*) parent->parent());
    w->show();

    QObject::connect(w, SIGNAL(connect()), this, SIGNAL(connect()));
    //QObject::connect(w, SIGNAL(recvData()), this, SIGNAL(recvData()));

}

s_CALIBRATION::~ s_CALIBRATION()
{
    delete w;
}


void s_CALIBRATION::idle(ProgramContext *p){
    qDebug() << "CAL";
}

void s_CALIBRATION::calibration(ProgramContext *p){

    if(w->isHidden()){
        w->show();
    }
    else{
        QString invState = "Already in the calibration State";
        QMessageBox::critical(0, "Invalid State", invState);

        qDebug() << invState;
    }
}


void s_CALIBRATION::measure(ProgramContext *p){
    qDebug() << "CAL";
}


void s_CALIBRATION::connect(){
    qDebug() << "CONN1";
}
