#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_actionCalibrate_triggered();

    void on_actionMeasure_triggered();

signals:
    //state you want to move
    void changeState(QString const &name);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
