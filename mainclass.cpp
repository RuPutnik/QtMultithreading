#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread();
    tsk=new Task();

    tsk->moveToThread(taskThread);
    connect(this, &MainClass::sendMessage,tsk,&Task::printMessage);//connect default
}

void MainClass::runTest()
{
    taskThread->start();
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    emit sendMessage("I'm a message");
    taskThread->wait();

    exit(0);
}
