#include "gardnerwindow.h"
#include <QMessageBox>

// Конструктор GardnerWindow отвечает за инициализацию окна садовника.
// На вход принимает список имен цветов и указатель на родительский виджет.
// На выход ничего не возвращает.
GardnerWindow::GardnerWindow(QStringList flowNameList, QWidget *parent)
    : QWidget{parent},
    flowNameList(flowNameList)
{
    auth = new QSettings("auth", QSettings::IniFormat); // Настройки аутентификации
    setWindowTitle("Bloom Baze | Registration/Authorization");
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico"));

    setFixedSize(200, 150); // Фиксированный размер окна

    mainLayout = new QGridLayout(); // Основная компоновка
    setLayout(mainLayout);

    lb_login = new QLabel("Enter name:");
    le_login = new QLineEdit();
    lb_password = new QLabel("Enter password:");
    le_password = new QLineEdit();
    pb_access = new QPushButton("Log in"); // Кнопка входа
    pb_access->setEnabled(false); // Пока поле логина пустое, поле пароля заблокировано
    connect(pb_access, &QPushButton::clicked, this, &GardnerWindow::showGardenerMain);
    connect(le_login, &QLineEdit::textChanged, this, [&](QString text){
        pb_access->setEnabled(!text.isEmpty());
    });

    pb_exit = new QPushButton("Close");
    connect(pb_exit, &QPushButton::clicked, this, &GardnerWindow::close);

    pb_logout = new QPushButton("Log out");
    pb_logout->setFixedSize(80, 30);
    pb_logout->hide(); // Скрыть кнопку до успешного входа в систему
    connect(pb_logout, &QPushButton::clicked, this, &GardnerWindow::logout);

    mainLayout->addWidget(lb_login, 0, 0, 1, 2);
    mainLayout->addWidget(le_login, 1, 0, 1, 2);
    mainLayout->addWidget(lb_password, 2, 0, 1, 2);
    mainLayout->addWidget(le_password, 3, 0, 1, 2);
    mainLayout->addWidget(pb_access, 4, 0);
    mainLayout->addWidget(pb_exit, 4, 1);
    mainLayout->addWidget(pb_logout, 5, 0, 1, 2);
}

// Метод logout отвечает за выход из системы и возврат к окну авторизации.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::logout()
{
    // Переход к окну авторизации
    setWindowTitle("Bloom Baze | Registration/Authorization");
    lb_login->show();
    le_login->show();
    lb_password->show();
    le_password->show();
    pb_access->show();
    pb_exit->show();
    pb_logout->hide();

    setFixedSize(200, 150);

    twFlowers->hide();
    twNotes->hide();
    addFlowBtn->hide();
    addNoteBtn->hide();
}

// Метод showGardenerMain отвечает за отображение главного профиля.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::showGardenerMain()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);
    processAuth();
    hideAuthInterface();
    prepareFlowTable(gardnerSettings);
    prepareNotesTable(gardnerSettings);

    pb_logout->show();
}

// Метод openGardnerFile отвечает за открытие файла садовника.
// На вход ничего не принимает.
// На выход возвращает true, если файл открыт успешно, иначе false.
bool GardnerWindow::openGardnerFile()
{
    QFile file(le_login->text());
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File opening error";
    }
    return true;
}

// Метод hideAuthInterface отвечает за скрытие интерфейса аутентификации.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::hideAuthInterface()
{
    setWindowTitle("Bloom Baze | Your profile");
    lb_login->hide();
    le_login->hide();
    lb_password->hide();
    le_password->hide();
    pb_access->hide();
    pb_exit->hide();

    setFixedSize(600, 500);
}

// Метод processAuth отвечает за обработку аутентификации пользователя.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::processAuth()
{
    QStringList logins{};
    int arrLoginSize = auth->beginReadArray("logins"); // Начало чтения массива "logins" из файла QSettings
    for (int loginIndex = 0; loginIndex < arrLoginSize; loginIndex++)
    {
        auth->setArrayIndex(loginIndex); // Установка текущего индекса массива на loginIndex
        logins << auth->value("login").toString(); // Чтение значения логина и добавление его в список logins
    }
    auth->endArray();

    if (!logins.contains(le_login->text())) // Если логин отсутствует в файле логинов
    {
        QMessageBox msgBox;
        msgBox.setText("Are you new Gardener?");
        msgBox.addButton(QMessageBox::Yes); // Добавление кнопки "Yes" в сообщение
        msgBox.addButton(QMessageBox::No); // Добавление кнопки "No" в сообщение
        int btn = msgBox.exec(); // Отображение сообщения и ожидание ответа пользователя
        switch (btn)
        {
        case QMessageBox::Yes: // Если ответ "Yes"
            logins.append(le_login->text()); // Добавление нового логина в список logins
            auth->beginWriteArray("logins"); // Начало записи массива "logins" в файл QSettings
            for (int loginIndex = 0; loginIndex < logins.size(); loginIndex++)
            {
                auth->setArrayIndex(loginIndex); // Установка текущего индекса массива на loginIndex
                auth->setValue("login", logins.at(loginIndex)); // Запись значения логина в массив
            }
            auth->endArray(); // Завершение записи массива
            break;
        case QMessageBox::No: // В случае ответа "No"
            return;
        default:
            return;
        }
    }
}

// Метод prepareFlowTable отвечает за подготовку таблицы цветов.
// На вход принимает ссылку на настройки садовника.
// На выход ничего не возвращает.
void GardnerWindow::prepareFlowTable(QSettings &gardnerSettings)
{
    twFlowers = new QTableWidget(this); // Создание таблицы

    twFlowers->setColumnCount(2); // Установка количества столбцов в таблице
    twFlowers->setColumnWidth(0, 300); // Установка ширины первого столбца
    twFlowers->setHorizontalHeaderLabels({"Flower name", "Watering"}); // Установка заголовков столбцов
    mainLayout->addWidget(twFlowers, 0, 0);

    int flowCount = gardnerSettings.beginReadArray("flowers"); // Начало чтения массива "flowers"

    for (int fIndex = 0; fIndex < flowCount; fIndex++)
    {
        twFlowers->blockSignals(true); // Блокировка сигналов для предотвращения триггеров во время инициализации таблицы

        gardnerSettings.setArrayIndex(fIndex); // Установка текущего индекса массива на fIndex
        int newRowNum = twFlowers->rowCount(); // Получение текущего количества строк в таблице
        addFlower(); // Добавление цветка в профиль
        QComboBox *currCombo = static_cast<QComboBox*>(twFlowers->cellWidget(newRowNum, 0));
        currCombo->blockSignals(true);

        QStringList allKeys = gardnerSettings.allKeys(); // Получение списка всех ключей (названий цветов) в настройках

        currCombo->setCurrentText(allKeys.at(0)); // Установка текущего текста выпадающего списка на первый ключ (название цветка)

        twFlowers->setItem(newRowNum, 1, new QTableWidgetItem(gardnerSettings.value(gardnerSettings.allKeys().at(0)).toString()));
        // Установка элемента во втором столбце (количество поливов) со значением, связанным с первым ключом

        currCombo->blockSignals(false); // Разблокировка сигналов для выпадающего списка
        twFlowers->blockSignals(false); // Разблокировка сигналов для таблицы
    }
    connect(twFlowers, &QTableWidget::itemChanged, this, &GardnerWindow::saveGurdnerData); // Сохранение данных при изменении элемента

    addFlowBtn = new QPushButton("Add new flower", this);
    mainLayout->addWidget(addFlowBtn, 0, 1);
    connect(addFlowBtn, &QPushButton::clicked, this, &GardnerWindow::addFlower); // Выбор нового цветка
    gardnerSettings.endArray(); // Завершение чтения массива
}

// Метод prepareNotesTable отвечает за подготовку таблицы заметок.
// На вход принимает ссылку на настройки садовника.
// На выход ничего не возвращает.
void GardnerWindow::prepareNotesTable(QSettings &gardnerSettings)
{
    twNotes = new QTableWidget(this);
    twNotes->setColumnCount(2); // Установка количества столбцов в таблице
    twNotes->setColumnWidth(0, 130); // Установка ширины первого столбца
    twNotes->setColumnWidth(1, 300); // Установка ширины второго столбца
    twNotes->setHorizontalHeaderLabels({"Data", "Notes"}); // Установка заголовков столбцов
    mainLayout->addWidget(twNotes, 1, 0);

    int noteCount = gardnerSettings.beginReadArray("notes"); // Начало чтения массива "notes"

    for (int nIndex = 0; nIndex < noteCount; nIndex++)
    {
        gardnerSettings.setArrayIndex(nIndex); // Установка текущего индекса массива на nIndex
        addNote(); // Добавление новой строки в таблицу заметок

        QString dateTimeKey = gardnerSettings.allKeys().at(0);
        dateTimeKey.remove('t'); // Удаление префикса 't'

        static_cast<QDateTimeEdit*>(twNotes->cellWidget(nIndex, 0))->setDateTime(QDateTime::fromSecsSinceEpoch(dateTimeKey.toInt()));
        // Установка даты и времени в виджете QDateTimeEdit

        twNotes->blockSignals(true); // Блокировка сигналов для предотвращения триггеров во время инициализации таблицы

        twNotes->setItem(nIndex, 1, new QTableWidgetItem(gardnerSettings.value(gardnerSettings.allKeys().at(0)).toString()));
        // Установка заметки во второй столбец

        twNotes->blockSignals(false); // Разблокировка сигналов
    }

    connect(twNotes, &QTableWidget::itemChanged, this, &GardnerWindow::saveGurdnerData); // Сохранение данных при изменении элемента

    addNoteBtn = new QPushButton("New note", this);
    mainLayout->addWidget(addNoteBtn, 1, 1);

    connect(addNoteBtn, &QPushButton::clicked, this, &GardnerWindow::addNote);

    gardnerSettings.endArray();
}

// Метод addFlower отвечает за добавление новой строки с цветком в таблицу.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::addFlower()
{
    int newRowNum = twFlowers->rowCount(); // Получение текущего количества строк в таблице
    twFlowers->insertRow(newRowNum); // Вставка новой строки в конец таблицы
    QComboBox *cb = new QComboBox(twFlowers); // Создание нового выпадающего списка для списка цветов

    cb->addItem("Choose the flower...");
    cb->addItems(flowNameList); // Добавление списка имен цветов в выпадающий список

    connect(cb, &QComboBox::currentIndexChanged, this, &GardnerWindow::saveGurdnerData);
    // Подключение сигнала currentIndexChanged выпадающего списка к слоту saveGurdnerData

    twFlowers->blockSignals(true); // Блокировка сигналов для предотвращения триггеров во время инициализации таблицы
    twFlowers->setCellWidget(newRowNum, 0, cb); // Установка выпадающего списка как виджета для первой ячейки новой строки
    twFlowers->setItem(newRowNum, 1, new QTableWidgetItem("0")); // Установка значения по умолчанию "0" (количество поливов) во второй ячейке
    twFlowers->blockSignals(false); // Разблокировка сигналов после завершения инициализации
}

// Метод addNote отвечает за добавление новой заметки.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::addNote()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat); // Настройки профиля
    int newRowNum = twNotes->rowCount(); // Получение текущего количества строк в таблице заметок
    twNotes->insertRow(newRowNum); // Вставка новой строки в конец таблицы
    QDateTime currTime = QDateTime::currentDateTime(); // Получение текущего времени
    twNotes->setCellWidget(newRowNum, 0, new QDateTimeEdit(currTime)); // Установка QDateTimeEdit с текущим временем в первую ячейку новой строки
    static_cast<QDateTimeEdit*>(twNotes->cellWidget(newRowNum, 0))->setCalendarPopup(true); // Включение всплывающего календаря для QDateTimeEdit
}

// Метод saveCurrFlower отвечает за сохранение текущих данных о цветах.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::saveCurrFlower()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat); // Настройки профиля

    gardnerSettings.beginWriteArray("flowers"); // Начало записи массива "flowers"
    for (int fIndex = 0; fIndex < twFlowers->rowCount(); fIndex++) // Строка за строкой
    {
        QComboBox *cb = qobject_cast<QComboBox*>(twFlowers->cellWidget(fIndex, 0));
        QTableWidgetItem *item = twFlowers->item(fIndex, 1); // Количество поливов

        if (cb->currentIndex() && item->text().length())
        {
            gardnerSettings.setArrayIndex(fIndex); // Установка текущего индекса массива на fIndex
            gardnerSettings.setValue(cb->currentText(), item->text()); // Сохранение значения в настройках
        }
    }
    gardnerSettings.endArray();
    gardnerSettings.sync(); // Синхронизация данных с файлом настроек
}

// Метод saveCurrNote отвечает за сохранение текущих заметок.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::saveCurrNote()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat); // Настройки профиля

    gardnerSettings.beginWriteArray("notes"); // Начало записи массива "notes"

    for (int fIndex = 0; fIndex < twNotes->rowCount(); fIndex++)
    {
        QString dateTime = QString::number(static_cast<QDateTimeEdit*>(twNotes->cellWidget(fIndex, 0))->dateTime().toSecsSinceEpoch());
        // Получение даты и времени из QDateTimeEdit в первой ячейке строки

        QTableWidgetItem *item = twNotes->item(fIndex, 1);

        if (item->text().length())
        {
            gardnerSettings.setArrayIndex(fIndex); // Установка текущего индекса массива на fIndex
            gardnerSettings.setValue("t" + dateTime, item->text()); // Сохранение значения в настройках
        }
    }
    gardnerSettings.endArray();
    gardnerSettings.sync(); // Синхронизация данных с файлом настроек
}

// Метод saveGurdnerData отвечает за сохранение данных.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void GardnerWindow::saveGurdnerData()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);
    gardnerSettings.clear();
    gardnerSettings.sync();
    saveCurrFlower();
    saveCurrNote();
}
