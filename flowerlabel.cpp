#include "flowerlabel.h"
#include <iostream>

FlowerLabel::FlowerLabel(QWidget *parent): QLabel{parent}
{
    installEventFilter(this);
}

bool FlowerLabel::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        emit click();
    }
    return false;
}
