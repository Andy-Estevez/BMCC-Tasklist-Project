#ifndef RESOURCEPAGELEFTFRAME_H
#define RESOURCEPAGELEFTFRAME_H

#include <QObject>
#include "qpushbutton.h"

class ResourcePageLeftFrame : public QObject
{
    Q_OBJECT

private:
    QPushButton* curButtonP = nullptr;

public:
    explicit ResourcePageLeftFrame(QObject *parent = nullptr);

    void setCurButton(QPushButton*);

    QPushButton* getCurButton();
};

#endif // RESOURCEPAGELEFTFRAME_H
