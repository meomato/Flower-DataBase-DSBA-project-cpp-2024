#include "flowerlabel.h"
#include <iostream>

// Конструктор FlowerLabel отвечает за инициализацию метки цветка.
// На вход принимает указатель на родительский виджет.
// На выход ничего не возвращает.
FlowerLabel::FlowerLabel(QWidget *parent) : QLabel{parent}
{
    installEventFilter(this); // Установка фильтра событий
}

// Метод eventFilter отвечает за фильтрацию событий.
// На вход принимает указатель на объект, который отслеживает события, и указатель на событие.
// На выход возвращает true, если событие обработано, иначе false.
bool FlowerLabel::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) // Обрабатывает нажатия мыши
    {
        // Если пользователь нажимает на изображение, то вызывается сигнал click
        emit click();
    }
    return false;
}
