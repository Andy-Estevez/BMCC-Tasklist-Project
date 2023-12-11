#include "category.h"

Category::Category(QFrame* bg, QLabel* header, QWidget* wid, QVBoxLayout* layout, QPushButton* btnAddList, QPushButton* btnSettings, QObject *parent)
    : QObject{parent}
{
    categoryBG = bg;
    categoryHeader= header;
    listScrollerWidget = wid;
    listScrollerLayout = layout;
    categoryAddListButton = btnAddList;
    categorySettingsButton = btnSettings;
}

Category::~Category()
{
    qDebug() << "Category Destroyed";

    for (int i = 0; i < lists.size(); i++)
    {
        delete lists.at(i);
    }

    lists.clear();

    delete categoryBG;
}

List* Category::createList(QWidget* wid, QLabel* header, QWidget* laywid, QVBoxLayout* layout, QPushButton* btnAddTask, QPushButton* btnSettings, QPushButton* btnLeft)
{
    List* newList = new List(wid, header, laywid, layout, btnAddTask, btnSettings, btnLeft);
    lists.push_back(newList);

    return newList;
}

void Category::removeListObj(List* listObjPtr)
{
    int index = lists.indexOf(listObjPtr);

    if (index != -1)
    {
        delete lists.at(index);
        lists.remove(index);
    }
}

// Accessors

QFrame* Category::getCategoryBG()
{
    return categoryBG;
}

QLabel* Category::getCategoryHeader()
{
    return categoryHeader;
}

QWidget* Category::getListScrollerWidget()
{
    return listScrollerWidget;
}

QVBoxLayout* Category::getListScrollerLayout()
{
    return listScrollerLayout;
}

QPushButton* Category::getCategorySettingsButton()
{
    return categorySettingsButton;
}

QPushButton* Category::getCategoryAddListButton()
{
    return categoryAddListButton;
}

QString Category::compileCategoryData()
{
    QString data = categoryHeader->text() + "\n";

    for (int i = 0; i < lists.size(); i++)
    {
        data += "List{\n";
        data += lists.at(i)->compileListData();
        data += "}\n";
    }

    return data;
}

// Signals/Slots

void Category::returnSelfSlot()
{
    emit returnSelfSignal(this);
}

void Category::categorySettingsButtonClicked()
{
    emit openCategorySettingsMenu();
}

void Category::categoryAddListButtonClicked()
{
    emit openAddListMenu();
}
