#include <QCoreApplication>
#include "mainclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainClass mcls;
    mcls.runTest();
    return a.exec();
}
