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

Добавляет заранее созданную переменную и сохранить ее под ключом `key`

### `void addValue(QString key, T value, QString name, QString description)`

Создает новую переменную `value` типа `T` и сохранить ее под ключом `key`

### `Variable * getValue(QString key)`

Возвращает переменную под ключом `key` без приведения к типу

### `T value(QString key)`

Возвращает значение переменной, сохраненной под ключом `key`

### `void setValue(QString key, T value)`

Устанавливает значение существующей переменной под ключом `key`

### `double operator[] (QString key)`

Возвращает значение переменной, сохраненной под ключом `key`. Значение будет приведено к `double`. Оператор предназначен для сокращения кода, запрашивающего значение для вычислений

## 2.2 `Variable`

### `Variable(T value, QString name, QString description, QString sourceCalculator = QString(""), VariableState state = VARIABLE)`

### `Variable(QString name, QString description, QString sourceCalculator = QString(""))`

Конструктор, создающий переменную с незаданным значением

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

# 3. Модуль `calculator`

## 3.1 `Calculator`

Класс-интерфейс, через который можно обращаться ко любому созданному калькулятору

### `Calculator(DataStorage * storage)`

### `std::vector<QString> getRequiredVariablesList()`

Возвращает список ключей переменных, необходимых для вычислений. Создает в `DataStorage`, указанном в конструкторе записи об этих переменных

### `double calculate()`

Возвращает результат вычислений

## 3.2 `namespace CalculatorFactory`

### `Calculator * createCalculator(DataStorage * storage)`

Возвращает новый калькулятор, привязанный к `storage`. Чтобы указать требуемый тип калькулятора, в  хранилище `storage` должна содержаться запись с ключом `“CURRENT_CALCULATOR”` и с значением `QString`. 

*Допустимые значения*:

* `“HEAT_CAPACITY”`
* `“HEATING_VALUE”`
* `“EXCESS_AIR_RATIO”`



