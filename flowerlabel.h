#ifndef FLOWERLABEL_H
#define FLOWERLABEL_H

#include <QLabel>
#include <QEvent>

// Класс FlowerLabel отвечает за отображение метки цветка с дополнительной функциональностью.
// Наследует QLabel.
class FlowerLabel : public QLabel
{
    Q_OBJECT
public:
    FlowerLabel(QWidget *parent = nullptr); // Конструктор класса, отвечает за инициализацию объекта.

protected:
    // Метод eventFilter отвечает за фильтрацию событий.
    // На вход принимает указатель на объект, который отслеживает события, и указатель на событие.
    // На выход возвращает true, если событие обработано, иначе false.
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    // Сигнал click вызывается при клике на метку.
    void click();
};

#endif // FLOWERLABEL_H
