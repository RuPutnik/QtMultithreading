#include "task.h"

Task::Task(QObject *parent)
{

}

void Task::run()
{
    qDebug()<<"Start thread..";
    printMessage("Message from RUN");
    //quit();
}

void Task::printMessage(QString str)
{
    qDebug()<<"You send str: "<<str;
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
}
