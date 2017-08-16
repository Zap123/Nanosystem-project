#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractSocket>
#include <QTcpSocket>
#include <QMainWindow>
#include "calibrate.h"
#include "chart.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    class State *current;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Calibrate *cal_win = 0;
    Chart *chart_win = 0;
    int volt = 1;
    int cal_packet = 0;
    QByteArray *cal_data;
    bool enter = true;

    //Network Config
    QTcpSocket *tcpSocket = 0;

    const QString ipAddress = "192.168.1.10";
    const int port = 7;

    //const QString ipAddress = "localhost";
    //const int port = 5040;

    void setCurrent(State *s){
        current = s;
    }

    void getCurrent();

    //calibration parameter
    QVector<double> cal_parameter;
    void openCalibration();

    //states declaration
    void idle();
    void calibration();
    void measure();

    void showCalibrationDialog();

private slots:
    void on_actionCalibrate_triggered();
    void on_actionMeasure_triggered();
    void connected();
    void disconnected();
    void on_actionConnect_triggered();
    void instanciateConnection();
    void displayError(QAbstractSocket::SocketError socketError);
    void processCalibration();
    void processVoltimetry();
    void setParameter(QVector<double> par);
    void sendData();

signals:
    //state you want to move
    void changeState(QString const &name);
    void startConnection();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
