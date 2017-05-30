#ifndef S_MEASURE_H
#define S_MEASURE_H

#include "state.h"
#include "mainwindow.h"

class s_MEASURE : public State
{
    Q_OBJECT
public:
    s_MEASURE(QObject *parent);

    void idle(MainWindow *p);
    void calibration(MainWindow *p);
    void measure(MainWindow *p);
};

#endif // S_MEASURE_H
