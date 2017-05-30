#ifndef STATE_H
#define STATE_H

#include <QDebug>
#include "mainwindow.h"

class State : public QObject
{
    Q_OBJECT
public:
    State(QObject *parent = 0, const  char *name = "no_name");

    virtual void idle(MainWindow *p){
        qDebug() << "Already in the state IDLE";
    }

    virtual void calibration(MainWindow *p){
        qDebug() << "Already in the state CALIBRATION";
    }

    virtual void measure(MainWindow *p){
        qDebug() << "Already in the state MEASURE";
    }


signals:
    void connect();
};
#endif // STATE_H
