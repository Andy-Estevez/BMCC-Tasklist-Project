#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "resourcepageleftframe.h"
#include "taskpage.h"
#include "category.h"
#include "list.h"
#include "task.h"
#include "taskacademic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    ResourcePageLeftFrame RPLeftFrame;
    TaskPage taskPage;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void returnToTab();

    void loadData();
    void saveData();

private slots:
    void on_TasksButton_clicked();

    void on_ResourcesButton_clicked();

    void on_RPTasksButton_clicked();

    void on_TPResourcesButton_clicked();

    void on_RPStudyTechButton_clicked();

    void on_RPStressMngmtButton_clicked();

    void on_RPSleepButton_clicked();

    void on_RPBMCCResourcesButton_clicked();

    void on_TPAddCategoryButton_clicked();

    void on_ACMenuTabCancelButton_clicked();

    void on_ACMenuTabCreateCategoryButton_clicked();

    void openAddListMenuSlot();

    void openCategorySettingsMenuSlot();

    void on_ECMenuTabDeleteCategoryButton_clicked();

    void on_ECMenuTabCancelButton_clicked();

    void on_ECMenuTabSaveChangesButton_clicked();

    void on_ALMenuTabCancelButton_clicked();

    void on_ALMenuTabCreateListButton_clicked();

    void openAddTaskMenuSlot();

    void openListSettingsMenuSlot();

    void openTabSlot();

    void updateCurCategory(Category* categObj);

    void on_ELMenuTabDeleteListButton_clicked();

    void on_ELMenuTabSaveChangesButton_clicked();

    void on_ELMenuTabCancelButton_clicked();

    void on_ATMenuTabCancelButton_clicked();

    void on_ATMenuTabCreateTaskButton_clicked();

    void openTaskSettingsTabSlot();

    void on_ETMenuTabCancelButton_clicked();

    void on_ETMenuTabDeleteTaskButton_clicked();

    void on_ETMenuTabSaveChangesButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
