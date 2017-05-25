#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

#include <QDebug>
#include "state.h"

class ProgramContext
{
    class State *current;

public:
    ProgramContext();
    void getCurrent();
    void setCurrent(State *s){
        this->current = s;
        qDebug() << "Changing State";
    }
    void idle();
    void calibration();
    void measure();



};

#endif // PROGRAMCONTEXT_H
