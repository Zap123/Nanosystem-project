#ifndef S_CALIBRATION_H
#define S_CALIBRATION_H

#include "state.h"
#include "programcontext.h"
#include "calibrate.h"

class s_CALIBRATION : public State
{
public:
    s_CALIBRATION();
    ~s_CALIBRATION();
    Calibrate *w; //dialog
    void idle(ProgramContext *p);
    void calibration(ProgramContext *p);
    void measure(ProgramContext *p);
};

#endif // S_CALIBRATION_H
