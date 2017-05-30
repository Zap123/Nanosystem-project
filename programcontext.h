#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

#include <QVector>
#include <QApplication>
#include "mainwindow.h"

class ProgramContext : public QObject
{
    Q_OBJECT

private:
    class State *current;

public:
    ProgramContext(QObject *parent = 0);
    ~ProgramContext(); 

    void setCurrent(State *s){
        current = s;
    }

    void getCurrent();

    //global calibration parameter
    static QVector<double> cal_parameter;
    void openCalibration();

    //states declaration
    void idle();
    void calibration();
    void measure();

signals:
    void requestCalibrationDialog();
    void calibrationDialogStatus(int *s);

private slots:
    void makeState(QString const &name);

};



#endif // PROGRAMCONTEXT_H
