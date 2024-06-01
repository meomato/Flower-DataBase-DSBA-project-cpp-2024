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

// Класс MainWindow отвечает за главное окно приложения.
// Наследует QMainWindow.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // Конструктор класса, отвечает за инициализацию объекта.
    ~MainWindow(); // Деструктор класса, отвечает за освобождение ресурсов.

private slots:
    // Слот showCard отвечает за отображение карточки цветка.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void showCard();

    // Слот on_lineEdit_textChanged отвечает за обработку изменения текста в QLineEdit.
    // На вход принимает строку с новым текстом.
    // На выход ничего не возвращает.
    void on_lineEdit_textChanged(const QString &arg1);

    // Слот on_pb_flowerGroup_clicked отвечает за обработку нажатия на кнопку выбора группы цветов.
    // На вход принимает булевое значение, указывающее, установлена ли кнопка.
    // На выход ничего не возвращает.
    void on_pb_flowerGroup_clicked(bool checked);

    // Слот on_pb_container_clicked отвечает за обработку нажатия на кнопку выбора контейнера.
    // На вход принимает булевое значение, указывающее, установлена ли кнопка.
    // На выход ничего не возвращает.
    void on_pb_container_clicked(bool checked);

    // Слот on_pb_popularity_clicked отвечает за обработку нажатия на кнопку выбора популярности.
    // На вход принимает булевое значение, указывающее, установлена ли кнопка.
    // На выход ничего не возвращает.
    void on_pb_popularity_clicked(bool checked);

    // Слот loadFlowers отвечает за загрузку цветов, соответствующих указанной подстроке.
    // На вход принимает строку для фильтрации.
    // На выход ничего не возвращает.
    void loadFlowers(QString subString = "");

    // Слот processFlowGroupVector отвечает за обработку выбранной группы цветов.
    // На вход принимает булевое значение, указывающее, выбрана ли группа.
    // На выход ничего не возвращает.
    void processFlowGroupVector(bool isChecked);

    // Слот processQualityVector отвечает за обработку выбранных качеств цветов.
    // На вход принимает булевое значение, указывающее, выбраны ли качества.
    // На выход ничего не возвращает.
    void processQualityVector(bool isChecked);

    // Слот processContainerVector отвечает за обработку выбранных контейнеров цветов.
    // На вход принимает булевое значение, указывающее, выбраны ли контейнеры.
    // На выход ничего не возвращает.
    void processContainerVector(bool isChecked);

    // Слот processPopularityVector отвечает за обработку выбранной популярности цветов.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void processPopularityVector();

    // Слот on_pb_qualities_clicked отвечает за обработку нажатия на кнопку выбора качеств цветов.
    // На вход принимает булевое значение, указывающее, установлена ли кнопка.
    // На выход ничего не возвращает.
    void on_pb_qualities_clicked(bool checked);

    // Слот on_toolButton_clicked отвечает за обработку нажатия на первую кнопку.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void on_toolButton_clicked();

    // Слот on_toolButton_2_clicked отвечает за обработку нажатия на вторую кнопку.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void on_toolButton_2_clicked();

    // Слот addToCompare отвечает за добавление цветка в список для сравнения.
    // На вход принимает булевое значение, указывающее, выбран ли цветок.
    // На выход ничего не возвращает.
    void addToCompare(bool isChecked);

    // Слот on_toolButton_3_clicked отвечает за обработку нажатия на третью кнопку.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void on_toolButton_3_clicked();

private:
    Ui::MainWindow *ui; // Указатель на UI компоновку.
    QMap<int, QVector<QString>> flowersDb{}; // База данных цветов из CSV-файла.
    QVector<QString> topics{}; // Вектор с заголовками колонок.
    QTableWidget *tw{}; // Указатель на виджет таблицы.

    // Переменные-члены класса MainWindow:
    FlowerCard *fcard{}; // Карточка цветка.
    CompFlow *compFlow{}; // Окно сравнения.
    GardnerWindow *gardnerWindow{}; // Окно садовника.
    QVector<FlowerContainer*> fcVector{}; // Вектор контейнеров цветков.

    // Метод openCsv отвечает за открытие и чтение CSV-файла.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void openCsv();

    QVector<FlowerContainer*> fcCompareVector{}; // Вектор контейнеров для сравнения.

    // Метод split отвечает за разделение строки по запятым и кавычкам.
    // На вход принимает строку для разделения.
    // На выход возвращает QStringList с разделенными элементами.
    QStringList split(QString full);

    QVector<QString> flowGroupVector{}; // Вектор групп цветов.
    QVector<QString> qualitiesVector{}; // Вектор качеств цветов.
    QVector<QString> containerVector{}; // Вектор контейнеров.
    QMultiMap<int, int> popularityMMap{}; // Мультимап для популярности цветов.

    QMenu *menu{}; // Меню.
    QAction *actionLogin{}; // Действие "Войти".

    QSettings *settings{}; // Настройки приложения.
};

#endif // MAINWINDOW_H
