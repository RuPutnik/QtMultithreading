#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread();
    tsk=new Task();

    tsk->moveToThread(taskThread);

    connect(this,       &MainClass::sendMessage,       tsk,  &Task::printMessage); //connect default
    connect(this,       &MainClass::sendSingleMessage, tsk,  &Task::printSingleMessage, (Qt::ConnectionType)(Qt::QueuedConnection|Qt::SingleShotConnection));
    connect(this,       &MainClass::closeThread,       tsk,  &Task::exitThread,         Qt::QueuedConnection);
    connect(taskThread, &QThread::finished,            this, QCoreApplication::quit);
}

void MainClass::runTest()
{
    taskThread->start();
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    emit sendMessage("I'm a message");
    emit sendMessage("I'm a message 1");
    emit sendMessage("I'm a message 2");

    emit sendSingleMessage("AAA");
    emit sendSingleMessage("BBB");
    emit sendSingleMessage("CCC");

    QThread::currentThread()->sleep(1);
    emit closeThread();
}
