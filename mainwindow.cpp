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
