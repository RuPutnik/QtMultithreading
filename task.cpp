#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{}

void Task::printMessage(QString str)
{
    qDebug()<<"You send str: "<<str;
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
}

int Task::getSumm(QVector<int> qvec)
{
    return std::accumulate(std::begin(qvec),std::end(qvec),0);
}


