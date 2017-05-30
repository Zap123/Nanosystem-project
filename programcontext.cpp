#include <typeinfo>
#include "programcontext.h"
#include "s_idle.h"

QVector<double> ProgramContext::cal_parameter(2);

ProgramContext::ProgramContext(QObject *parent) : QObject(parent)
{
    current = new s_IDLE(this);
    getCurrent();

}


ProgramContext::~ProgramContext()
{
    delete current;
}


void ProgramContext::idle(){
    current->idle(this);
}

void ProgramContext::calibration(){
    current->calibration(this);
}

void ProgramContext::measure(){
    current->measure(this);
}

void ProgramContext::getCurrent(){
    qDebug() << "Current state: " << current->objectName();
}

void ProgramContext::makeState(const QString &name){
    if(name == "IDLE")
        idle();
    else if(name == "CALIBRATION")
        calibration();
    else
        measure();

    QObject::connect(current, SIGNAL(connect()),
            this, SLOT(instanciateConnection()));

}

void ProgramContext::instanciateConnection(){
    if(!tcpSocket){
        qDebug() << "Connecting";
        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(ipAddress, port);

        //Show the status of the connection in the status bar
        connect(tcpSocket, SIGNAL(connected()),
                this, SIGNAL(connected()));
        connect(tcpSocket, SIGNAL(disconnected()),
                this, SIGNAL(disconnected()));
        connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(displayError(QAbstractSocket::SocketError)));

        tcpSocket->write("c");
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));

    }
}

void ProgramContext::displayError(QAbstractSocket::SocketError socketError){
    qDebug() << "NETWORK ERROR:";
    qDebug() << socketError;
}

void ProgramContext::readData(){
    qDebug() << "READ:";
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    QString line;
    in >> line;
    qDebug() << line;
}
