#include <QFile>
#include <QVector>
#include <QDebug>
#include <helper.h>

void test_parseASCII(QVector<double> *x_v, QVector<double> *y_i, QByteArray *q){
    QFile file(":/test/testASCII.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error:" << file.errorString();
    }


    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QList<QByteArray> splt = line.split(' ');

        x_v->append(splt.first().toDouble());
        y_i->append(splt.last().simplified().toDouble()); //remove carriage return
    }
}

void parseASCII(QVector<double> *x_v, QVector<double> *y_i, QByteArray *q){


        QList<QByteArray> lines = q->split('\n');

        foreach(QByteArray line, lines){
            QList<QByteArray> element = line.split(' ');
            qDebug(line);
            if(!line.isEmpty()){
                x_v->append(element.first().toDouble());
                y_i->append(element.last().toDouble());
            }
        }

}

QVector<double> calibration_parameter(QVector<double> *x_v, QVector<double> *y_i){
    double x_a, x_b, y_a, y_b;
    double m, q;
    QVector<double> parameter;

    x_a = x_v->first();
    x_b = x_v->last();
    y_a = y_i->first();
    y_b = y_i->last();

    m = (y_b - y_a)/(x_b - x_a);
    q = y_a - m*x_a;

    parameter.append(m);
    parameter.append(q);

    return parameter;
}

double cal_line(double x, double m, double q){
    return m*x+q;
}
