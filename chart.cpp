#include "chart.h"
#include "ui_chart.h"

Chart::Chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chart)
{
    ui->setupUi(this);
    ui->customPlot->addGraph(); // blue line
    //ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));

    ui->customPlot->xAxis->setRange(0, 0.04);
    ui->customPlot->yAxis->setRange(123676, 178189);
    ui->customPlot->replot();
}

Chart::~Chart()
{
    delete ui;
}

void Chart::plot(double x, double y){
    ui->customPlot->graph(0)->addData(x, y);
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(x, 20, Qt::AlignRight);
    ui->customPlot->replot();
}
