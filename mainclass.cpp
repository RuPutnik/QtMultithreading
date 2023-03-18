#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread();
    tsk=new Task();

    connect(taskThread,&QThread::started,tsk,&Task::printMessage);
    connect(tsk,&Task::stop,taskThread,&QThread::quit,Qt::DirectConnection);  //похоже, сигнал приходит уже в основной поток и есть не указать явно Qt::DirectConnection
    //то работать не будет.
    connect(tsk,&Task::stop,taskThread,&QThread::deleteLater,Qt::DirectConnection);
    tsk->moveToThread(taskThread);
}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    taskThread->start();
    taskThread->wait();

    exit(0);
}
