#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "programcontext.h"
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    const QString ipAddress = "192.168.1.21";
    const int port = 5040;


private slots:
    void on_actionCalibrate_triggered();
    void displayError(QAbstractSocket::SocketError socketError);
    void on_actionMeasure_triggered();
    void sessionOpened();


    void on_actionConnect_triggered();

signals:
    //state you want to move
    void changeState(QString const &name);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
