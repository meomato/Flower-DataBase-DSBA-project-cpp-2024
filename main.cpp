#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico"));
    w.show();
    return a.exec();
}
