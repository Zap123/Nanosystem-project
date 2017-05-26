#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

#include <QDebug>

class ProgramContext
{
private:
    class State *current;

public:
    ProgramContext();
    void setCurrent(State *s){
        current = s;
        qDebug() << "Changing State";
    }

    void getCurrent();

    //states declaration
    void idle();
    void calibration();
    void measure();

};

#endif // PROGRAMCONTEXT_H
