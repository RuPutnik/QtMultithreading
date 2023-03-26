#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{

}

void Task::printMessage()
{
    qDebug()<<"You send str: empty";
    qDebug()<<"Thread address: "<<QThread::currentThreadId();

}

void Task::drawRectangle(int w, int h)
{
    qDebug()<<"You draw rect";
    qDebug()<<"Thread address: "<<QThread::currentThreadId();
    QDebug debug_wihout_newline=qDebug().nospace();
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            debug_wihout_newline<<"o";
        }
        debug_wihout_newline<<"\n";
    }
    emit stop();
}
