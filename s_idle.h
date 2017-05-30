#ifndef IDLE_H
#define IDLE_H

#include "state.h"
#include "mainwindow.h"

class s_IDLE: public State
{

public:
    s_IDLE(QObject *parent);

    void idle(MainWindow *p);
    void calibration(MainWindow *p);
    void measure(MainWindow *p);
};

#endif // IDLE_H
