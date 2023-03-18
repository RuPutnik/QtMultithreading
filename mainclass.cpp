#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{

    tsk=new Task();
}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    tsk->start();
    tsk->wait();
    exit(0);
}
