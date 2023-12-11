#ifndef TASKPAGE_H
#define TASKPAGE_H

#include <QObject>
#include "category.h"
#include "list.h"
#include "task.h"
#include "qframe.h"
#include "qlabel.h"
#include "qboxlayout.h"
#include "qpushbutton.h"

class TaskPage : public QObject
{
    Q_OBJECT

private:
    QWidget* curTabWidget;
    Category* curCategoryObj;
    List* curListObj;
    TaskAcademic* curTaskObj;

    QVector <Category*> categories;

public:
    explicit TaskPage(QObject *parent = nullptr);

    Category* createCategory(QFrame*, QLabel*, QWidget*, QVBoxLayout*, QPushButton*, QPushButton*);
    void removeCurrentCategoryObj();

    void setCurTabWidget(QWidget*);
    QWidget* getCurTabWidget();

    void setCurCategoryObj(Category*);
    Category* getCurCategoryObj();

    void setCurListObj(List*);
    List* getCurListObj();

    void setCurTaskObj(TaskAcademic*);
    TaskAcademic* getCurTaskObj();

    QString compileData();
};

#endif // TASKPAGE_H
