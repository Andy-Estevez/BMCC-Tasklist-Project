#ifndef LIST_H
#define LIST_H

#include <QObject>
#include "task.h"
#include "taskacademic.h"
#include "qwidget.h"
#include "qlabel.h"
#include "qboxlayout.h"
#include "qpushbutton.h"

class List : public QObject
{
    Q_OBJECT

private:
    QWidget* listWidget;
    QLabel* listHeader;
    QWidget* taskScrollerWidget;
    QVBoxLayout* taskScrollerLayout;
    QPushButton* listSettingsButton;
    QPushButton* listAddTaskButton;
    QPushButton* listLeftButton;

    QVector <TaskAcademic*> tasks;

public:
    explicit List(QWidget*, QLabel*, QWidget*, QVBoxLayout*, QPushButton*, QPushButton*, QPushButton*, QObject *parent = nullptr);
    ~List();

    TaskAcademic* createTask(QFrame*, QLabel*, QLabel*, QLabel*, QPushButton*);
    void removeTaskObj(Task*);

    QWidget* getListWidget();
    QLabel* getListHeader();
    QWidget* getTaskScrollerWidget();
    QVBoxLayout* getTaskScrollerLayout();
    QPushButton* getListSettingsButton();
    QPushButton* getListAddTaskButton();
    QPushButton* getListLeftButton();

    QString compileListData();

    void listSettingsButtonClicked();
    void listAddTaskButtonClicked();
    void listLeftButtonClicked();

signals:
    void requestCategoryParent();

    void openListSettingsMenu();
    void openAddTaskMenu();
    void openTab();
};

#endif // LIST_H
