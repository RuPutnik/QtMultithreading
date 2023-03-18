#include <QCoreApplication>
#include "mainclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1");
    MainClass mcls;
    mcls.runTest();
    return a.exec();
}
