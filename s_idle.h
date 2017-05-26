#ifndef IDLE_H
#define IDLE_H

#include "state.h"
#include "programcontext.h"

class s_IDLE: public State
{
public:
    s_IDLE();

    void idle(ProgramContext *p);
    void calibration(ProgramContext *p);
    void measure(ProgramContext *p);
};

#endif // IDLE_H
