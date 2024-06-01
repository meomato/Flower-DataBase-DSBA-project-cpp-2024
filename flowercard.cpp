#include "flowercard.h"
#include <iostream>
#include "ui_flowercard.h"

// Конструктор FlowerCard отвечает за инициализацию карточки цветка.
// На вход принимает указатель на родительский виджет.
// На выход ничего не возвращает.
FlowerCard::FlowerCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlowerCard)
{
    ui->setupUi(this);

    sliderFl = new FlowerLabel();
    sliderFl->setAlignment(Qt::AlignHCenter); // Центрирование слайдера

    // Создание лямбда-функции без указания типа,
    // & для импорта всех методов и свойств внешнего класса в функцию
    connect(sliderFl, &FlowerLabel::click, this, [&]()
    {
        // fIndex - номер изображения по порядку
        // vUrlFlowers - адреса изображений
        // если индекс последний, то сбрасываем его до нуля и загружаем заново
        if(!(++fIndex < fc->vUrlFlowers.count()))
            fIndex = 0;

        // Загрузка изображения:
        QPixmap pix(fc->vUrlFlowers.at(fIndex));
        sliderFl->setPixmap(pix);
    });

    ui->gridLayout->addWidget(sliderFl, 0, 0);

    setWindowTitle("Bloom Baze | Description of the flower");
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico"));
}

// Деструктор FlowerCard отвечает за освобождение ресурсов, используемых объектом.
// На вход ничего не принимает.
// На выход ничего не возвращает.
FlowerCard::~FlowerCard()
{
    delete ui;
}

// Метод setFlowContainer отвечает за установку контейнера цветка для отображения в карточке.
// На вход принимает указатель на FlowerContainer.
// На выход ничего не возвращает.
void FlowerCard::setFlowContainer(FlowerContainer *p_fc)
{
    fc = p_fc;

    ui->tableWidget->setColumnWidth(0, 167);
    ui->tableWidget->setColumnWidth(1, 167);

    ui->tableWidget->setRowHeight(0, 63);
    ui->tableWidget->setRowHeight(1, 63);
    ui->tableWidget->setRowHeight(2, 63);

    l_flowerTime = new QLabel(this);
    l_flowerTime->setWordWrap(true);
    l_flowerTime->setFixedWidth(163);
    l_flowerTime->setText("Flower time: \n" + fc->vDataFlowers.at(0));
    ui->tableWidget->setCellWidget(0, 0, l_flowerTime);

    l_lifeCycle = new QLabel(this);
    l_lifeCycle->setWordWrap(true);
    l_lifeCycle->setFixedWidth(163);
    l_lifeCycle->setText("Life Cycle: \n" + fc->vDataFlowers.at(1));
    ui->tableWidget->setCellWidget(0, 1, l_lifeCycle);

    l_leaves = new QLabel(this);
    l_leaves->setWordWrap(true);
    l_leaves->setFixedWidth(163);
    l_leaves->setText("Leaves: \n" + fc->vDataFlowers.at(2));
    ui->tableWidget->setCellWidget(1, 0, l_leaves);

    l_flowerGroup = new QLabel(this);
    l_flowerGroup->setWordWrap(true);
    l_flowerGroup->setFixedWidth(163);
    l_flowerGroup->setText("Flower group: \n" + fc->vDataFlowers.at(3));
    ui->tableWidget->setCellWidget(1, 1, l_flowerGroup);

    l_plantHabit = new QLabel(this);
    l_plantHabit->setWordWrap(true);
    l_plantHabit->setFixedWidth(163);
    l_plantHabit->setText("Plant habit: \n" + fc->vDataFlowers.at(4));
    ui->tableWidget->setCellWidget(2, 0, l_plantHabit);

    l_containers = new QLabel(this);
    l_containers->setWordWrap(true);
    l_containers->setFixedWidth(163);
    l_containers->setText("Containers: \n" + fc->vDataFlowers.at(5));
    ui->tableWidget->setCellWidget(2, 1, l_containers);

    ui->tableWidget_2->setColumnWidth(0, 340);

    ui->tableWidget_2->setRowHeight(0, 95);
    ui->tableWidget_2->setRowHeight(1, 95);

    fIndex = 0;
    QPixmap pix(fc->vUrlFlowers.at(fIndex));
    sliderFl->setPixmap(pix); // Запись изображений для отображения
    ui->l_fname->setText(fc->getImgDesk());

    l_additional = new QLabel(this);
    l_additional->setWordWrap(true);
    l_additional->setFixedWidth(326);
    l_additional->setText(fc->vDataFlowers.at(6));
    ui->tableWidget_2->setCellWidget(0, 0, l_additional);

    l_url = new QLabel(this);
    l_url->setWordWrap(true);
    l_url->setFixedWidth(326);
    l_url->setText(fc->vDataFlowers.at(7));
    ui->tableWidget_2->setCellWidget(1, 0, l_url);
}
