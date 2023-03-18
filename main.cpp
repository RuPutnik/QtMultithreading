#include <QCoreApplication>
#include "mainclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainClass mncl;
    mncl.runTest();
    return a.exec();
}
