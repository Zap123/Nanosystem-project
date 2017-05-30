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


    return a.exec();
}
