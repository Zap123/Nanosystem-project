#ifndef CALIBRATE_H
#define CALIBRATE_H

#include <QDialog>
#include <QVector>
namespace Ui {
class Calibrate;
}

class Calibrate : public QDialog
{
    Q_OBJECT

public:
    explicit Calibrate(QWidget *parent = 0);
    ~Calibrate();
    void calc_par(QByteArray *q);

private slots:
    void on_pushButton_clicked();

signals:
    void parameter(QVector<double> par);
    void connect();
    void requestData();

private:
    Ui::Calibrate *ui;
};

#endif // CALIBRATE_H
