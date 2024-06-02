#include "compflow.h"
#include "ui_compflow.h"
#include <QTableWidget>
#include <QHeaderView>

// Конструктор CompFlow отвечает за инициализацию окна сравнения.
// На вход принимает указатель на родительский виджет.
// На выход ничего не возвращает.
CompFlow::CompFlow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompFlow)
{
    ui->setupUi(this);
    setWindowTitle("Bloom Baze | Flower Comparison"); // Установка заголовка окна
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico")); // Установка иконки окна

}

// Деструктор CompFlow отвечает за освобождение ресурсов, используемых объектом.
// На вход ничего не принимает.
// На выход ничего не возвращает.
CompFlow::~CompFlow()
{
    delete ui;
}

// Метод setCompVector отвечает за установку вектора цветочных контейнеров для сравнения.
// На вход принимает вектор указателей на FlowerContainer.
// На выход ничего не возвращает.
void CompFlow::setCompVector(QVector<FlowerContainer *> fcCompVector)
{
    clearWidgets(); // Очистка существующих виджетов из компоновки

    for(const auto fc: fcCompVector)
    {
        FlowerLabel *fl = new FlowerLabel; // Создание нового виджета FlowerLabel
        fl->setAlignment(Qt::AlignHCenter); // Выравнивание содержимого метки по центру горизонтально
        QPixmap pix(fc->vUrlFlowers.at(0)); // Создание QPixmap из первого URL изображения в FlowerContainer
        fl->setPixmap(pix); // Установка QPixmap как содержимого FlowerLabel
        int currColumn = ui->gridLayout->columnCount(); // Получение текущего количества столбцов в компоновке
        ui->gridLayout->addWidget(fl, 0, currColumn); // Добавление FlowerLabel в компоновку в текущий столбец

        QTableWidget *flowTable = new QTableWidget(); // Создание нового QTableWidget для отображения данных о цветке
        flowTable->setAlternatingRowColors(true); // Включение чередующихся цветов строк для лучшей читаемости
        flowTable->setEditTriggers(QAbstractItemView::NoEditTriggers); // Установка таблицы в режим только для чтения
        flowTable->setSelectionMode(QAbstractItemView::NoSelection); // Отключение возможности выбора ячеек
        flowTable->setSelectionBehavior(QAbstractItemView::SelectRows); // Установка поведения выбора строк
        flowTable->horizontalHeader()->setVisible(false); // Скрытие горизонтального заголовка
        flowTable->verticalHeader()->setVisible(false); // Скрытие вертикального заголовка
        ui->gridLayout->addWidget(flowTable, 1, currColumn); // Добавление QTableWidget в компоновку под FlowerLabel

        flowTable->setColumnCount(2); // Установка количества столбцов в таблице
        flowTable->setColumnWidth(0, 123); // Установка ширины первого столбца
        flowTable->setColumnWidth(1, 123); // Установка ширины второго столбца
        flowTable->setRowCount(8); // Установка количества строк в таблице

        int rowIndex{}; // Инициализация переменной индекса строки
        while(rowIndex < flowTable->rowCount())
        {
            flowTable->setRowHeight(rowIndex, 50); // Установка высоты каждой строки в 50 пикселей
            rowIndex++;
        }

        // Установка текста и данных для каждой ячейки в таблице
        flowTable->setItem(0, 0, new QTableWidgetItem("Flower time:")); // Установка метки для времени цветения
        flowTable->setItem(0, 1, new QTableWidgetItem(fc->vDataFlowers.at(0))); // Установка данных о времени цветения
        flowTable->setItem(1, 0, new QTableWidgetItem("Life Cycle:")); // Установка метки для жизненного цикла
        flowTable->setItem(1, 1, new QTableWidgetItem(fc->vDataFlowers.at(1))); // Установка данных о жизненном цикле
        flowTable->setItem(2, 0, new QTableWidgetItem("Leaves:")); // Установка метки для листьев
        flowTable->setItem(2, 1, new QTableWidgetItem(fc->vDataFlowers.at(2))); // Установка данных о листьях
        flowTable->setItem(3, 0, new QTableWidgetItem("Flower group:")); // Установка метки для группы цветков
        flowTable->setItem(3, 1, new QTableWidgetItem(fc->vDataFlowers.at(3))); // Установка данных о группе цветков
        flowTable->setItem(4, 0, new QTableWidgetItem("Plant habit:")); // Установка метки для привычек растения
        flowTable->setItem(4, 1, new QTableWidgetItem(fc->vDataFlowers.at(4))); // Установка данных о привычках растения
        flowTable->setItem(5, 0, new QTableWidgetItem("Containers:")); // Установка метки для контейнеров
        flowTable->setItem(5, 1, new QTableWidgetItem(fc->vDataFlowers.at(5))); // Установка данных о контейнерах
        flowTable->setItem(6, 0, new QTableWidgetItem("Additional:")); // Установка метки для дополнительной информации
        flowTable->setItem(6, 1, new QTableWidgetItem(fc->vDataFlowers.at(6))); // Установка данных о дополнительной информации
        flowTable->setItem(7, 0, new QTableWidgetItem("URL:")); // Установка метки для URL
        flowTable->setItem(7, 1, new QTableWidgetItem(fc->vDataFlowers.at(7))); // Установка данных о URL

        fl->setFocus(); // Установка фокуса на FlowerLabel для потенциального взаимодействия с пользователем или визуальной индикации
    }
}

// Метод clearWidgets отвечает за очистку всех виджетов из компоновки.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void CompFlow::clearWidgets()
{
    QLayoutItem *item; // Элемент компоновки
    while ((item = ui->gridLayout->takeAt(0)) != nullptr) // Цикл до тех пор, пока в компоновке есть элементы
    {
        if (item->widget()) { // Если элемент является виджетом
            delete item->widget(); // Удалить виджет
        }
        delete item; // Удалить элемент компоновки
    }
}
