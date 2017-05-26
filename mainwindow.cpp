#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    context = new ProgramContext();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete context;
}

void MainWindow::on_actionCalibrate_triggered()
{
    context->calibration();
}

void MainWindow::on_actionMeasure_triggered()
{
    context->measure();
}
