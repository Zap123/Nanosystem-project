/**
    Chart window

    @author Luca Costa
    @version 1
*/

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

    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(7, -7);
    ui->customPlot->replot();
}

Chart::~Chart()
{
    delete ui;
}

void Chart::plot(double x, double y){
    ui->customPlot->graph(0)->addData(x, y);
    // make key axis range scroll with the data (at a constant range size of 8):
    //ui->customPlot->xAxis->setRange(x, 0.1, Qt::AlignRight);
    if(first){
        max_C = y;
        min_C = y;
        first = false;
    }
    else{
        if(y>max_C){
            max_C = y;
        }
        if(y<min_C){
            min_C = y;
        }
    }
    ui->customPlot->yAxis->setRange(min_C, max_C);


    ui->customPlot->replot();
}
