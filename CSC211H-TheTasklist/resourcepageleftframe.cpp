#include "resourcepageleftframe.h"

// Constructor
ResourcePageLeftFrame::ResourcePageLeftFrame(QObject *parent)
    : QObject{parent}
{}

// Set Current Button Pointer
void ResourcePageLeftFrame::setCurButton(QPushButton* curButton)
{
    curButtonP = curButton;
}

// Return Current Button Pointer
QPushButton* ResourcePageLeftFrame::getCurButton()
{
    return curButtonP;
}
