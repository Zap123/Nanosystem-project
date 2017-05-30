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
    emit(startConnection());
}


