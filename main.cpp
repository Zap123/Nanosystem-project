#include "mainwindow.h"
#include <QApplication>
#include <QFile>


/*
void MessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
     QString txt;
     QByteArray localMsg = msg.toLocal8Bit();
     switch (type) {
         case QtDebugMsg:
             txt = QString("Debug: %1").arg(msg);
             fprintf(stderr, "Debug: %s \n", localMsg.constData());
             break;
         case QtWarningMsg:
             txt = QString("Warning: %1").arg(msg);
             fprintf(stderr, "Warning: %s \n", localMsg.constData());
         break;
         case QtInfoMsg:
            txt = QString("%1").arg(msg);
            fprintf(stderr, "%s", localMsg.constData());
            break;
         case QtCriticalMsg:
             txt = QString("Critical: %1").arg(msg);
             fprintf(stderr, "Warning: %s \n", localMsg.constData());
         break;
         case QtFatalMsg:
             txt = QString("Fatal: %1").arg(msg);
             fprintf(stderr, "Fatal: %s \n", localMsg.constData());
         break;
     }
     QFile outFile("logFile.txt");
     outFile.open(QIODevice::WriteOnly| QIODevice::Append);
     QTextStream ts(&outFile);
     ts << txt << endl;
}
*/

int main(int argc, char *argv[])
{
    //qInstallMessageHandler(MessageOutput); //Redirect output to Logfile

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
