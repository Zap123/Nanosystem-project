#ifndef CHART_H
#define CHART_H

#include <QWidget>

namespace Ui {
class Chart;
}

class Chart : public QWidget
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = 0);
    ~Chart();
    void plot(double x, double y);
    double min_C = 0;
    double max_C = 100000;
    bool first=true;

private:
    Ui::Chart *ui;

};

#endif // CHART_H
