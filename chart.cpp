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

    ui->customPlot->xAxis->setRange(-1.2, 1.2);
    ui->customPlot->yAxis->setRange(1e+09, 15e+09);
    ui->customPlot->replot();
}

Chart::~Chart()
{
    delete ui;
}

void Chart::plot(double x, double y){
    ui->customPlot->graph(0)->addData(x, y);
    // make key axis range scroll with the data (at a constant range size of 8):
    //ui->customPlot->yAxis->setRange(y, 10, Qt::AlignRight);
    //ui->customPlot->xAxis->setRange(x, 10, Qt::AlignRight);

    ui->customPlot->replot();
}
