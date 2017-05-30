#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

#include <QVector>
#include <QApplication>
#include <QAbstractSocket>
#include <QTcpSocket>
#include "mainwindow.h"

class ProgramContext : public QObject
{
    Q_OBJECT

private:
    class State *current;

public:
    ProgramContext(QObject *parent = 0);
    ~ProgramContext(); 

    QTcpSocket *tcpSocket = 0;
    const QString ipAddress = "localhost";
    const int port = 5040;

    void setCurrent(State *s){
        current = s;
    }

    void getCurrent();

    //global calibration parameter
    static QVector<double> cal_parameter;

    //states declaration
    void idle();
    void calibration();
    void measure();

signals:
    void connected();
    void disconnected();

private slots:
    void makeState(QString const &name);
    void instanciateConnection();
    void displayError(QAbstractSocket::SocketError socketError);
    void readData();

};



#endif // PROGRAMCONTEXT_H
