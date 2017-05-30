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

    //start connection message
    QObject::connect( &w, SIGNAL(startConnection()), context, SLOT(instanciateConnection()) );

    //status bar notification
    QObject::connect(context, SIGNAL(connected()), &w, SLOT(connected()) );
    QObject::connect(context, SIGNAL(disconnected()), &w, SLOT(disconnected()) );

    return a.exec();
}
