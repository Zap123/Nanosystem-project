#ifndef HELPER_H
#define HELPER_H

void test_parseASCII(QVector<double> *x_v, QVector<double> *y_i);
void parseASCII(QVector<double> *x_v, QVector<double> *y_i, QByteArray *q);

QVector<double> calibration_parameter(QVector<double> *x_v, QVector<double> *y_i);

double cal_line(double x, double m, double q);

#endif // HELPER_H

