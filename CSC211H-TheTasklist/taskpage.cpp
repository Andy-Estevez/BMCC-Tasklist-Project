#include "taskpage.h"

TaskPage::TaskPage(QObject *parent)
    : QObject{parent}
{}

Category* TaskPage::createCategory(QFrame* bg, QLabel* header, QWidget* wid, QVBoxLayout* layout, QPushButton* btnAddList, QPushButton* btnSettings)
{
    Category* newCategory = new Category(bg, header, wid, layout, btnAddList, btnSettings);
    categories.push_back(newCategory);

    return newCategory;
}

void TaskPage::removeCurrentCategoryObj()
{
    int index = categories.indexOf(curCategoryObj);

    if (index != -1)
    {
        delete categories.at(index);
        categories.remove(index);
    }
}

// Accessor & Mutator Pairs

void TaskPage::setCurTabWidget(QWidget* wid)
{
    curTabWidget = wid;
}

QWidget* TaskPage::getCurTabWidget()
{
    return curTabWidget;
}

void TaskPage::setCurCategoryObj(Category* obj)
{
    curCategoryObj = obj;
}

Category* TaskPage::getCurCategoryObj()
{
    return curCategoryObj;
}

void TaskPage::setCurListObj(List* obj)
{
    curListObj = obj;
}

List* TaskPage::getCurListObj()
{
    return curListObj;
}

void TaskPage::setCurTaskObj(TaskAcademic* obj)
{
    curTaskObj = obj;
}

TaskAcademic* TaskPage::getCurTaskObj()
{
    return curTaskObj;
}

QString TaskPage::compileData()
{
    QString data = "";

    for (int i = 0; i < categories.size(); i++)
    {
        data += "Category{\n";
        data += categories.at(i)->compileCategoryData();
        data += "}\n";
    }

    return data;
}
