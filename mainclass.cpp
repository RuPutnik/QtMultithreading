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
    QFuture<int> fv1=QtConcurrent::run(&Task::getSumm,tsk,QVector<int>{1,5,8,34});
    QFuture fv2=QtConcurrent::task(&Task::getMultiples<int>).withArguments(tsk,QVector<int>{1,2,3,4}).spawn();

    qDebug()<<"Parallel";

    fv.waitForFinished();
    fv1.waitForFinished();
    fv2.waitForFinished();

    qDebug()<<fv1.result();
    qDebug()<<fv2.result();

    for(auto v:fv1){
        qDebug()<<"V: "<<v;
    }

    exit(0);
}
