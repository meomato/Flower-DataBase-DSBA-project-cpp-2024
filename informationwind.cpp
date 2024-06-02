#include "informationwind.h"
#include "ui_informationwind.h"
#include <QPushButton>

InformationWind::InformationWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationWind)
{
    ui->setupUi(this);

    setWindowTitle("Bloom Baze | Info"); // Заголовок окна
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico")); // Иконка окна

    connect(ui->toolButton_5, &QPushButton::clicked, this, &InformationWind::clicked_on_toolButton_5);
}

InformationWind::~InformationWind()
{
    delete ui;
}

void InformationWind::clicked_on_toolButton_5()
{
   this->close();
}
