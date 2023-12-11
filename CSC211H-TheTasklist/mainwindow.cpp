#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init Screen
    ui->stackedWidget->setCurrentWidget(ui->StartUpPage);

    // Init Task Page
    ui->TPRFStackedWidget->setCurrentWidget(ui->DefaultTab);
    taskPage.setCurTabWidget(ui->DefaultTab);
    taskPage.setCurCategoryObj(nullptr);
    taskPage.setCurListObj(nullptr);
    taskPage.setCurTaskObj(nullptr);

    // Init Resource Page
    ui->RPRFStackedWidget->setCurrentWidget(ui->StudyingTechPage);
    RPLeftFrame.setCurButton(ui->RPStudyTechButton);

    //loadData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// On Main Window Closing
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveData();

    event->accept();
}

// Return To Previous Tab
void MainWindow::returnToTab()
{
    ui->TPRFStackedWidget->setCurrentWidget(taskPage.getCurTabWidget());

    // Activates Menu Bar & Directory Buttons
    ui->TPMenuBar->setEnabled(true);
    ui->TPLeftFrame->setEnabled(true);
}

///////////////////
// Start-Up Page //
///////////////////

void MainWindow::on_TasksButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TaskPage);
}

void MainWindow::on_ResourcesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ResourcePage);
}

///////////////////
// Resource Page //
///////////////////

/// Menu Bar

void MainWindow::on_RPTasksButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TaskPage);
}

/// Left Frame (Directory)

void MainWindow::on_RPStudyTechButton_clicked()
{
    // Disable Studying Techniques Button
    ui->RPStudyTechButton->setEnabled(false);
    ui->RPStudyTechButton->setStyleSheet("background-color: rgb(150, 150, 150); color: rgb(100, 100, 100);");

    // Open Studying Techniques Tab
    ui->RPRFStackedWidget->setCurrentWidget(ui->StudyingTechPage);

    // Re-Enable Previous Button
    QString objName = RPLeftFrame.getCurButton()->objectName();
    RPLeftFrame.getCurButton()->setEnabled(true);
    RPLeftFrame.getCurButton()->setStyleSheet("QPushButton#"+objName+" {background-color: rgb(215, 215, 215); color: dark-gray;}"
                                              "QPushButton:hover#"+objName+" {background-color: rgb(180, 180, 180);}");

    RPLeftFrame.setCurButton(ui->RPStudyTechButton);
}

void MainWindow::on_RPStressMngmtButton_clicked()
{
    // Disable Stress Management Button
    ui->RPStressMngmtButton->setEnabled(false);
    ui->RPStressMngmtButton->setStyleSheet("background-color: rgb(150, 150, 150); color: rgb(100, 100, 100);");

    // Open Stress Management Tab
    ui->RPRFStackedWidget->setCurrentWidget(ui->StressMngmtPage);

    // Re-Enable Previous Button
    QString objName = RPLeftFrame.getCurButton()->objectName();
    RPLeftFrame.getCurButton()->setEnabled(true);
    RPLeftFrame.getCurButton()->setStyleSheet("QPushButton#"+objName+" {background-color: rgb(215, 215, 215); color: dark-gray;}"
                                              "QPushButton:hover#"+objName+" {background-color: rgb(180, 180, 180);}");

    RPLeftFrame.setCurButton(ui->RPStressMngmtButton);
}

void MainWindow::on_RPSleepButton_clicked()
{
    // Disable Sleep Health Button
    ui->RPSleepButton->setEnabled(false);
    ui->RPSleepButton->setStyleSheet("background-color: rgb(150, 150, 150); color: rgb(100, 100, 100);");

    // Open Sleep Health Tab
    ui->RPRFStackedWidget->setCurrentWidget(ui->SleepHealthPage);

    // Re-Enable Previous Button
    QString objName = RPLeftFrame.getCurButton()->objectName();
    RPLeftFrame.getCurButton()->setEnabled(true);
    RPLeftFrame.getCurButton()->setStyleSheet("QPushButton#"+objName+" {background-color: rgb(215, 215, 215); color: dark-gray;}"
                                              "QPushButton:hover#"+objName+" {background-color: rgb(180, 180, 180);}");

    RPLeftFrame.setCurButton(ui->RPSleepButton);
}

void MainWindow::on_RPBMCCResourcesButton_clicked()
{
    // Disable BMCC Resources Button
    ui->RPBMCCResourcesButton->setEnabled(false);
    ui->RPBMCCResourcesButton->setStyleSheet("background-color: rgb(150, 150, 150); color: rgb(100, 100, 100);");

    // Open BMCC Resources Tab
    ui->RPRFStackedWidget->setCurrentWidget(ui->BMCCResourcesPage);

    // Re-Enable Previous Button
    QString objName = RPLeftFrame.getCurButton()->objectName();
    RPLeftFrame.getCurButton()->setEnabled(true);
    RPLeftFrame.getCurButton()->setStyleSheet("QPushButton#"+objName+" {background-color: rgb(215, 215, 215); color: dark-gray;}"
                                              "QPushButton:hover#"+objName+" {background-color: rgb(180, 180, 180);}");

    RPLeftFrame.setCurButton(ui->RPBMCCResourcesButton);
}

///////////////
// Task Page //
///////////////

/// Menu Bar

// Resource Button Functionality
void MainWindow::on_TPResourcesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ResourcePage);
}

/// Content

// Open Category Adder Menu
void MainWindow::on_TPAddCategoryButton_clicked()
{
    ui->TPMenuBar->setEnabled(false);
    ui->TPLeftFrame->setEnabled(false);

    ui->TPRFStackedWidget->setCurrentWidget(ui->AddCategoryMenuTab);
}

// Category Adder Menu: Cancel
void MainWindow::on_ACMenuTabCancelButton_clicked()
{
    returnToTab();
}

// Category Adder Menu: Create Category
void MainWindow::on_ACMenuTabCreateCategoryButton_clicked()
{
    QVBoxLayout* categScrollerLayout = qobject_cast<QVBoxLayout*>(ui->TPCategScrollAreaWidgetContents->layout());

    QFrame* newFrame = new QFrame(ui->TPCategScrollAreaWidgetContents);
    newFrame->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    newFrame->setMinimumSize(80, 278);
    newFrame->setStyleSheet("background-color: rgb(60, 60, 60);");
    newFrame->setFrameShape(QFrame::StyledPanel);
    newFrame->setFrameShadow(QFrame::Raised);

    QVBoxLayout* newVLayout = new QVBoxLayout(newFrame);

    QLabel* newLabel = new QLabel(newFrame);
    newLabel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newLabel->setMinimumSize(120, 40);
    newLabel->setStyleSheet("background-color: transparent; color: rgb(215, 215, 215);");
    newLabel->setAlignment(Qt::AlignCenter);

    QFont* newFont = new QFont();
    newFont->setPointSize(14);
    newFont->setBold(true);

    newLabel->setFont(*newFont);

    QString categoryName;

    if (ui->ACMenuTabLineEdit->text() == "")
    {
        categoryName = tr("My Category #%1").arg(categScrollerLayout->count());
    }
    else
    {
        categoryName = ui->ACMenuTabLineEdit->text();
    }

    newLabel->setText(categoryName);

    QScrollArea* newScrollArea = new QScrollArea(newFrame);
    newScrollArea->setStyleSheet("background-color: rgb(80, 80, 80)");
    newScrollArea->setWidgetResizable(true);

    QWidget* newScrollCentral = new QWidget;
    newScrollArea->setWidget(newScrollCentral);

    QVBoxLayout* newVLayout2 = new QVBoxLayout(newScrollCentral);
    newVLayout2->setSpacing(9);

    QHBoxLayout* newHLayout = new QHBoxLayout();
    newVLayout2->addLayout(newHLayout);

    QPushButton* newButton = new QPushButton("Add List", newScrollCentral);
    newButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newButton->setMinimumSize(80, 40);
    newButton->setProperty("class", "adderButton");
    newButton->setStyleSheet(".adderButton {background-color: rgb(95, 95, 95); color: rgb(215, 215, 215);"
                             "border-width: 2px; border-style: solid; border-color: rgb(215, 215, 215);}"
                             ".adderButton:hover {background-color: rgb(110, 110, 110);}");

    QCursor* newCursor = new QCursor();
    newCursor->setShape(Qt::PointingHandCursor);

    newFont->setPointSize(11);

    newButton->setFont(*newFont);
    newButton->setCursor(*newCursor);

    QPushButton* newButton2 = new QPushButton("Settings", newScrollCentral);
    newButton2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newButton2->setMinimumSize(80, 40);
    newButton2->setFont(*newFont);
    newButton2->setCursor(*newCursor);
    newButton2->setProperty("class", "settingsButton");
    newButton2->setStyleSheet(".settingsButton {background-color: rgb(215, 215, 215); color: dark-gray;}"
                              ".settingsButton:hover {background-color: rgb(180, 180, 180);}");

    QSpacerItem* newSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    newVLayout->addWidget(newLabel);
    newVLayout->addWidget(newScrollArea);
    newHLayout->addWidget(newButton);
    newHLayout->addWidget(newButton2);
    newVLayout2->addSpacerItem(newSpacer);

    categScrollerLayout->insertWidget(categScrollerLayout->count(), newFrame);

    Category* categoryObjP = taskPage.createCategory(newFrame, newLabel, newScrollCentral, newVLayout2, newButton, newButton2);

    QObject::connect(newButton, &QPushButton::clicked, categoryObjP, &Category::categoryAddListButtonClicked);
    QObject::connect(newButton2, &QPushButton::clicked, categoryObjP, &Category::categorySettingsButtonClicked);

    QObject::connect(categoryObjP, &Category::openAddListMenu, this, &MainWindow::openAddListMenuSlot);
    QObject::connect(categoryObjP, &Category::openCategorySettingsMenu, this, &MainWindow::openCategorySettingsMenuSlot);

    delete newFont;
    delete newCursor;

    ui->ACMenuTabLineEdit->setText("");

    returnToTab();
}

// Open Category Settings Menu
void MainWindow::openCategorySettingsMenuSlot()
{
    ui->TPMenuBar->setEnabled(false);
    ui->TPLeftFrame->setEnabled(false);

    ui->TPRFStackedWidget->setCurrentWidget(ui->EditCategoryMenuTab);

    taskPage.setCurCategoryObj(qobject_cast<Category*>(sender()));
    taskPage.setCurListObj(nullptr);

    ui->ECMenuTabLineEdit->setText(taskPage.getCurCategoryObj()->getCategoryHeader()->text());
}

// Category Settings Menu: Delete
void MainWindow::on_ECMenuTabDeleteCategoryButton_clicked()
{
    taskPage.removeCurrentCategoryObj();

    taskPage.setCurCategoryObj(nullptr);

    ui->ECMenuTabLineEdit->setText("");

    taskPage.setCurTabWidget(ui->DefaultTab);
    returnToTab();
}

// Category Settings Menu: Cancel
void MainWindow::on_ECMenuTabCancelButton_clicked()
{
    taskPage.setCurCategoryObj(nullptr);

    ui->ECMenuTabLineEdit->setText("");

    taskPage.setCurTabWidget(ui->DefaultTab);
    returnToTab();
}

// Category Settings Menu: Save Changes
void MainWindow::on_ECMenuTabSaveChangesButton_clicked()
{
    taskPage.getCurCategoryObj()->getCategoryHeader()->setText(ui->ECMenuTabLineEdit->text());

    taskPage.setCurCategoryObj(nullptr);

    ui->ECMenuTabLineEdit->setText("");

    taskPage.setCurTabWidget(ui->DefaultTab);
    returnToTab();
}

// Open List Adder Menu
void MainWindow::openAddListMenuSlot()
{
    ui->TPMenuBar->setEnabled(false);
    ui->TPLeftFrame->setEnabled(false);

    ui->TPRFStackedWidget->setCurrentWidget(ui->AddListMenuTab);

    taskPage.setCurCategoryObj(qobject_cast<Category*>(sender()));
    taskPage.setCurListObj(nullptr);
}

// List Adder Menu: Cancel
void MainWindow::on_ALMenuTabCancelButton_clicked()
{
    taskPage.setCurCategoryObj(nullptr);

    ui->ALMenuTabLineEdit->setText("");

    taskPage.setCurTabWidget(ui->DefaultTab);
    returnToTab();
}

// List Adder Menu: Create List
void MainWindow::on_ALMenuTabCreateListButton_clicked()
{
    QVBoxLayout* listScrollerLayout = taskPage.getCurCategoryObj()->getListScrollerLayout();

    QWidget* newWidget = new QWidget;

    ui->TPRFStackedWidget->addWidget(newWidget);

    QVBoxLayout* newVLayout = new QVBoxLayout(newWidget);
    newVLayout->setSpacing(9);

    QLabel* newLabel = new QLabel(newWidget);
    newLabel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newLabel->setMinimumSize(120, 40);
    newLabel->setStyleSheet("background-color: rgb(80, 80, 80); color: rgb(215, 215, 215);");
    newLabel->setAlignment(Qt::AlignCenter);

    QFont* newFont = new QFont;
    newFont->setPointSize(15);
    newFont->setBold(true);

    newLabel->setFont(*newFont);

    QString listName;

    if (ui->ALMenuTabLineEdit->text() == "")
    {
        listName = tr("My List #%1").arg(listScrollerLayout->count() - 1);
    }
    else
    {
        listName = ui->ALMenuTabLineEdit->text();
    }

    newLabel->setText(listName);

    QScrollArea* newScrollArea = new QScrollArea(newWidget);
    newScrollArea->setStyleSheet("background-color: rgb(80, 80, 80)");
    newScrollArea->setWidgetResizable(true);

    QWidget* newScrollCentral = new QWidget;
    newScrollArea->setWidget(newScrollCentral);

    QVBoxLayout* newVLayout2 = new QVBoxLayout(newScrollCentral);
    newVLayout2->setSpacing(9);

    QHBoxLayout* newHLayout = new QHBoxLayout();
    newVLayout2->addLayout(newHLayout);

    QPushButton* newButton = new QPushButton("Add Task", newScrollCentral);
    newButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newButton->setMinimumSize(80, 40);
    newButton->setProperty("class", "adderButton");
    newButton->setStyleSheet(".adderButton {background-color: rgb(95, 95, 95); color: rgb(215, 215, 215);"
                             "border-width: 2px; border-style: solid; border-color: rgb(215, 215, 215);}"
                             ".adderButton:hover {background-color: rgb(110, 110, 110);}");

    QCursor* newCursor = new QCursor();
    newCursor->setShape(Qt::PointingHandCursor);

    newFont->setPointSize(11);

    newButton->setFont(*newFont);
    newButton->setCursor(*newCursor);

    QPushButton* newButton2 = new QPushButton("Settings", newScrollCentral);
    newButton2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newButton2->setMinimumSize(80, 40);
    newButton2->setFont(*newFont);
    newButton2->setCursor(*newCursor);
    newButton2->setProperty("class", "settingsButton");
    newButton2->setStyleSheet(".settingsButton {background-color: rgb(215, 215, 215); color: dark-gray;}"
                              ".settingsButton:hover {background-color: rgb(180, 180, 180);}");

    QSpacerItem* newSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    newVLayout->addWidget(newLabel);
    newVLayout->addWidget(newScrollArea);
    newHLayout->addWidget(newButton);
    newHLayout->addWidget(newButton2);
    newVLayout2->addSpacerItem(newSpacer);

    QPushButton* newButton3 = new QPushButton(listName, taskPage.getCurCategoryObj()->getListScrollerWidget());
    newButton3->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newButton3->setMinimumSize(80, 43);
    newButton3->setFont(*newFont);
    newButton3->setCursor(*newCursor);
    newButton3->setProperty("class", "listButton");
    newButton3->setStyleSheet(".listButton {background-color: rgb(60, 60, 60); color: rgb(215, 215, 215);"
                              "border-width: 2px; border-style: solid; border-color: rgb(215, 215, 215);}"
                              ".listButton:hover {background-color: rgb(75, 75, 75);}");

    listScrollerLayout->insertWidget(listScrollerLayout->count() - 1, newButton3);

    List* listObjP = taskPage.getCurCategoryObj()->createList(newWidget, newLabel, newScrollCentral, newVLayout2, newButton, newButton2, newButton3);

    QObject::connect(newButton, &QPushButton::clicked, listObjP, &List::listAddTaskButtonClicked);
    QObject::connect(newButton2, &QPushButton::clicked, listObjP, &List::listSettingsButtonClicked);
    QObject::connect(newButton3, &QPushButton::clicked, listObjP, &List::listLeftButtonClicked);

    QObject::connect(listObjP, &List::openAddTaskMenu, this, &MainWindow::openAddTaskMenuSlot);
    QObject::connect(listObjP, &List::openListSettingsMenu, this, &MainWindow::openListSettingsMenuSlot);
    QObject::connect(listObjP, &List::openTab, this, &MainWindow::openTabSlot);

    Category* curCategoryObj = taskPage.getCurCategoryObj();

    QObject::connect(listObjP, &List::requestCategoryParent, curCategoryObj, &Category::returnSelfSlot);
    QObject::connect(curCategoryObj, &Category::returnSelfSignal, this, &MainWindow::updateCurCategory);

    delete newFont;
    delete newCursor;

    ui->ALMenuTabLineEdit->setText("");

    taskPage.setCurListObj(listObjP);

    taskPage.setCurTabWidget(newWidget);
    ui->TPRFStackedWidget->setCurrentWidget(newWidget);

    ui->TPMenuBar->setEnabled(true);
    ui->TPLeftFrame->setEnabled(true);
}

void MainWindow::updateCurCategory(Category* categObj)
{
    taskPage.setCurCategoryObj(categObj);
}

void MainWindow::openTabSlot()
{
    List* curListObj = qobject_cast<List*>(sender());

    taskPage.setCurListObj(curListObj);
    emit curListObj->requestCategoryParent();

    taskPage.setCurTabWidget(curListObj->getListWidget());
    ui->TPRFStackedWidget->setCurrentWidget(curListObj->getListWidget());
}

void MainWindow::openListSettingsMenuSlot()
{
    ui->TPMenuBar->setEnabled(false);
    ui->TPLeftFrame->setEnabled(false);

    ui->TPRFStackedWidget->setCurrentIndex(4);

    ui->ELMenuTabLineEdit->setText(taskPage.getCurListObj()->getListHeader()->text());
}

void MainWindow::on_ELMenuTabDeleteListButton_clicked()
{
    taskPage.getCurCategoryObj()->removeListObj(taskPage.getCurListObj());

    taskPage.setCurListObj(nullptr);
    taskPage.setCurCategoryObj(nullptr);

    ui->ELMenuTabLineEdit->setText("");

    taskPage.setCurTabWidget(ui->DefaultTab);

    returnToTab();
}

void MainWindow::on_ELMenuTabCancelButton_clicked()
{
    ui->ELMenuTabLineEdit->setText("");

    returnToTab();
}

void MainWindow::on_ELMenuTabSaveChangesButton_clicked()
{
    taskPage.getCurListObj()->getListHeader()->setText(ui->ELMenuTabLineEdit->text());
    taskPage.getCurListObj()->getListLeftButton()->setText(ui->ELMenuTabLineEdit->text());

    ui->ELMenuTabLineEdit->setText("");

    returnToTab();
}

// Open Task Adder Menu
void MainWindow::openAddTaskMenuSlot()
{
    ui->TPMenuBar->setEnabled(false);
    ui->TPLeftFrame->setEnabled(false);

    ui->TPRFStackedWidget->setCurrentIndex(5);
}

// Task Adder Menu: Cancel
void MainWindow::on_ATMenuTabCancelButton_clicked()
{
    ui->ATMenuTabLineEdit->setText("");

    returnToTab();
}

// Task Adder Menu: Create Task
void MainWindow::on_ATMenuTabCreateTaskButton_clicked()
{
    QWidget* taskScrollerWidget = taskPage.getCurListObj()->getTaskScrollerWidget();
    QVBoxLayout* taskScrollerLayout = qobject_cast<QVBoxLayout*>(taskPage.getCurListObj()->getTaskScrollerLayout());

    QFrame* newFrame = new QFrame(taskScrollerWidget);
    newFrame->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    newFrame->setMinimumSize(0, 278);
    newFrame->setStyleSheet("background-color: rgb(60, 60, 60); border-style: solid; border-width: 2px; border-color: red;");
    newFrame->setFrameShape(QFrame::StyledPanel);
    newFrame->setFrameShadow(QFrame::Raised);

    QVBoxLayout* newVLayout = new QVBoxLayout(newFrame);
    newVLayout->setSpacing(9);
    newFrame->setLayout(newVLayout);

    QLabel* newLabel = new QLabel(newFrame);
    newLabel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newLabel->setMinimumSize(120, 40);
    newLabel->setStyleSheet("background-color: rgb(70, 70, 70); color: rgb(215, 215, 215); border-color: transparent;");
    newLabel->setAlignment(Qt::AlignCenter);

    QFont* newFont = new QFont();
    newFont->setPointSize(14);
    newFont->setBold(true);

    newLabel->setFont(*newFont);

    QString taskName;

    if (ui->ATMenuTabLineEdit->text() == "")
    {
        taskName = tr("My Task #%1").arg(taskScrollerLayout->count() - 1);
    }
    else
    {
        taskName = ui->ATMenuTabLineEdit->text();
    }

    newLabel->setText(taskName);

    QLabel* newLabel2 = new QLabel(newFrame);
    newLabel2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    newLabel2->setMinimumSize(120, 20);
    newLabel2->setStyleSheet("background-color: transparent; color: rgb(215, 215, 215); border-color: transparent;");
    newLabel2->setAlignment(Qt::AlignLeft);
    newLabel2->setAlignment(Qt::AlignVCenter);
    newLabel2->setText("Due Date: " + ui->ATMenuTabTimeEdit->text());

    newFont->setPointSize(11);

    newLabel2->setFont(*newFont);

    QLabel* newLabel3 = new QLabel(newFrame);
    newLabel3->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    newLabel3->setMinimumSize(120, 20);
    newLabel3->setStyleSheet("background-color: transparent; color: rgb(215, 215, 215); border-color: transparent;");
    newLabel3->setAlignment(Qt::AlignLeft);
    newLabel3->setAlignment(Qt::AlignVCenter);
    newLabel3->setText("Progress: N/A");
    newLabel3->setFont(*newFont);

    QPushButton* newButton = new QPushButton("Settings", newFrame);
    newButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newButton->setMinimumSize(180, 40);
    newButton->setFont(*newFont);
    newButton->setProperty("class", "settingsButton");
    newButton->setStyleSheet(".settingsButton {background-color: rgb(215, 215, 215); color: dark-gray; border-color: transparent;}"
                             ".settingsButton:hover {background-color: rgb(180, 180, 180);}");

    QCursor* newCursor = new QCursor;
    newCursor->setShape(Qt::PointingHandCursor);

    newButton->setCursor(*newCursor);

    newVLayout->addWidget(newLabel);
    newVLayout->addWidget(newLabel2);
    newVLayout->addWidget(newLabel3);
    newVLayout->addWidget(newButton);

    TaskAcademic* taskObjP = taskPage.getCurListObj()->createTask(newFrame, newLabel, newLabel2, newLabel3, newButton);

    QObject::connect(newButton, &QPushButton::clicked, taskObjP, &TaskAcademic::taskSettingButtonClicked);

    QObject::connect(taskObjP, &TaskAcademic::openTaskSettingsTab, this, &MainWindow::openTaskSettingsTabSlot);

    taskScrollerLayout->insertWidget(taskScrollerLayout->count() - 1, newFrame);

    delete newFont;
    delete newCursor;

    ui->ATMenuTabLineEdit->setText("");

    returnToTab();
}

void MainWindow::openTaskSettingsTabSlot()
{
    ui->TPMenuBar->setEnabled(false);
    ui->TPLeftFrame->setEnabled(false);

    ui->TPRFStackedWidget->setCurrentIndex(6);

    taskPage.setCurTaskObj(qobject_cast<TaskAcademic*>(sender()));

    ui->ETMenuTabLineEdit->setText(taskPage.getCurTaskObj()->getTaskHeader()->text());
    ui->ETMenuTabCheckbox->setChecked(taskPage.getCurTaskObj()->getTaskCompletion());
}

void MainWindow::on_ETMenuTabCancelButton_clicked()
{
    taskPage.setCurTaskObj(nullptr);

    returnToTab();
}

void MainWindow::on_ETMenuTabDeleteTaskButton_clicked()
{
    taskPage.getCurListObj()->removeTaskObj(taskPage.getCurTaskObj());

    taskPage.setCurTaskObj(nullptr);

    returnToTab();
}

void MainWindow::on_ETMenuTabSaveChangesButton_clicked()
{
    taskPage.getCurTaskObj()->getTaskHeader()->setText(ui->ETMenuTabLineEdit->text());
    taskPage.getCurTaskObj()->getTaskDueDate()->setText("Due Date: " + ui->ETMenuTabTimeEdit->text());

    if (ui->ETMenuTabCheckbox->isChecked())
    {
        taskPage.getCurTaskObj()->getTaskBG()->setStyleSheet("background-color: rgb(60, 60, 60); border-style: solid; border-color: green; border-width: 2px;");
        taskPage.getCurTaskObj()->setTaskCompletion(true);
    }
    else
    {
        taskPage.getCurTaskObj()->getTaskBG()->setStyleSheet("background-color: rgb(60, 60, 60); border-style: solid; border-color: red; border-width: 2px;");
        taskPage.getCurTaskObj()->setTaskCompletion(false);
    }

    taskPage.setCurTaskObj(nullptr);

    returnToTab();
}

///////////////////
// Data Handling //
///////////////////

// INCOMPLETE
/*
void MainWindow::loadData()
{
    try
    {
        QFile dataFile("tasklistData.txt");

        if (dataFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream readFromFile(&dataFile);

            QString curLine;
            Category* curCateg;
            List* curList;
            TaskAcademic* curTask;

            while (!readFromFile.atEnd())
            {
                curLine = readFromFile.readLine();

                if (curLine == "Category{")
                {
                    QString categName = readFromFile.readLine();

                    // Create Category
                }
            }

            dataFile.flush();
            dataFile.close();
        }
        else
        {
            throw(tr("Data file could not be accessed.\n\nYou will not be able to load/save data."));
        }
    }
    catch(QString errorMsg)
    {
        QMessageBox::warning(this, "Error", errorMsg);
    }
}
*/

void MainWindow::saveData()
{
    try
    {
        QFile dataFile("tasklistData.txt");

        if (dataFile.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream writeToFile(&dataFile);

            writeToFile << taskPage.compileData();

            dataFile.flush();
            dataFile.close();
        }
        else
        {
            throw(tr("Data file could not be accessed.\n\nYou will not be able to save data."));
        }
    }
    catch(QString errorMsg)
    {
        QMessageBox::warning(this, "Error", errorMsg);
    }
}
