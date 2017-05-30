#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractSocket>
#include <QTcpSocket>
#include <QMainWindow>
#include "programcontext.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTcpSocket *tcpSocket = 0;
    const QString ipAddress = "localhost";
    const int port = 5040;

private slots:
    void on_actionCalibrate_triggered();
    void on_actionMeasure_triggered();
    void connected();
    void disconnected();
    void on_actionConnect_triggered();
    void instanciateConnection();
    void displayError(QAbstractSocket::SocketError socketError);
    void readData();

signals:
    //state you want to move
    void changeState(QString const &name);
    void startConnection();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
