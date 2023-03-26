#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    taskThread=new QThread(parent);
    tsk=new Task();

    tsk->moveToThread(taskThread);

    connect(taskThread, &QThread::started,              tsk,        &Task::printMessage,     Qt::DirectConnection);
    connect(tsk,        &Task::stop,                    taskThread, &QThread::quit,          Qt::QueuedConnection);
    connect(taskThread, &QThread::finished,             taskThread, &QThread::deleteLater,   Qt::QueuedConnection);
    connect(taskThread, &QThread::finished,             this,       &QCoreApplication::quit, Qt::QueuedConnection);
    connect(this,       &MainClass::sendPrintRectangle, tsk,        &Task::drawRectangle,    Qt::QueuedConnection);
}
//Доказали, что если поток выполняет свою работу путем коннекта слота к сигналу QThread::started, это не мешает нам еще и другие слоты коннектить
void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    taskThread->start();
    emit sendPrintRectangle(5,8);
}

