#include "mainwindow.h"
#include <QApplication>

// Функция main отвечает за инициализацию и запуск главного окна приложения.
// На вход принимает argc - количество аргументов командной строки, argv - массив аргументов командной строки.
// На выход возвращает код завершения работы приложения.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Создание приложения Qt.
    MainWindow w; // Создание и инициализация главного окна.
    a.setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico")); // Установка иконки окна.
    w.show(); // Отображение главного окна.
    return a.exec(); // Запуск цикла обработки событий.
}
