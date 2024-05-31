#include "flowercontainer.h"

FlowerContainer::FlowerContainer(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QGridLayout(this);

    mainFl = new FlowerLabel(this);
    deskFl = new FlowerLabel(this);
    select = new QCheckBox(this);

    mainLayout->addWidget(mainFl,0,0,1,2);
    mainLayout->addWidget(deskFl,1,0);
    mainLayout->addWidget(select,1,1,1,1,Qt::AlignRight);


    connect(mainFl, &FlowerLabel::click, this, &FlowerContainer::click);
    connect(select, &QCheckBox::stateChanged, this, &FlowerContainer::checked);
}

bool FlowerContainer::setInfo(QString imgAddress, QString p_imgDesk)
{
    imgDesk = p_imgDesk.left(p_imgDesk.indexOf('('));

    QPixmap pix;
    if (!pix.load(imgAddress))
    {
        return false;
    }
    mainFl->setPixmap(pix);

    deskFl->setText(imgDesk);
    return true;
}

void FlowerContainer::unChecked()
{
    select->setChecked(false);
}
