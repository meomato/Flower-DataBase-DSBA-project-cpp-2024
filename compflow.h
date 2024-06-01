#ifndef COMPFLOW_H
#define COMPFLOW_H

#include <QWidget>
#include "flowercontainer.h"

namespace Ui {
class CompFlow;
}

// Класс CompFlow отвечает за отображение и управление сравнением цветочных контейнеров.
// Наследует QWidget.
class CompFlow : public QWidget
{
    Q_OBJECT

public:
    explicit CompFlow(QWidget *parent = nullptr); // Конструктор класса, отвечает за инициализацию объекта.
    ~CompFlow(); // Деструктор класса, отвечает за освобождение ресурсов.

    // Метод setCompVector отвечает за установку вектора цветочных контейнеров для сравнения.
    // На вход принимает вектор указателей на FlowerContainer.
    // На выход ничего не возвращает.
    void setCompVector(QVector<FlowerContainer*> fcCompVector);

    // Метод clearWidgets отвечает за очистку всех виджетов, используемых для отображения сравнения.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void clearWidgets();

private:
    Ui::CompFlow *ui; // Указатель на UI компоновку.
};

#endif // COMPFLOW_H
