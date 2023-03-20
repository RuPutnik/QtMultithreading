#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{

}

void Task::printMessage(QString str)
{
    qDebug()<<"You send str: "<<str;
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
}

void Task::printSingleMessage(QString str)
{
    qDebug()<<"This is single-shot slot: "<<str;
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
    qDebug()<<"--You send str: "<<str;
}

void Task::exitThread()
{
    QThread::currentThread()->quit();
}
