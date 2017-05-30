#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "s_idle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Disconnected");


    setCurrent(new s_IDLE(this));
    getCurrent();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete current;
}

void MainWindow::idle(){
    current->idle(this);
}

void MainWindow::calibration(){
    current->calibration(this);
}

void MainWindow::measure(){
    current->measure(this);
}

void MainWindow::getCurrent(){
    qDebug() << "Current state: " << current->objectName();
}


void MainWindow::on_actionCalibrate_triggered()
{
    calibration();
}

void MainWindow::on_actionMeasure_triggered()
{
    measure();
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

int MainWindow::showCalibrationDialog(){
    qDebug() << "Opening Caliration Dialog";

    if(!cal_win){
        cal_win = new Calibrate(this);
        QObject::connect(cal_win, SIGNAL(parameter(QVector<double>*)), this, SLOT(setParameter(QVector<double>*)));
    }

    if(!cal_win->isVisible()){
        cal_win->show();
        return 0;
    }
    else
        return 1;
}

void MainWindow::setParameter(QVector<double> *par){
    cal_parameter = par;
    qDebug() << cal_parameter->at(0);
}
