#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{

}
//ЗАПУСКА QEVENTLOOP НЕ БУДЕТ, но для отправки сигналов он и не нужен
void Task::run()
{
    printMessage("blablabla");
}

void Task::printMessage(QString str)
{
    mut.lock();
    qDebug()<<"You send str: "<<str;
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
    mut.unlock();
    QThread::currentThread()->sleep(2);
    emit finished();
}
