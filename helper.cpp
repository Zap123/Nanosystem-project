#include <QFile>
#include <QStringList>
#include <QDebug>

void parseASCII(){
    QFile file(":/test/testASCII.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error:" << file.errorString();
    }


    QStringList wordList;
    while(!file.atEnd()){
        QByteArray line = file.readLine();
        wordList.append(line.split(' ').first());

    }

    qDebug() << "Parsed:" << wordList;
}
