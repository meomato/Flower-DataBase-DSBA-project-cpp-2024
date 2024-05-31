/********************************************************************************
** Form generated from reading UI file 'gardenerform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GARDENERFORM_H
#define UI_GARDENERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GardenerForm
{
public:
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *GardenerForm)
    {
        if (GardenerForm->objectName().isEmpty())
            GardenerForm->setObjectName("GardenerForm");
        GardenerForm->resize(400, 300);
        gridLayout_2 = new QGridLayout(GardenerForm);
        gridLayout_2->setObjectName("gridLayout_2");

        retranslateUi(GardenerForm);

        QMetaObject::connectSlotsByName(GardenerForm);
    } // setupUi

    void retranslateUi(QWidget *GardenerForm)
    {
        GardenerForm->setWindowTitle(QCoreApplication::translate("GardenerForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GardenerForm: public Ui_GardenerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GARDENERFORM_H
