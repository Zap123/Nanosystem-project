#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "s_idle.h"
#include "helper.h"

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
    tcpSocket->close();
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

        //connect socket new data with calibration process fn
        QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(processCalibration()));

    }

}

void MainWindow::displayError(QAbstractSocket::SocketError socketError){
    qDebug() << "NETWORK ERROR:";
    qDebug() << socketError;
}

void MainWindow::sendData(){
    tcpSocket->write("0");
}

void MainWindow::processCalibration(){
    qDebug() << "READ:";
    QByteArray readData = tcpSocket->readAll();
    qDebug() << readData;

    cal_win->calc_par(&readData);
}

void MainWindow::processVoltimetry(){
    qDebug() << "READ:";
    QByteArray readData = tcpSocket->readAll();
    qDebug() << readData;

    QVector<double> v,I;
    parseASCII(&v,&I,&readData);


    //qDebug()<< cal_parameter.isEmpty();
    double I_cal = cal_line(v.at(0),cal_parameter.at(0), cal_parameter.at(1));
    double out = I.at(0) - I_cal;

    qDebug() << "V:" << v.at(0);
    qDebug() << "I:" << out;

    //qDebug() << "I_cal:";
    //qDebug() << I_cal;

    ui->lcdV->setText(QString::number(v.at(0)));
    ui->lcdI->setText(QString::number(out));
}

void MainWindow::showCalibrationDialog(){
    qDebug() << "Opening Calibration Dialog";

    if(!cal_win){
        cal_win = new Calibrate(this);
        //save cal data
        QObject::connect(cal_win, SIGNAL(parameter(QVector<double>)), this, SLOT(setParameter(QVector<double>)));

        //open connection from dialog
        QObject::connect(cal_win, SIGNAL(connect()), this, SLOT(instanciateConnection()));
        QObject::connect(cal_win, SIGNAL(requestData()), this, SLOT(sendData()));

    }

    if(!cal_win->isVisible()){
        cal_win->show();
    }

}

void MainWindow::setParameter(QVector<double> par){
    cal_parameter = par;
    qDebug() << "parameters:";
    qDebug() << par.at(0);
    qDebug() << par.at(1);
}
