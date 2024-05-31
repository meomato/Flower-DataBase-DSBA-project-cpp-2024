#ifndef FLOWERCARD_H
#define FLOWERCARD_H

#include <QWidget>
#include "flowercontainer.h"

namespace Ui {
class FlowerCard;
}

class FlowerCard : public QWidget
{
    Q_OBJECT

public:
    explicit FlowerCard(QWidget *parent = nullptr);
    ~FlowerCard();
    void setFlowContainer(FlowerContainer *p_fc);

private:
    Ui::FlowerCard *ui;
    QVector<FlowerCard*> vFlowerLabel{};
    FlowerContainer *fc{};
    FlowerLabel *sliderFl{};

    QLabel *l_flowerTime{};
    QLabel *l_lifeCycle{};
    QLabel *l_leaves{};
    QLabel *l_flowerGroup{};
    QLabel *l_plantHabit{};
    QLabel *l_containers{};

    QLabel *l_additional{};
    QLabel *l_url{};


    int fIndex{};
};

#endif // FLOWERCARD_H
