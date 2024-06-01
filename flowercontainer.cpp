#include "flowercontainer.h"

// Конструктор FlowerContainer отвечает за инициализацию контейнера цветка.
// На вход принимает указатель на родительский виджет.
// На выход ничего не возвращает.
FlowerContainer::FlowerContainer(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QGridLayout(this); // Создание компоновки окна

    mainFl = new FlowerLabel(this); // Метка для изображений цветка
    deskFl = new FlowerLabel(this); // Метка для названия цветка
    select = new QCheckBox(this); // Чекбокс для выбора

    // Размещение в Grid Layout:
    mainLayout->addWidget(mainFl, 0, 0, 1, 2); // Номер строки, номер столбца, количество занимаемых строк, столбцов
    mainLayout->addWidget(deskFl, 1, 0);
    mainLayout->addWidget(select, 1, 1, 1, 1, Qt::AlignRight); // Чекбокс справа

    connect(mainFl, &FlowerLabel::click, this, &FlowerContainer::click);
    connect(select, &QCheckBox::stateChanged, this, &FlowerContainer::checked);
}

// Метод setInfo отвечает за установку дополнительной информации для конкретного изображения.
// На вход принимает строку с адресом изображения и строку с описанием изображения.
// На выход возвращает true, если информация установлена успешно, иначе false.
bool FlowerContainer::setInfo(QString imgAddress, QString p_imgDesk)
{
    imgDesk = p_imgDesk.left(p_imgDesk.indexOf('(')); // Запись короткого названия цветка (без скобок)

    QPixmap pix; // Загрузка изображений
    if (!pix.load(imgAddress))
    {
        return false;
    }

    mainFl->setPixmap(pix);
    deskFl->setText(imgDesk);

    return true;
}

// Метод unChecked отвечает за снятие отметки с выбранных цветов.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void FlowerContainer::unChecked()
{
    select->setChecked(false);
}
