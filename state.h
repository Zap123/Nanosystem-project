#ifndef STATE_H
#define STATE_H

#include <QDebug>
#include "programcontext.h"

class State : public QObject
{
    Q_OBJECT

public:
    State(QObject *parent = 0, const  char *name = "no_name");
    virtual void idle(ProgramContext *p){
        qDebug() << "Already in the state IDLE";
    }

    virtual void calibration(ProgramContext *p){
        qDebug() << "Already in the state CALIBRATION";
    }

    virtual void measure(ProgramContext *p){
        qDebug() << "Already in the state MEASURE";
    }


signals:
    void connect();
    void recvData();
};
#endif // STATE_H
