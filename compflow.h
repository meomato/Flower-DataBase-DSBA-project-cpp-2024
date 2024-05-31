#ifndef COMPFLOW_H
#define COMPFLOW_H

#include <QWidget>
#include "flowercontainer.h"

namespace Ui {
class CompFlow;
}

class CompFlow : public QWidget
{
    Q_OBJECT

public:
    explicit CompFlow(QWidget *parent = nullptr);
    ~CompFlow();

    void setCompVector(QVector<FlowerContainer*> fcCompVector);
    void clearWidgets();

private:
    Ui::CompFlow *ui;
};

#endif // COMPFLOW_H
