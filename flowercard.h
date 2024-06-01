#ifndef FLOWERCARD_H
#define FLOWERCARD_H

#include <QWidget>
#include "flowercontainer.h"

namespace Ui {
class FlowerCard;
}

// Класс FlowerCard отвечает за отображение карточки цветка.
// Наследует QWidget.
class FlowerCard : public QWidget
{
    Q_OBJECT

public:
    explicit FlowerCard(QWidget *parent = nullptr); // Конструктор класса, отвечает за инициализацию объекта.
    ~FlowerCard(); // Деструктор класса, отвечает за освобождение ресурсов.

    // Метод setFlowContainer отвечает за установку контейнера цветка для отображения в карточке.
    // На вход принимает указатель на FlowerContainer.
    // На выход ничего не возвращает.
    void setFlowContainer(FlowerContainer *p_fc);

private:
    Ui::FlowerCard *ui; // Указатель на UI компоновку.
    QVector<FlowerCard*> vFlowerLabel{}; // Вектор для хранения FlowerCard.
    FlowerContainer *fc{}; // Указатель на текущий FlowerContainer.
    FlowerLabel *sliderFl{}; // Указатель на слайдер цветка.

    QLabel *l_flowerTime{}; // Метка для времени цветения.
    QLabel *l_lifeCycle{}; // Метка для жизненного цикла.
    QLabel *l_leaves{}; // Метка для листьев.
    QLabel *l_flowerGroup{}; // Метка для группы цветков.
    QLabel *l_plantHabit{}; // Метка для привычек растения.
    QLabel *l_containers{}; // Метка для контейнеров.

    QLabel *l_additional{}; // Метка для дополнительной информации.
    QLabel *l_url{}; // Метка для URL.

    int fIndex{}; // Индекс цветка.
};

#endif // FLOWERCARD_H
