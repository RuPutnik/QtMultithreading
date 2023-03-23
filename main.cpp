#include <QCoreApplication>
#include "mainclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainClass mcl;
    mcl.runTest();
    return a.exec(); //Запускаем цикл событий, без которых прием и обработка сигналов невозможна
}
