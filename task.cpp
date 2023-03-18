#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{

}

void Task::printMessage()
{
    qDebug()<<"You send str: empty";
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
    emit stop();
}
