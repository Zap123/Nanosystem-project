#ifndef S_CALIBRATION_H
#define S_CALIBRATION_H

#include "state.h"

class s_CALIBRATION : public State
{

public:
    s_CALIBRATION(QObject *parent);

    void idle(MainWindow *p);
    void calibration(MainWindow *p);
    void measure(MainWindow *p);
private slots:
    void connect();
};

#endif // S_CALIBRATION_H
