#include "programcontext.h"
#include "s_idle.h"

QVector<double> ProgramContext::cal_parameter(2);

ProgramContext::ProgramContext(QObject *parent) : QObject(parent)
{
    current = new s_IDLE(this);
    getCurrent();

}


ProgramContext::~ProgramContext()
{
    delete current;
}


void ProgramContext::idle(){
    current->idle(this);
}

void ProgramContext::calibration(){
    current->calibration(this);
}

void ProgramContext::measure(){
    current->measure(this);
}

void ProgramContext::getCurrent(){
    qDebug() << "Current state: " << current->objectName();
}

void ProgramContext::makeState(const QString &name){
    if(name == "IDLE")
        idle();
    else if(name == "CALIBRATION")
        calibration();
    else
        measure();

    QObject::connect(current, SIGNAL(connect()),
            this, SLOT(instanciateConnection()));

}

void ProgramContext::openCalibration(){
    emit(requestCalibrationDialog());
}
