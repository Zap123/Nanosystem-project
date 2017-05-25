#ifndef STATE_H
#define STATE_H

#include <QDebug>
#include "programcontext.h"

class State
{
public:
    State();
    virtual void idle(ProgramContext *p){qDebug() << "Already in the state IDLE";}
    virtual void calibration(ProgramContext *p){qDebug() << "Already in the state CALIBRATION";}
    virtual void measure(ProgramContext *p){qDebug() << "Already in the state MEASURE";}
};
#endif // STATE_H
