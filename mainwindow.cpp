#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCalibrate_triggered()
{
    emit(changeState("CALIBRATION"));
}

void MainWindow::on_actionMeasure_triggered()
{
    emit(changeState("MEASURE"));
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError){
    qDebug() << "NETWORK ERROR:";
    qDebug() << socketError;
}

void MainWindow::sessionOpened(){
    qDebug() << "Session Opened";
}

void MainWindow::on_actionConnect_triggered()
{
    //Open Network Interface
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config = manager.defaultConfiguration();
    QNetworkSession *networkSession = new QNetworkSession(config, this);
    networkSession->open();


    QTcpSocket *tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(ipAddress, port);

    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
}
