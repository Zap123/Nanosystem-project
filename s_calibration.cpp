#include <QMessageBox>
#include "s_calibration.h"

s_CALIBRATION::s_CALIBRATION(QObject *parent) : State(parent, "CALIBRATION")
{
}

void s_CALIBRATION::idle(MainWindow *p){
    qDebug() << "CAL";
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
    qDebug() << "CAL";
}
