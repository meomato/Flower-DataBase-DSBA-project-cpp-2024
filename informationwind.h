#ifndef INFORMATIONWIND_H
#define INFORMATIONWIND_H

#include <QDialog>

namespace Ui {
class InformationWind;
}

class InformationWind : public QDialog
{
    Q_OBJECT

public:
    explicit InformationWind(QWidget *parent = nullptr);
    ~InformationWind();

private:
    Ui::InformationWind *ui;

private slots:

    // Слот clicked_on_toolButton_5 отвечает за закрытие окна информации.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void clicked_on_toolButton_5();
};

#endif // INFORMATIONWIND_H
