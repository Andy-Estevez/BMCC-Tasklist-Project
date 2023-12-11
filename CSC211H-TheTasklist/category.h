#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include "list.h"
#include "qframe.h"
#include "qlabel.h"
#include "qboxlayout.h"
#include "qpushbutton.h"

class Category : public QObject
{
    Q_OBJECT

private:
    QFrame* categoryBG;
    QLabel* categoryHeader;
    QWidget* listScrollerWidget;
    QVBoxLayout* listScrollerLayout;
    QPushButton* categorySettingsButton;
    QPushButton* categoryAddListButton;

    QVector <List*> lists;

public:
    explicit Category(QFrame*, QLabel*, QWidget*, QVBoxLayout*, QPushButton*, QPushButton*, QObject *parent = nullptr);
    ~Category();

    List* createList(QWidget*, QLabel*, QWidget*, QVBoxLayout*, QPushButton*, QPushButton*, QPushButton*);
    void removeListObj(List*);

    QFrame* getCategoryBG();
    QLabel* getCategoryHeader();
    QWidget* getListScrollerWidget();
    QVBoxLayout* getListScrollerLayout();
    QPushButton* getCategorySettingsButton();
    QPushButton* getCategoryAddListButton();

    QString compileCategoryData();

    void returnSelfSlot();

    void categorySettingsButtonClicked();
    void categoryAddListButtonClicked();

signals:
    void returnSelfSignal(Category* categObj);

    void openCategorySettingsMenu();
    void openAddListMenu();
};

#endif // CATEGORY_H
