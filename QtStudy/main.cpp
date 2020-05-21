#include <QApplication>
#include <stdio.h>
#include <stdlib.h>

#include "mainwindow.h"

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000, 810);
    w.show();
    return a.exec();
}


