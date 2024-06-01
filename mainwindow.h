#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtablewidget.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QCheckBox>
#include <QListWidgetItem>
#include <QSettings>
#include <QRadioButton>
#include <QMenu>
#include "flowercard.h"
#include "compflow.h"
#include "gardnerwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showCard();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_flowerGroup_clicked(bool checked);

    void on_pb_container_clicked(bool checked);

    void on_pb_popularity_clicked(bool checked);

    void loadFlowers(QString subString = "");

    void processFlowGroupVector(bool isChecked);

    void processQualityVector(bool isChecked);

    void processContainerVector(bool isChecked);

    void processPopularityVector();

    void on_pb_qualities_clicked(bool checked);

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void addToCompare(bool isChecked);

    void on_toolButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QMap<int, QVector<QString>> flowersDb{};
    QVector<QString> topics{};
    QTableWidget *tw{};
    FlowerCard *fcard{};
    CompFlow *compFlow{};
    GardnerWindow *gardnerWindow{};
    QVector<FlowerContainer*> fcVector{};

    void openCsv();

    QVector<FlowerContainer*> fcCompareVector{};


    QStringList split(QString full);

    QVector<QString> flowGroupVector{};
    QVector<QString> qualitiesVector{};
    QVector<QString> containerVector{};
    QMultiMap<int, int> popularityMMap{};

    QMenu *menu{};
    QAction *actionLogin{};
    QAction *actionLogout{};

    QSettings *settings{};

};
#endif // MAINWINDOW_H
