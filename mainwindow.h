#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractSocket>
#include <QTcpSocket>
#include <QMainWindow>
#include "calibrate.h"
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

    //Network Config
    QTcpSocket *tcpSocket = 0;
    const QString ipAddress = "localhost";
    const int port = 5040;

    void setCurrent(State *s){
        current = s;
    }

    void getCurrent();

    //calibration parameter
    QVector<double> *cal_parameter;
    void openCalibration();

    //states declaration
    void idle();
    void calibration();
    void measure();

    int showCalibrationDialog();

private slots:
    void on_actionCalibrate_triggered();
    void on_actionMeasure_triggered();
    void connected();
    void disconnected();
    void on_actionConnect_triggered();
    void instanciateConnection();
    void displayError(QAbstractSocket::SocketError socketError);
    void readData();
    void setParameter(QVector<double> *par);




signals:
    //state you want to move
    void changeState(QString const &name);
    void startConnection();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
