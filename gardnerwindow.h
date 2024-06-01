#ifndef GARDNERWINDOW_H
#define GARDNERWINDOW_H

#include <QWidget>
#include <QSettings>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QFile>
#include <QTableWidget>
#include <QDateTimeEdit>
#include <QComboBox>
#include "flowercontainer.h"

// Класс GardnerWindow отвечает за отображение окна садовника.
// Наследует QWidget.
class GardnerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GardnerWindow(QStringList flowNameList, QWidget *parent = nullptr); // Конструктор класса, отвечает за инициализацию объекта.

private:
    QSettings *auth{}; // Настройки аутентификации.

    QLabel *lb_login{}; // Метка для ввода логина.
    QLineEdit *le_login{}; // Поле ввода логина.
    QLabel *lb_password{}; // Метка для ввода пароля.
    QLineEdit *le_password{}; // Поле ввода пароля.
    QPushButton *pb_access{}; // Кнопка доступа.
    QPushButton *pb_exit{}; // Кнопка выхода.
    QPushButton *pb_logout{}; // Кнопка выхода из системы.

    QGridLayout *mainLayout{}; // Основная компоновка.
    QVector<FlowerContainer*> flowContVector{}; // Вектор контейнеров цветов.

    QMap<QString, QMap<int, QString>> gardenerFlowDb{}; // База данных цветов садовника.

    QTableWidget *twFlowers{}; // Таблица цветов.
    QTableWidget *twNotes{}; // Таблица заметок.

    QPushButton *addFlowBtn{}; // Кнопка добавления цветка.
    QPushButton *addNoteBtn{}; // Кнопка добавления заметки.

    QStringList flowNameList{}; // Список имен цветов.

    // Метод openGardnerFile отвечает за открытие файла садовника.
    // На вход ничего не принимает.
    // На выход возвращает true, если файл открыт успешно, иначе false.
    bool openGardnerFile();

    // Метод hideAuthInterface отвечает за скрытие интерфейса аутентификации.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void hideAuthInterface();

    // Метод processAuth отвечает за обработку аутентификации пользователя.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void processAuth();

    // Метод prepareFlowTable отвечает за подготовку таблицы цветов.
    // На вход принимает ссылку на настройки садовника.
    // На выход ничего не возвращает.
    void prepareFlowTable(QSettings &gardnerSettings);

    // Метод prepareNotesTable отвечает за подготовку таблицы заметок.
    // На вход принимает ссылку на настройки садовника.
    // На выход ничего не возвращает.
    void prepareNotesTable(QSettings &gardnerSettings);

private slots:
    // Слот showGardenerMain отвечает за отображение главного окна садовника.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void showGardenerMain();

    // Слот logout отвечает за выход из системы.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void logout();

    // Слот addFlower отвечает за добавление нового цветка.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void addFlower();

    // Слот addNote отвечает за добавление новой заметки.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void addNote();

    // Слот saveCurrFlower отвечает за сохранение текущего цветка.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void saveCurrFlower();

    // Слот saveCurrNote отвечает за сохранение текущей заметки.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void saveCurrNote();

    // Слот saveGurdnerData отвечает за сохранение данных садовника.
    // На вход ничего не принимает.
    // На выход ничего не возвращает.
    void saveGurdnerData();
};

#endif // GARDNERWINDOW_H
