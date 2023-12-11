#include "list.h"

List::List(QWidget* wid, QLabel* header, QWidget* laywid, QVBoxLayout* layout, QPushButton* btnAddTask, QPushButton* btnSettings, QPushButton* btnLeft, QObject *parent)
    : QObject{parent}
{
    listWidget = wid;
    listHeader = header;
    taskScrollerWidget = laywid;
    taskScrollerLayout = layout;
    listAddTaskButton = btnAddTask;
    listSettingsButton = btnSettings;
    listLeftButton = btnLeft;
}

List::~List()
{
    qDebug() << "List Destroyed";

    for (int i = 0; i < tasks.size(); i++)
    {
        delete tasks.at(i);
    }

    tasks.clear();

    delete listWidget;
    delete listLeftButton;
}

TaskAcademic* List::createTask(QFrame* bg, QLabel* header, QLabel* date, QLabel* prog, QPushButton* btnSettings)
{
    TaskAcademic* newTask = new TaskAcademic(bg, header, date, prog, btnSettings);
    tasks.push_back(newTask);

    return newTask;
}

void List::removeTaskObj(Task* taskObjPtr)
{
    int index = tasks.indexOf(taskObjPtr);

    if (index != -1)
    {
        delete tasks.at(index);
        tasks.remove(index);
    }
}

// Accessors

QWidget* List::getListWidget()
{
    return listWidget;
}

QLabel* List::getListHeader()
{
    return listHeader;
}

QWidget* List::getTaskScrollerWidget()
{
    return taskScrollerWidget;
}

QVBoxLayout* List::getTaskScrollerLayout()
{
    return taskScrollerLayout;
}

QPushButton* List::getListSettingsButton()
{
    return listSettingsButton;
}

QPushButton* List::getListAddTaskButton()
{
    return listAddTaskButton;
}

QPushButton* List::getListLeftButton()
{
    return listLeftButton;
}

QString List::compileListData()
{
    QString data = listHeader->text() + "\n";

    for (int i = 0; i < tasks.size(); i++)
    {
        data += "Task{\n";
        data += tasks.at(i)->compileTaskData();
        data += "}\n";
    }

    return data;
}

// Signals/Slots

void List::listSettingsButtonClicked()
{
    emit openListSettingsMenu();
}

void List::listAddTaskButtonClicked()
{
    emit openAddTaskMenu();
}

void List::listLeftButtonClicked()
{
    emit openTab();
}
