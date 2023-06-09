#include <QApplication>
#include <QCoreApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale loc(QLocale("C"));
    QLocale().setDefault(loc);
    MainWindow w;
    w.show();
    return a.exec();
}
