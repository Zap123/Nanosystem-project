#ifndef HELPER_H
#define HELPER_H

void test_parseASCII(QVector<double> *x_v, QVector<double> *y_i);
void parseASCII(QVector<double> *x_v, QVector<double> *y_i, QByteArray *q);

QVector<double> calibration_parameter(const QVector<double> *x_v, const QVector<double> *y_i);

QVector<double> least_square(const QVector<double> *x_v, const QVector<double> *y_i);


double cal_line(double x, double m, double q);

#endif // HELPER_H

