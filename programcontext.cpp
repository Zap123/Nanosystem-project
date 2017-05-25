#include <typeinfo>
#include "programcontext.h"
#include "idle.h"

ProgramContext::ProgramContext()
{
    setCurrent(new IDLE());
    getCurrent();
}

void ProgramContext::idle(){
    current->idle(this);
}

void ProgramContext::getCurrent(){
    qDebug() << "Current state: " << typeid(current).name();
}
