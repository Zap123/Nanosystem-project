#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Disconnected");
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

void MainWindow::connected()
{
    ui->statusBar->showMessage("Connected");
}

void MainWindow::disconnected()
{
    ui->statusBar->showMessage("Disconnected");
}


void MainWindow::on_actionConnect_triggered()
{
    instanciateConnection();
}

void MainWindow::instanciateConnection(){
    if(!tcpSocket){
        qDebug() << "Connecting";
        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(ipAddress, port);

        //Show the status of the connection in the status bar
        connect(tcpSocket, SIGNAL(connected()),
                this, SLOT(connected()));
        connect(tcpSocket, SIGNAL(disconnected()),
                this, SLOT(disconnected()));
        connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(displayError(QAbstractSocket::SocketError)));

        tcpSocket->write("c");
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));

    }
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError){
    qDebug() << "NETWORK ERROR:";
    qDebug() << socketError;
}

void MainWindow::readData(){
    qDebug() << "READ:";
    qDebug() << tcpSocket->readAll();
}

int MainWindow::showCalibrationDialog(int s){
    qDebug() << "Opening Caliration Dialog";

    if(!cal_win)
        cal_win = new Calibrate(this);
    if(!cal_win->isVisible()){
        cal_win->show();
        s= 0;
    }
    else
        s= 1;
}
