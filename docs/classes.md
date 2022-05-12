# Table of contents

- [1. Модуль `table`](#1--table)
  - [1.1 `Table`](#11-table)
    - [`Table(QString tablename)`](#tableqstring-tablename)
    - [`Table(QString tablename, QString filename)`](#tableqstring-tablename-qstring-filename)
    - [`~Table()`](#table)
    - [`std::vector<QVariant *> getColumn(int columnNumber)`](#stdvectorqvariant--getcolumnint-columnnumber)
    - [`std::vector<QVariant *> getColumn()`](#stdvectorqvariant--getcolumn)
    - [`std::vector<QVariant *> getRow(int rowNumber)`](#stdvectorqvariant--getrowint-rownumber)
    - [`std::vector<QVariant *> getRow()`](#stdvectorqvariant--getrow)
    - [`std::vector<std::vector<QVariant *>> getMatrix(int beginColumn, int beginRow, int endColumn, int endRow)`](#stdvectorstdvectorqvariant--getmatrixint-begincolumn-int-beginrow-int-endcolumn-int-endrow)
    - [`std::vector<std::vector<QVariant *>> getMatrix()`](#stdvectorstdvectorqvariant--getmatrix)
    - [`QVariant * getCell(int columnNumber, int rowNumber)`](#qvariant--getcellint-columnnumber-int-rownumber)
    - [`void writeColumn(std::vector<QVariant *> Column)`](#void-writecolumnstdvectorqvariant--column)
    - [`void writeColumn(std::vector<QVariant *> Column, int columnNumber)`](#void-writecolumnstdvectorqvariant--column-int-columnnumber)
    - [`void writeColumn(std::vector<QVariant *> Column, int columnNumber, int beginRow)`](#void-writecolumnstdvectorqvariant--column-int-columnnumber-int-beginrow)
    - [`void writeRow(std::vector<QVariant *> Row)`](#void-writerowstdvectorqvariant--row)
    - [`void writeRow(std::vector<QVariant *> Row, int rowNumber)`](#void-writerowstdvectorqvariant--row-int-rownumber)
    - [`void writeRow(std::vector<QVariant *> Row, int rowNumber, int beginColumn)`](#void-writerowstdvectorqvariant--row-int-rownumber-int-begincolumn)
    - [`void writeCell(QVariant * value, int columnNumber, int rowNumber)`](#void-writecellqvariant--value-int-columnnumber-int-rownumber)
  - [1.2 `TableManager`](#12-tablemanager)
    - [`TableManager()`](#tablemanager)
    - [`~TableManager()`](#tablemanager)
    - [`void openTable(QString tablename)`](#void-opentableqstring-tablename)
    - [`void openTable(QString tablename, QString filename)`](#void-opentableqstring-tablename-qstring-filename)
    - [`void closeTable(QString tablename)`](#void-closetableqstring-tablename)
- [2. Модуль `data`](#2--data)
  - [2.1 `DataStorage`](#21-datastorage)
    - [`DataStorage()`](#datastorage)
    - [`void addValue(QString key, T value, QString name, QString description, VariableState state = REQUIRED, Calculators::Calculator sourceCalculator = Calculators::NONE)`](#void-addvalueqstring-key-t-value-qstring-name-qstring-description-variablestate-state--required-calculatorscalculator-sourcecalculator--calculatorsnone)
    - [`void addValue<T>(QString key, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE)`](#void-addvaluetqstring-key-qstring-name-qstring-description-calculatorscalculator-sourcecalculator--calculatorsnone)
    - [`Variable * getValue(QString key)`](#variable--getvalueqstring-key)
    - [`T value(QString key)`](#t-valueqstring-key)
    - [`void setValue(QString key, T value)`](#void-setvalueqstring-key-t-value)
    - [`void writeValue(QString key, T value)`](#void-writevalueqstring-key-t-value)
    - [`bool hasKey(QString key)`](#bool-haskeyqstring-key)
    - [`void setVariablesReplaceable(std::vector<QString> keys)`](#void-setvariablesreplaceablestdvectorqstring-keys)
    - [`int getGroupId(QString key)`](#int-getgroupidqstring-key)
    - [`std::vector<QString> getKeysByGroupId(int groupId)`](#stdvectorqstring-getkeysbygroupidint-groupid)
    - [`double operator[] (QString key)`](#double-operator-qstring-key)
  - [2.2 `enum VariableState`](#22-enum-variablestate)
    - [`REQUIRED`](#required)
    - [`CONST`](#const)
    - [`OPTIONAL`](#optional)
  - [2.3 `Variable`](#23-variable)
    - [`Variable(QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE)`](#variableqstring-name-qstring-description-calculatorscalculator-sourcecalculator--calculatorsnone)
    - [`Variable(T value, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE, VariableState state = REQUIRED)`](#variablet-value-qstring-name-qstring-description-calculatorscalculator-sourcecalculator--calculatorsnone-variablestate-state--required)
    - [`void value(T value)`](#void-valuet-value)
    - [`T value()`](#t-value)
    - [`bool isEmpty()`](#bool-isempty)
    - [`QString type()`](#qstring-type)
    - [`QString name()`](#qstring-name)
    - [`QString desc()`](#qstring-desc)
    - [`Calculators::Calculator calc()`](#calculatorscalculator-calc)
    - [`VariableState state()`](#variablestate-state)
- [3. Модуль `calculator`](#3--calculator)
  - [3.1 `Calculator`](#31-calculator)
    - [`Calculator(DataStorage * storage)`](#calculatordatastorage--storage)
    - [`double calculate()`](#double-calculate)
  - [3.2 `namespace CalculatorFactory`](#32-namespace-calculatorfactory)
    - [`Calculator * createCalculator(DataStorage * storage, Calculators::Calculator type)`](#calculator--createcalculatordatastorage--storage-calculatorscalculator-type)
  - [3.3 `enum Calculators::Calculator`](#33-enum-calculatorscalculator)
    - [`NONE`](#none)
    - [`HEATING_VALUE`](#heating_value)
    - [`HEAT_CAPACITY`](#heat_capacity)
    - [`EXCESS_AIR_RATIO`](#excess_air_ratio)

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

### `void addValue(QString key, T value, QString name, QString description, VariableState state = REQUIRED, Calculators::Calculator sourceCalculator = Calculators::NONE)`

Создает переменную с указанным значением, именем и описанием и сохраняет ее под ключом `key`.

Параметр `sourceCalculator` указывает, из какого калькулятора можно получить значение этой переменной

### `void addValue<T>(QString key, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE)`

Создает пустую переменную типа `T`

### `Variable * getValue(QString key)`

Возвращает переменную под ключом `key` без приведения к типу

### `T value(QString key)`

Возвращает значение переменной, сохраненной под ключом `key`

### `void setValue(QString key, T value)`

Устанавливает значение существующей переменной под ключом `key`

### `void writeValue(QString key, T value)`

Устанавливает значение переменной под ключом `key`, если она существует. Иначе создает новую переменную и записывает в нее значение

### `bool hasKey(QString key)`

Проверяет, есть ли в хранилище переменные с указанным ключом

### `void setVariablesReplaceable(std::vector<QString> keys)`

Делает переменные под указанными ключами взаимозаменяемыми (в пользовательском интерфейсе будет предложено заполнить только одну из этих переменных)

### `int getGroupId(QString key)`

Возвращает id группы взаимозаменяемых переменных, в которой содержится переменная с ключом `key`

### `std::vector<QString> getKeysByGroupId(int groupId)`

Возвращает список ключей, содержащихся в группе взаимозаменяемых переменных с указанным id

### `double operator[] (QString key)`

Возвращает значение переменной, сохраненной под ключом `key`. Значение будет приведено к `double`. Оператор предназначен для сокращения кода, запрашивающего значение для вычислений

## 2.2 `enum VariableState`

Используется для определения состояния переменной.

### `REQUIRED`

### `CONST`

### `OPTIONAL`

## 2.3 `Variable`

### `Variable(QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE)`

### `Variable(T value, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE, VariableState state = REQUIRED)`

Конструктор, создающий переменную с незаданным значением

### `void value(T value)`

Устанавливает значение переменной

### `T value()`

Возвращает значение переменной, приведенное к типу `T`

### `bool isEmpty()`

Проверяет, содержит ли переменная значение

### `QString type()`

Возвращает тип переменной

### `QString name()`

Возвращает название переменной

### `QString desc()`

Возвращает описание переменной

### `Calculators::Calculator calc()`

Возвращает калькулятор, результатом вычислений которого является эта переменная

### `VariableState state()`

Возвращает состояние переменной

# 3. Модуль `calculator`

## 3.1 `Calculator`

Класс-интерфейс, через который можно обращаться к любому созданному калькулятору

### `Calculator(DataStorage * storage)`

### `double calculate()`

Возвращает результат вычислений

## 3.2 `namespace CalculatorFactory`

### `Calculator * createCalculator(DataStorage * storage, Calculators::Calculator type)`

Возвращает новый калькулятор, привязанный к `storage`. Тип калькулятора указывается в параметре `type`

## 3.3 `enum Calculators::Calculator`

Хранит список видов калькуляторов

### `NONE`

### `HEATING_VALUE`

### `HEAT_CAPACITY`

### `EXCESS_AIR_RATIO`

`STOICHIOMETRIC_RATIO`
