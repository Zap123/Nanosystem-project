#ifndef S_CALIBRATION_H
#define S_CALIBRATION_H

#include "state.h"

class s_CALIBRATION : public State
{
    Q_OBJECT
public:
    s_CALIBRATION(QObject *parent);

    void idle(MainWindow *p);
    void calibration(MainWindow *p);
    void measure(MainWindow *p);

signals:
    void requestData();
};

#endif // S_CALIBRATION_H
