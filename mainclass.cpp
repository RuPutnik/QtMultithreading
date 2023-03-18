#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread();
    tsk=new Task();

    tsk->moveToThread(taskThread);
}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();

}
