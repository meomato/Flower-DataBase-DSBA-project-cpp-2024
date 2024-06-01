#ifndef FLOWERCONTAINER_H
#define FLOWERCONTAINER_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QCheckBox>
#include "flowerlabel.h"

// Класс FlowerContainer отвечает за управление контейнером цветка.
// Наследует QWidget.
class FlowerContainer : public QWidget
{
    Q_OBJECT
public:
    explicit FlowerContainer(QWidget *parent = nullptr); // Конструктор класса, отвечает за инициализацию объекта.

    // Метод setInfo отвечает за установку информации о цветке.
    // На вход принимает строку с адресом изображения и строку с описанием цветка.
    // На выход возвращает true, если информация установлена успешно, иначе false.
    bool setInfo(QString imgAddress, QString imgDesk);

    // Метод getImgDesk отвечает за получение дескриптора изображения цветка.
    // На вход ничего не принимает.
    // На выход возвращает строку с дескриптором.
    QString getImgDesk(){return imgDesk;}

    // Метод unChecked отвечает за снятие отметки с чекбокса.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void unChecked();

    // Информация для карточки цветка:
    QVector<QString> vUrlFlowers{}; // Вектор для хранения URL изображений цветов.
    QVector<QString> vDataFlowers{}; // Вектор для хранения данных о цветке в определенном порядке.

private:
    FlowerLabel *mainFl{}; // Основная метка цветка.
    FlowerLabel *deskFl{}; // Метка с описанием цветка.
    QCheckBox *select{}; // Чекбокс для выбора цветка.
    QGridLayout *mainLayout{}; // Основная компоновка для контейнера.
    QString imgDesk{}; // Дескриптор изображения цветка.

signals:
    // Сигнал click вызывается при нажатии на контейнер.
    void click();
    // Сигнал checked вызывается при изменении состояния чекбокса.
    // На вход принимает булевое значение, указывающее, установлен ли чекбокс.
    void checked(bool isCheck);
};

#endif // FLOWERCONTAINER_H
