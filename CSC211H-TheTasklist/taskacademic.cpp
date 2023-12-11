#include "taskacademic.h"

TaskAcademic::TaskAcademic(QFrame* bg, QLabel* header, QLabel* date, QLabel* prog, QPushButton* btnSettings)
    : Task(bg, header, prog, btnSettings)
{
    taskDueDate = date;
}

QLabel* TaskAcademic::getTaskDueDate()
{
    return taskDueDate;
}

QString TaskAcademic::compileTaskData()
{
    QString data = taskHeader->text() + "\n";
    data += taskDueDate->text() + "\n";
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

// Signals / Slots

void TaskAcademic::taskSettingButtonClicked()
{
    emit openTaskSettingsTab();
}
