#include <typeinfo>
#include "programcontext.h"
#include "s_idle.h"

ProgramContext::ProgramContext()
{
    current = new s_IDLE();
    getCurrent();
}

void ProgramContext::idle(){
    current->idle(this);
}

void ProgramContext::getCurrent(){
    qDebug() << "Current state: " << typeid(current).name();
}
