#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Child of the main window
    ProgramContext *context;
    context = new ProgramContext(&w);

    //connect MainWindow and ProgramContext(state machine)
    QObject::connect( &w, SIGNAL(changeState(QString)), context, SLOT(makeState(QString)) );

    //Calibration dialog
    QObject::connect(context, SIGNAL(requestCalibrationDialog()), &w, SLOT(showCalibrationDialog()));


    return a.exec();
}
