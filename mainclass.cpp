#include "mainclass.h"

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    tsk=new Task();
}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    QFuture<void> fv=QtConcurrent::run(&Task::printMessage,tsk,"hello");

    qDebug()<<"Parallel";

    fv.waitForFinished();
    exit(0);
}
