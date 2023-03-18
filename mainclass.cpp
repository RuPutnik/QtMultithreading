#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread();
    tsk=new Task();

#define TypeConnect 0

#if TypeConnect==0
    tsk->moveToThread(taskThread);
    connect(this, &MainClass::sendMessage,tsk,&Task::printMessage);//connect default Qt::AutoConnection
#elif TypeConnect==1
    tsk->moveToThread(taskThread);
    connect(this, &MainClass::sendMessage,tsk,&Task::printMessage, Qt::DirectConnection);//выполнится в основном потоке
#elif TypeConnect==2
    //tsk->moveToThread(taskThread);
    connect(this, &MainClass::sendMessage,tsk,&Task::printMessage, Qt::QueuedConnection);//Не выполнится (т.к. нет запуска потока) и прога зависнет, т.к. не вызовется метод
    //завершгения потока, находящаяся в данном слоте
#endif
}

void MainClass::runTest()
{
    taskThread->start();//если закомментить, то сигналы с коннектком Qt::QueuedConnection просто не выполнятся, а Qt::DirectConnection выполнятся
    //в основном потоке
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    emit sendMessage("I'm a message");
    taskThread->wait();

    exit(0);
}
