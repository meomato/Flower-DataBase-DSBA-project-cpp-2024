#include <gtest/gtest.h>
#include <QApplication>
#include "mainwindow.h"

// Создание глобального объекта QApplication для всех тестов
QApplication* globalApp = nullptr;

int main(int argc, char **argv) {
    // Создание QApplication
    int argc_copy = argc;
    globalApp = new QApplication(argc_copy, argv);

    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();

    // Удаление QApplication
    delete globalApp;

    return result;
}

// Тест на проверку заголовка окна
TEST(MainWindowTest, DefaultTitle) {
    MainWindow window;
    EXPECT_EQ(window.windowTitle(), "Bloom Baze | Home Page");
}

// Тест на проверку закрытия окна при нажатии на кнопку
TEST(InformationWindTest, CloseButton) {
    InformationWind window;

    // Имитируем нажатие на кнопку закрытия
    window.clicked_on_toolButton_5();

    // Проверяем, что окно закрыто
    EXPECT_FALSE(window.isVisible());
}

// Тест на скрытие интерфейса аутентификации после входа
TEST(GardnerWindowTest, ShowGardenerMain_HidesAuthInterface) {
    QStringList flowerNames = {"Rose", "Tulip", "Sunflower"};
    GardnerWindow window(flowerNames);

    window.le_login->setText("test_user");
    window.showGardenerMain();

    EXPECT_EQ(window.windowTitle(), "Bloom Baze | Your profile");
    EXPECT_FALSE(window.lb_login->isVisible());
    EXPECT_FALSE(window.le_login->isVisible());
    EXPECT_FALSE(window.lb_password->isVisible());
    EXPECT_FALSE(window.le_password->isVisible());
    EXPECT_FALSE(window.pb_access->isVisible());
    EXPECT_FALSE(window.pb_exit->isVisible());
}
