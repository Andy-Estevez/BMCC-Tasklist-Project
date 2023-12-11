#include "task.h"

Task::Task(QFrame* bg, QLabel* header, QLabel* prog, QPushButton* btnSettings, QObject *parent)
    : QObject{parent}
{
    taskBG = bg;
    taskHeader = header;
    taskProgress = prog;
    taskSettingsButton = btnSettings;
}

Task::~Task()
{
    qDebug() << "Task Destroyed";

    delete taskBG;
}

void Task::setTaskCompletion(bool state)
{
    taskCompletion = state;
}

bool Task::getTaskCompletion()
{
    return taskCompletion;
}

QFrame* Task::getTaskBG()
{
    return taskBG;
}

QLabel* Task::getTaskHeader()
{
    return taskHeader;
}

QLabel* Task::getTaskProgress()
{
    return taskProgress;
}

QPushButton* Task::getTaskSettingsButton()
{
    return taskSettingsButton;
}

QString Task::compileTaskData()
{
    QString data = taskHeader->text() + "\n";
    data += taskProgress->text() + "\n";

    if (taskCompletion == true)
    {
        data += "complete\n";
    }
    else
    {
        data += "incomplete\n";
    }

    return data;
}
