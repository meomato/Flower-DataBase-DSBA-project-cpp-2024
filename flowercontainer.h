#ifndef FLOWERCONTAINER_H
#define FLOWERCONTAINER_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QCheckBox>
#include "flowerlabel.h"

class FlowerContainer : public QWidget
{
    Q_OBJECT
public:
    explicit FlowerContainer(QWidget *parent = nullptr);
    bool setInfo(QString imgAddress, QString imgDesk);
    QVector<QString> vUrlFlowers{};
    QVector<QString> vDataFlowers{};
    QString getImgDesk(){return imgDesk;}
    void unChecked();
private:
    FlowerLabel *mainFl{};
    FlowerLabel *deskFl{};
    QCheckBox *select{};
    QGridLayout *mainLayout{};
    QString imgDesk{};

signals:
    void click();
    void checked(bool isCheck);
};

#endif // FLOWERCONTAINER_H
