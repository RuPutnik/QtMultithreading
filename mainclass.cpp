#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{

    tsk=new Task();
    //по хорошему нужно ловить сигнал от Task, что метод закончил работу и по этому сигналу выключать основной поток.
    //поток Task и так закончится,т.к. там нет цикла событий
}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    tsk->start();
    tsk->wait();
    exit(0);
}
