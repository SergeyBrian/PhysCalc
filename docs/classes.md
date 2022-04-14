# 1. Модуль `table`

## 1.1 `Table`

### `Table(QString tablename)`

Конструктор для создания пустой виртуальной таблицы

### `Table(QString tablename, QString filename)`

Конструктор для создания таблицы, содержимое которой загружается из файла

### `~Table()`

### `std::vector<QVariant *> getColumn(int columnNumber)`

Возвращает колонку с указанным номером

### `std::vector<QVariant *> getColumn()`

Возвращает первую или единственную колонку в таблице

### `std::vector<QVariant *> getRow(int rowNumber)`

Возвращает строку с указанным номером

### `std::vector<QVariant *> getRow()`

Возвращает первую или единственную строку в таблице

### `std::vector<std::vector<QVariant *>> getMatrix(int beginColumn, int beginRow, int endColumn, int endRow)`

Возвращает часть таблицы, ограниченную заданными координатами

> :warning: `beginColumn` < `endColumn`; `beginRow` < `endRow`

### `std::vector<std::vector<QVariant *>> getMatrix()`

Возвращает всю таблицу

### `QVariant * getCell(int columnNumber, int rowNumber)`

Возвращает значение ячейки с указанными координатами

### `void writeColumn(std::vector<QVariant *> Column)`

Записывает переданные значения в первую колонку

### `void writeColumn(std::vector<QVariant *> Column, int columnNumber)`

Записывает переданные значения в колонку с указанным номером

### `void writeColumn(std::vector<QVariant *> Column, int columnNumber, int beginRow)`

Записывает переданные значения в колонку с указанным номером и начиная с заданной строки

### `void writeRow(std::vector<QVariant *> Row)`

Записывает переданные значения в первую строку

### `void writeRow(std::vector<QVariant *> Row, int rowNumber)`

Записывает переданные значения в строку с указанным номером

### `void writeRow(std::vector<QVariant *> Row, int rowNumber, int beginColumn)`

Записывает переданные значения в строку с указанным номером и начиная с заданной колонки

### `void writeCell(QVariant * value, int columnNumber, int rowNumber)`

Записывает значение в ячейку с указанными координатами

##  1.2 `TableManager`

### `TableManager()`

### `~TableManager()`

Вызывает `closeTable` для всех открытых таблиц, после чего удаляет их

### `void openTable(QString tablename)`

Создает пустую виртуальную таблицу, не привязанную к файлу

### `void openTable(QString tablename, QString filename)`

Создает виртуальную таблицу и заполняет ее данными из файла

### `void closeTable(QString tablename)`

Закрывает таблицу с указанным именем

# 2. Модуль `data`

## 2.1 `DataStorage`

### `DataStorage()`

### `void addValue(QString key, Variable * value)`

Добавить заранее созданную переменную и сохранить ее под ключом `key`

### `void addValue(QString key, T value, QString name, QString description)`

Создать новую переменную `value` типа `T` и сохранить ее под ключом `key`

### `T value(QString key)`

Получить значение переменной, сохраненной под ключом `key`

### `double operator[] (QString key)`

Получить значение переменной, сохраненной под ключом `key`. Значение будет приведено к `double`. Оператор предназначен для сокращения кода, запрашивающего значение для вычислений

## 2.2 `Variable`

### `Variable(T value, QString name, QString description)`

### `void value(T value)`

Устанавливает значение переменной

### `T value()`

Возвращает значение переменной, приведенное к типу `T`

### `QString type()`

Возвращает тип переменной

### `QString name()`

Возвращает название переменной

### `QString desc()`

Возвращает описание переменной
