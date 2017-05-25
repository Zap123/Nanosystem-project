#include "mainwindow.h"
#include <QApplication>
#include "helper.cpp"
#include "programcontext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ProgramContext *context = new ProgramContext();
    context->idle();
    parseASCII();

    return a.exec();
}
