#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDir>

// Конструктор MainWindow отвечает за инициализацию главного окна приложения.
// На вход принимает указатель на родительский виджет.
// На выход ничего не возвращает.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settings = new QSettings("stat", QSettings::IniFormat, this); // Хранение конфигурации файла "stat" в формате ini для популярности

    compFlow = new CompFlow(); // Создание экземпляра класса сравнения цветов

    openCsv(); // Открытие CSV файла

    tw = ui->tableWidget; // Сокращение имени

    loadFlowers(); // Загрузка изображений цветов

    gardnerWindow = new GardnerWindow(flowersDb[1]); // Создание экземпляра класса профиля садовника
    fcard = new FlowerCard(); // Создание экземпляра класса описания цветка

    ui->tw_filterList->setColumnWidth(0, 250); // Ширина колонки фильтра

    setWindowTitle("Bloom Baze | Home Page"); // Заголовок окна
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico")); // Иконка окна

    menu = new QMenu("Menu"); // Меню
    actionLogin = new QAction("Login", this);
    menu->addAction(actionLogin); // Параметры меню

    ui->toolButton_3->setMenu(menu); // Кнопка для меню
    ui->toolButton_3->setPopupMode(QToolButton::InstantPopup); // Отображение меню при нажатии

    // Иконки для кнопок
    ui->toolButton->setIcon(QIcon(":/img/icons8_compare.png"));
    ui->toolButton_3->setIcon(QIcon(":/img/user_1077063.png"));
    ui->toolButton_2->setIcon(QIcon(":/img/icons8_remake.png"));

    // Связь между кнопкой входа и профилем
    connect(actionLogin, &QAction::triggered, this, &MainWindow::on_toolButton_3_clicked);
}

// Деструктор MainWindow отвечает за освобождение ресурсов, используемых объектом.
// На вход ничего не принимает.
// На выход ничего не возвращает.
MainWindow::~MainWindow()
{
    delete ui;
}

// Метод showCard отвечает за отображение карточки цветка.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void MainWindow::showCard()
{
    FlowerContainer *fCont = qobject_cast<FlowerContainer *>(sender());
    // sender() - позволяет получить указатель на виджет, который вызвал сигнал
    // с помощью qobject_cast преобразуем указатель от QWidget к FlowerContainer

    int counter = settings->value(fCont->getImgDesk()).toInt();
    settings->setValue(fCont->getImgDesk(), ++counter);
    // В статистике увеличиваем количество кликов на цветок
    // fCont->getImgDesk() - ключ; ++counter - значение

    fcard->setFlowContainer(fCont); // Указываем контейнер для карточки цветка с инфо векторами
    fcard->show();
}

// Метод split отвечает за разделение строки на колонки.
// На вход принимает строку для разделения.
// На выход возвращает список разделенных колонок в виде QStringList.
QStringList MainWindow::split(QString full)
{
    QStringList result{};
    int commaIndex{}; // номер запятой в строке
    while(commaIndex >= 0)
    {
        int marksIndex  = full.indexOf('"'); // поиск ближайшей кавычки
        if(!marksIndex)
            marksIndex++;
        commaIndex = full.indexOf(','); // поиск ближайшей запятой
        if(marksIndex != -1) // если кавычка найдена, проверяем находится ли она перед или после запятой
        {
            if(commaIndex < marksIndex) // Если запятая находится перед кавычками, кавычки находятся в другой колонке
            {
                result.push_back(full.left(commaIndex));
                full.remove(0, commaIndex+1);
            }
            else
            {
                // если кавычки перед запятой, значит кавычки в этой колонке
                // поиск индекса второй кавычки:
                int marksIndex2 = full.indexOf('"',marksIndex);
                int commaIndex2 = full.indexOf(',',marksIndex2);

                // создание строки с удаленными кавычками:
                QString str = full.left(commaIndex2);
                str.remove('"');

                result.push_back(str);
                full.remove(0, commaIndex2+1);
            }
        }
        else
        {
            // обычное разделение строки
            result.push_back(full.left(commaIndex));
            full.remove(0, commaIndex+1); // удаление слова до запятой и самой запятой
        }
    }
    return result; // возвращает список разделенных колонок
}

// Метод openCsv отвечает за открытие и чтение CSV файла.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void MainWindow::openCsv()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Opening flower database"), "", tr("CSV file (*.csv)"));
    // QFileDialog::getOpenFileName - Это статический метод класса QFileDialog, который открывает диалоговое окно для выбора одного файла.
    // Возвращает путь к выбранному файлу в виде строки
    // tr("Opening flower database") - Этот текст будет отображаться в заголовке диалогового окна
    // "" - Начальная директория. Пустая строка означает, что диалоговое окно будет открыто в текущей рабочей директории приложения
    // tr("CSV file (*.csv)") - Фильтр файлов, который определяет, какие файлы могут быть выбраны в диалоговом окне

    QFile file(fileName);
    // QFile - для работы с файлами

    // попытка открыть файл:
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // текстовый формат, только для чтения
        return;

    int strIndex{};

    while (!file.atEnd()) { // пока не достигнут конец файла
        QByteArray line = file.readLine(); // чтение каждой строки
        QString currString = QString::fromUtf8(line); // преобразование полученного набора байтов в строку
        QStringList items = split(currString); // наша функция для получения списка разделенных колонок
        items << settings->value(items[1]).toString(); // по названию цветка получаем текущую статистику по количеству кликов на цветок
        int colIndex{}; // счетчик колонок
        for(const auto item : items)
        {
            if(!strIndex) // номер строки, которую читаем
            {
                topics.push_back(item);
                flowersDb.insert(colIndex, {});
            }
            else
            {
                flowersDb[colIndex].push_back(item); // заполняем таблицу
                if(colIndex == 1) // если номер колонки = 1, создаем статистику для каждого цветка
                {
                    if(!settings->contains(item))
                    {
                        settings->setValue(item, 0);
                    }
                }

            }
            colIndex++;
        }
        strIndex++;
    }
}

// Метод loadFlowers отвечает за загрузку изображений цветов.
// На вход принимает подстроку для фильтрации цветов (необязательный).
// На выход ничего не возвращает.
void MainWindow::loadFlowers(QString subString)
{
    if(fcVector.size()) // пока вектор не пустой
    {
        for(auto fc: fcVector)
        {
            delete fc;
            fcVector.remove(fcVector.indexOf(fc));
        }
    }

    tw->setRowCount(0); // очистка
    bool isLeft = true; // левая или правая колонка
    int newRow{};
    int iterIndex{};

    QMultiMap<int, int>::Iterator mmIter{};

    if(popularityMMap.size())
    {
        if(qobject_cast<QRadioButton*>(ui->tw_filterList->cellWidget(1,0))->isChecked())
        {
            mmIter = popularityMMap.begin();
        }
        else
        {
            mmIter = --popularityMMap.end();
        }
    }

    while(iterIndex < flowersDb[1].count()) // перебор имен цветов
    {
        QString flowerName = flowersDb.value(1).at(iterIndex); // короткое название цветка

        if(subString.length())
        {
            if(!flowerName.contains(subString))
            {
                iterIndex++;
                continue;
            }
        }

        if(flowGroupVector.length())
        {
            if(!flowGroupVector.contains(flowersDb.value(0).at(iterIndex))) // если вектор не содержит название группы этого цветка, пропускаем
            {
                iterIndex++;
                continue;
            }
        }

        if(qualitiesVector.length())
        {
            if(!qualitiesVector.contains(flowersDb.value(5).at(iterIndex))) // если вектор не содержит название характеристики этого цветка, пропускаем
            {
                iterIndex++;
                continue;
            }
        }

        if(containerVector.length())
        {
            if(!containerVector.contains(flowersDb.value(3).at(iterIndex))) // если вектор не содержит название контейнера этого цветка, пропускаем
            {
                iterIndex++;
                continue;
            }
        }

        if(popularityMMap.size())
        {
            iterIndex = mmIter.value();
            flowerName = flowersDb.value(1).at(iterIndex);
            if(qobject_cast<QRadioButton*>(ui->tw_filterList->cellWidget(1,0))->isChecked())
            {
                mmIter++;
                if(mmIter == popularityMMap.end())
                {
                    break;
                }
            }
            else
            {
                if(mmIter == popularityMMap.begin())
                {
                    break;
                }
                mmIter--;
            }
        }

        FlowerContainer *fc = new FlowerContainer(this); // хранение изображений, имен, галочек цветов и т.д.
        fcVector.push_back(fc); // для сравнения
        fc->vDataFlowers.push_back(flowersDb.value(4).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(7).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(6).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(0).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(9).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(3).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(8).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(2).at(iterIndex));

        connect(fc, &FlowerContainer::click, this, &MainWindow::showCard); // связь между кликом по контейнеру и открытием описания
        connect(fc, &FlowerContainer::checked, this, &MainWindow::addToCompare); // связь между выбором чекбокса и добавлением цветка в сравнение

        QDir currDir("./img/"+flowerName); // адрес цветка
        QString fAddress{};
        fAddress = "./img/"+flowerName+"/"+currDir.entryList().value(2); // полный адрес изображения

        if(!fc->setInfo(fAddress, flowerName)) // установка информации в FlowerContainer, если не удалось, пропускаем
        {
            iterIndex++;
            continue;
        }

        if(isLeft) // проверяем с какой стороны отображать цветы
        {
            newRow = tw->rowCount(); // общее количество строк
            tw->insertRow(newRow); // создание новой строки
            tw->setCellWidget(newRow, 0, fc); // размещение изображения с подписью в первой ячейке строки
        }
        else
        {
            tw->setCellWidget(newRow, 1, fc);
        }
        isLeft = !isLeft;

        for(const auto fName : currDir.entryList()) // перебор имен цветов
        {
            if(fName!="." && fName!="..")
            {
                fc->vUrlFlowers.push_back("./img/"+flowerName+"/"+fName); // добавление вектора изображений для слайдера цветов
            }
        }

        if(!popularityMMap.size())
        {
            iterIndex++;
        }
    }
}

// Метод processFlowGroupVector отвечает за фильтрацию по группам.
// На вход принимает булевое значение, указывающее, выбран ли элемент.
// На выход ничего не возвращает.
void MainWindow::processFlowGroupVector(bool isChecked)
{
    int rowNum = ui->tw_filterList->currentRow(); // номер текущей строки

    QString str = qobject_cast<QCheckBox*>(ui->tw_filterList->cellWidget(rowNum, 0))->text(); // получение чекбокса для этой группы

    if(isChecked) // если чекбокс отмечен, добавляем в вектор
    {
        flowGroupVector << str;
    }
    else
    {
        flowGroupVector.remove(flowGroupVector.indexOf(str)); // если не отмечен, удаляем
    }
    loadFlowers(); // обновление страницы
}

// Метод processQualityVector отвечает за фильтрацию по качествам.
// На вход принимает булевое значение, указывающее, выбран ли элемент.
// На выход ничего не возвращает.
void MainWindow::processQualityVector(bool isChecked)
{
    int rowNum = ui->tw_filterList->currentRow();
    QString str = qobject_cast<QCheckBox*>(ui->tw_filterList->cellWidget(rowNum, 0))->text();
    if(isChecked)
    {
        qualitiesVector << str;
    }
    else
    {
        qualitiesVector.remove(qualitiesVector.indexOf(str));
    }
    loadFlowers();
}

// Метод processContainerVector отвечает за фильтрацию по контейнерам.
// На вход принимает булевое значение, указывающее, выбран ли элемент.
// На выход ничего не возвращает.
void MainWindow::processContainerVector(bool isChecked)
{
    int rowNum = ui->tw_filterList->currentRow();
    QString str = qobject_cast<QCheckBox*>(ui->tw_filterList->cellWidget(rowNum, 0))->text();
    if(isChecked)
    {
        containerVector << str;
    }
    else
    {
        containerVector.remove(containerVector.indexOf(str));
    }
    loadFlowers();
}

// Метод processPopularityVector отвечает за обработку вектора популярности.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void MainWindow::processPopularityVector()
{
    popularityMMap.clear();
    for(int strIndex = 0; strIndex < flowersDb[1].count(); strIndex++)
    {
        popularityMMap.insert(flowersDb[29].at(strIndex).toInt(), strIndex);
    }
    loadFlowers();
}

// Слот on_lineEdit_textChanged отвечает за обработку изменения текста в QLineEdit.
// На вход принимает строку с новым текстом.
// На выход ничего не возвращает.
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    loadFlowers(arg1);
}

// Слот on_pb_flowerGroup_clicked отвечает за обработку нажатия на кнопку выбора группы цветов.
// На вход принимает булевое значение, указывающее, установлена ли кнопка.
// На выход ничего не возвращает.
void MainWindow::on_pb_flowerGroup_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(0); // очистка списка фильтров
    if(checked)
    {
        ui->pb_container->setChecked(false);
        ui->pb_flowerGroup->setChecked(true);
        ui->pb_qualities->setChecked(false);
        ui->pb_popularity->setChecked(false);
    }
    QVector<QString> flowerGroup = flowersDb.value(0); // список групп цветов из первой колонки

    flowerGroup.sort(); // сортировка по алфавиту
    QString lastFlowerGroup{}; // для объединения всех повторяющихся значений и создания только уникальных
    for(const auto group: flowerGroup)
    {
        if(group != lastFlowerGroup) // если новая уникальная группа, добавляем
        {
            lastFlowerGroup = group;
            int newRowNum = ui->tw_filterList->rowCount();
            ui->tw_filterList->insertRow(newRowNum); // новая строка
            QCheckBox *chBox = new QCheckBox(group, this); // новый чекбокс

            connect(chBox, &QCheckBox::clicked, this, &MainWindow::processFlowGroupVector); // связь между выбором чекбокса и фильтрацией
            ui->tw_filterList->setCellWidget(newRowNum,  0, chBox); // добавление в таблицу фильтров
        }
    }
}

// Слот on_pb_container_clicked отвечает за обработку нажатия на кнопку выбора контейнера.
// На вход принимает булевое значение, указывающее, установлена ли кнопка.
// На выход ничего не возвращает.
void MainWindow::on_pb_container_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(0);
    if(checked)
    {
        ui->pb_container->setChecked(true);
        ui->pb_flowerGroup->setChecked(false);
        ui->pb_qualities->setChecked(false);
        ui->pb_popularity->setChecked(false);
    }
    QVector<QString> container = flowersDb.value(3);

    container.sort();
    QString lastContainer{};
    for(const auto cont: container)
    {
        if(cont != lastContainer)
        {
            lastContainer = cont;
            int newRowNum = ui->tw_filterList->rowCount();
            ui->tw_filterList->insertRow(newRowNum);
            QCheckBox *chBox = new QCheckBox(cont, this);
            connect(chBox, &QCheckBox::clicked, this, &MainWindow::processContainerVector);
            ui->tw_filterList->setCellWidget(newRowNum,  0, chBox);
        }
    }
}

// Слот on_pb_popularity_clicked отвечает за обработку нажатия на кнопку выбора популярности.
// На вход принимает булевое значение, указывающее, установлена ли кнопка.
// На выход ничего не возвращает.
void MainWindow::on_pb_popularity_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(2);
    if(checked)
    {
        ui->pb_container->setChecked(false);
        ui->pb_flowerGroup->setChecked(false);
        ui->pb_qualities->setChecked(false);
        ui->pb_popularity->setChecked(true);
    }

    QRadioButton *rbMaxBegin = new QRadioButton("Most popular",this);
    connect(rbMaxBegin, &QCheckBox::clicked, this, &MainWindow::processPopularityVector);
    ui->tw_filterList->setCellWidget(0,  0, rbMaxBegin);
    QRadioButton *rbMaxEnd = new QRadioButton("Least popular", this);
    connect(rbMaxEnd, &QCheckBox::clicked, this, &MainWindow::processPopularityVector);
    ui->tw_filterList->setCellWidget(1,  0, rbMaxEnd);
}

// Слот on_pb_qualities_clicked отвечает за обработку нажатия на кнопку выбора качества.
// На вход принимает булевое значение, указывающее, установлена ли кнопка.
// На выход ничего не возвращает.
void MainWindow::on_pb_qualities_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(0);
    if(checked)
    {
        ui->pb_container->setChecked(false);
        ui->pb_flowerGroup->setChecked(false);
        ui->pb_qualities->setChecked(true);
        ui->pb_popularity->setChecked(false);
    }
    QVector<QString> qualities = flowersDb.value(5);

    qualities.sort();
    QString lastQuality{};
    for(const auto quality: qualities)
    {
        if(quality != lastQuality)
        {
            lastQuality = quality;
            int newRowNum = ui->tw_filterList->rowCount();
            ui->tw_filterList->insertRow(newRowNum);
            QCheckBox *chBox = new QCheckBox(quality, this);
            connect(chBox, &QCheckBox::clicked, this, &MainWindow::processQualityVector);
            ui->tw_filterList->setCellWidget(newRowNum,  0, chBox);
        }
    }
}

// Слот on_toolButton_clicked отвечает за обработку нажатия на кнопку сравнения цветов.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void MainWindow::on_toolButton_clicked()
{
    if(fcCompareVector.length()) // если больше 0
    {
        compFlow->setCompVector(fcCompareVector);
        compFlow->show();
    }
}

// Слот on_toolButton_2_clicked отвечает за обработку нажатия на кнопку очистки сравнения цветов.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void MainWindow::on_toolButton_2_clicked()
{
    for(auto fc: fcCompareVector)
    {
        fc->unChecked();
    }

    fcCompareVector.clear();
    compFlow->clearWidgets();
}

// Метод addToCompare отвечает за добавление цветов для сравнения.
// На вход принимает булевое значение, указывающее, выбран ли элемент.
// На выход ничего не возвращает.
void MainWindow::addToCompare(bool isChecked)
{
    FlowerContainer *currFc = qobject_cast<FlowerContainer*>(sender()); // определение конкретного контейнера
    if(isChecked)
    {
        fcCompareVector << currFc;
    }
    else
    {
        fcCompareVector.remove(fcCompareVector.indexOf(currFc));
    }
}

// Слот on_toolButton_3_clicked отвечает за обработку нажатия на кнопку входа в систему.
// На вход ничего не принимает.
// На выход ничего не возвращает.
void MainWindow::on_toolButton_3_clicked()
{
    gardnerWindow->show(); // отображение окна авторизации
}
