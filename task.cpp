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
