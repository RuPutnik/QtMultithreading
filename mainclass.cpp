#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread(parent);
    tsk=new Task();

    tsk->moveToThread(taskThread);

    connect(taskThread, &QThread::started,tsk,         &Task::printMessage,     Qt::DirectConnection);
    connect(tsk,        &Task::stop,taskThread,        &QThread::quit,          Qt::QueuedConnection);
    connect(taskThread, &QThread::finished,taskThread, &QThread::deleteLater,   Qt::QueuedConnection);
    connect(taskThread, &QThread::finished,this,       &QCoreApplication::quit, Qt::QueuedConnection);

}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    taskThread->start();
}

