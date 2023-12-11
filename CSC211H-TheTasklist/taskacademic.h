#ifndef TASKACADEMIC_H
#define TASKACADEMIC_H

#include <QObject>
#include "task.h"
#include "qframe.h"
#include "qlabel.h"
#include "qpushbutton.h"

class TaskAcademic : public Task
{
    Q_OBJECT

private:
    QLabel* taskDueDate;

public:
    explicit TaskAcademic(QFrame*, QLabel*, QLabel*, QLabel*, QPushButton*);

    QLabel* getTaskDueDate();

    QString compileTaskData() override;

    void taskSettingButtonClicked();

signals:
    void openTaskSettingsTab();
};

#endif // TASKACADEMIC_H
