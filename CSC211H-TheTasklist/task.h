#ifndef TASK_H
#define TASK_H

#include <QObject>
#include "qframe.h"
#include "qlabel.h"
#include "qpushbutton.h"

class Task : public QObject
{
    Q_OBJECT

protected:
    bool taskCompletion = false;

    QFrame* taskBG;
    QLabel* taskHeader;
    QLabel* taskProgress;
    QPushButton* taskSettingsButton;

public:
    explicit Task(QFrame*, QLabel*, QLabel*, QPushButton*, QObject *parent = nullptr);
    ~Task();

    void setTaskCompletion(bool);
    bool getTaskCompletion();

    QFrame* getTaskBG();
    QLabel* getTaskHeader();
    QLabel* getTaskProgress();
    QPushButton* getTaskSettingsButton();

    virtual QString compileTaskData();
};

#endif // TASK_H
