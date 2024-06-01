# Documentation
### Список функций и методов

#### Файл: `flowercard.h`

1. **FlowerCard(QWidget *parent = nullptr)**
   - Конструктор класса FlowerCard.
   - **На вход:** указатель на родительский виджет.
   - **На выход:** ничего не возвращает.

2. **~FlowerCard()**
   - Деструктор класса FlowerCard.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

3. **void setFlowContainer(FlowerContainer *p_fc)**
   - Метод для установки контейнера цветка для отображения в карточке.
   - **На вход:** указатель на FlowerContainer.
   - **На выход:** ничего не возвращает.

#### Файл: `flowercontainer.h`

1. **FlowerContainer(QWidget *parent = nullptr)**
   - Конструктор класса FlowerContainer.
   - **На вход:** указатель на родительский виджет.
   - **На выход:** ничего не возвращает.

2. **bool setInfo(QString imgAddress, QString p_imgDesk)**
   - Метод для установки дополнительной информации для конкретного изображения.
   - **На вход:** строка с адресом изображения и строка с описанием изображения.
   - **На выход:** true, если информация установлена успешно, иначе false.

3. **void unChecked()**
   - Метод для снятия отметки с выбранных цветов.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

#### Файл: `flowerlabel.h`

1. **FlowerLabel(QWidget *parent = nullptr)**
   - Конструктор класса FlowerLabel.
   - **На вход:** указатель на родительский виджет.
   - **На выход:** ничего не возвращает.

2. **bool eventFilter(QObject *watched, QEvent *event)**
   - Метод для фильтрации событий.
   - **На вход:** указатель на объект, который отслеживает события, и указатель на событие.
   - **На выход:** true, если событие обработано, иначе false.

#### Файл: `gardnerwindow.h`

1. **GardnerWindow(QStringList flowNameList, QWidget *parent = nullptr)**
   - Конструктор класса GardnerWindow.
   - **На вход:** список имен цветов и указатель на родительский виджет.
   - **На выход:** ничего не возвращает.

2. **void logout()**
   - Метод для выхода из системы и возврата к окну авторизации.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

3. **void showGardenerMain()**
   - Метод для отображения главного профиля.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

4. **bool openGardnerFile()**
   - Метод для открытия файла садовника.
   - **На вход:** ничего не принимает.
   - **На выход:** true, если файл открыт успешно, иначе false.

5. **void hideAuthInterface()**
   - Метод для скрытия интерфейса аутентификации.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

6. **void processAuth()**
   - Метод для обработки аутентификации пользователя.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

7. **void prepareFlowTable(QSettings &gardnerSettings)**
   - Метод для подготовки таблицы цветов.
   - **На вход:** ссылка на настройки садовника.
   - **На выход:** ничего не возвращает.

8. **void prepareNotesTable(QSettings &gardnerSettings)**
   - Метод для подготовки таблицы заметок.
   - **На вход:** ссылка на настройки садовника.
   - **На выход:** ничего не возвращает.

9. **void addFlower()**
   - Метод для добавления новой строки с цветком в таблицу.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

10. **void addNote()**
    - Метод для добавления новой заметки.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

11. **void saveCurrFlower()**
    - Метод для сохранения текущих данных о цветах.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

12. **void saveCurrNote()**
    - Метод для сохранения текущих заметок.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

13. **void saveGurdnerData()**
    - Метод для сохранения данных.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

#### Файл: `mainwindow.h`

1. **MainWindow(QWidget *parent = nullptr)**
   - Конструктор класса MainWindow.
   - **На вход:** указатель на родительский виджет.
   - **На выход:** ничего не возвращает.

2. **~MainWindow()**
   - Деструктор класса MainWindow.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

3. **void showCard()**
   - Метод для отображения карточки цветка.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

4. **QStringList split(QString full)**
   - Метод для разделения строки на колонки.
   - **На вход:** строка для разделения.
   - **На выход:** список разделенных колонок в виде QStringList.

5. **void openCsv()**
   - Метод для открытия и чтения CSV файла.
   - **На вход:** ничего не принимает.
   - **На выход:** ничего не возвращает.

6. **void loadFlowers(QString subString = "")**
   - Метод для загрузки изображений цветов.
   - **На вход:** подстрока для фильтрации цветов (необязательный).
   - **На выход:** ничего не возвращает.

7. **void processFlowGroupVector(bool isChecked)**
   - Метод для фильтрации по группам.
   - **На вход:** булевое значение, указывающее, выбран ли элемент.
   - **На выход:** ничего не возвращает.

8. **void processQualityVector(bool isChecked)**
   - Метод для фильтрации по качествам.
   - **На вход:** булевое значение, указывающее, выбран ли элемент.
   - **На выход:** ничего не возвращает.

9. **void processContainerVector(bool isChecked)**
   - Метод для фильтрации по контейнерам.
   - **На вход:** булевое значение, указывающее, выбран ли элемент.
   - **На выход:** ничего не возвращает.

10. **void processPopularityVector()**
    - Метод для обработки вектора популярности.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

11. **void on_lineEdit_textChanged(const QString &arg1)**
    - Слот для обработки изменения текста в QLineEdit.
    - **На вход:** строка с новым текстом.
    - **На выход:** ничего не возвращает.

12. **void on_pb_flowerGroup_clicked(bool checked)**
    - Слот для обработки нажатия на кнопку выбора группы цветов.
    - **На вход:** булевое значение, указывающее, установлена ли кнопка.
    - **На выход:** ничего не возвращает.

13. **void on_pb_container_clicked(bool checked)**
    - Слот для обработки нажатия на кнопку выбора контейнера.
    - **На вход:** булевое значение, указывающее, установлена ли кнопка.
    - **На выход:** ничего не возвращает.

14. **void on_pb_popularity_clicked(bool checked)**
    - Слот для обработки нажатия на кнопку выбора популярности.
    - **На вход:** булевое значение, указывающее, установлена ли кнопка.
    - **На выход:** ничего не возвращает.

15. **void on_pb_qualities_clicked(bool checked)**
    - Слот для обработки нажатия на кнопку выбора качества.
    - **На вход:** булевое значение, указывающее, установлена ли кнопка.
    - **На выход:** ничего не возвращает.

16. **void on_toolButton_clicked()**
    - Слот для обработки нажатия на кнопку сравнения цветов.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

17. **void on_toolButton_2_clicked()**
    - Слот для обработки нажатия на кнопку очистки сравнения цветов.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

18. **void addToCompare(bool isChecked)**
    - Метод для добавления цветов для сравнения.
    - **На вход:** булевое значение, указывающее, выбран ли элемент.
    - **На выход:** ничего не возвращает.

19. **void on_toolButton_3_clicked()**
    - Слот для обработки нажатия на кнопку входа в систему.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

#### Файл: `compflow.h`

1. **CompFlow(QWidget *parent = nullptr)**
    - Конструктор класса CompFlow.
    - **На вход:** указатель на родительский виджет.
    - **На выход:** ничего не возвращает.

2. **~CompFlow()**
    - Деструктор класса CompFlow.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

3. **void setCompVector(QVector<FlowerContainer*> fcCompVector)**
    - Метод для установки вектора контейнеров цветов для сравнения.
    - **На вход:** вектор указателей на FlowerContainer.
    - **На выход:** ничего не возвращает.

4. **void clearWidgets()**
    - Метод для очистки виджетов в компоновке.
    - **На вход:** ничего не принимает.
    - **На выход:** ничего не возвращает.

#### Файл: `main.cpp`

1. **int main(int argc, char *argv[])**
    - Главная функция программы.
    - **На вход:** количество аргументов командной строки и массив строк аргументов.
    - **На выход:** код завершения программы.

---

# Technical Specification

## 1. Input Data

The flower database includes the following fields:

* **Flower group**: Group of flowers
* **Flower name**: Name of the flower
* **URL**: Link to detailed description
* **Containers**: Containers
* **Flower Time**: Flowering time
* **Flowers (Qualities)**: Flower qualities
* **Leaves**: Leaves
* **Life cycle**: Life cycle
* **Miscellaneous**: Miscellaneous
* **Plant Habit**: Growth habit

## 2. Core Application Features

### 2.1. Flower List View
* **Description:** Ability to view all records from the database with basic information.
* **Functionality:** Dynamic filtering by popularity, container type, flower group, and characteristics.

### 2.2. Detailed Flower Information View
* **Description:** Display full information about a selected flower.
* **Functionality:** Navigate to the URL for detailed flower description. **(Not implemented)**

### 2.3. Flower Comparison
* **Description:** Ability to select and compare multiple flowers based on various criteria (e.g., container compatibility, life cycle).
* **Functionality:** 

### 2.4. Advanced Search and Filtering
* **Description:** Search by flower names.
* **Functionality:** 

### 2.5. Personal Gardener
* **Description:** 
  - **Profile Management:** Manage your profile.
  - **Flower Addition:** Add flowers.
  - **Note Taking:** Write notes about flowers.
  - **Login/Logout:** 

## 3. Application Appearance

### 3.1. Application Name
* **Name:** BloomBaze

### 3.2. Application Icon
* **Icon:** 

### 3.3. Window Title and Icon
* **Title and Icon:** Each window in the application should display the application name and icon.

## 4. Documentation

### 4.1. User Guide
* **Description:** Detailed user manual with descriptions of all features and visual elements of the application.

### 4.2. Technical Documentation
* **Description:** Technical documentation describing the architecture of the application and the database structure.

### 4.1. User Guide
- **Description:** Detailed user manual with descriptions of all features and visual elements of the application.

### 4.2. Technical Documentation
- **Description:** Technical documentation describing the architecture of the application and the database structure.

---

## Design

You can view the design of our project on Figma:

[View Figma Design](https://www.figma.com/design/C077Fcs12xT5OE5XNlJNsw/Untitled?node-id=0-1&t=jUKsiwbvDRH4FT57-0)

### Design Previews

#### Main Window
![Main Window](https://i.imgur.com/gGPpRU4.png)

#### Flower Description
![Flower Description](https://imgur.com/LBj3pv2.png)

#### Compare Window
![Compare Window](https://imgur.com/Zkyc1F5.png)

#### Authorization Window
![Authorization Window](https://imgur.com/qFC1SGG.png)

#### Gardener Profile
![Gardener Profile](https://imgur.com/Cne19PR.png)

---
