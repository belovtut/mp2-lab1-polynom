# Лабораторная работа №1 "Алгебра полиномов"
## Цели и задачи

__Цель данной работы__  — изучение методов компьютерной обработки полиномов, а также приобретение студентами практических навыков и опыта командной разработки.\
Для достижения цели предлагается в команде из трёх человек осуществить разработку программной системы для выполнения алгебраических операций над полиномами от трёх переменных.

Выполнение работы предполагает решение следующих задач:

  1. Формирование технического задания (ТЗ) на проект.
  2. Анализ предметной области, выделение объектов, основных операций и алгоритмов.
  3. Описание модели выделенных объектов.
  4. Разработка проекта программной системы.
  5. Разработка и реализация модульных тестов.
  6. Презентация проекта заказчику.

## Общая информация
### Команда проекта
Белов Артём, Капустин Иван, Корнеева Екатерина.

### Длительность проекта
Разработка проекта займёт 8 недель весеннего семестра.

### Специфика проекта
Работа над проектом разделена между участниками команды и добросовестно осуществляется каждым участником.\
В процессе работы над проектом команда должна пройти через основные этапы жизненного цикла программного продукта.

## Требования к проекту
### Хранение полиномов
- Полиномы хранятся в виде списка.
- Полиномы должны быть доступны для хранения в различных видах таблиц:
  - Линейная на массиве.
  - Линейная на списке.
  - Упорядоченная на массиве.
  - АВЛ-дерево или красно-чёрное дерево.
  - Две хеш-таблицы.

### Операции над полиномом
- Вычисление полинома в точке.
- Умножение полинома на константу.

### Операции в выражениях из полиномов (с использованием постфиксной формы)
- Сложение полиномов.
- Вычитание полиномов.
- Перемножение полиномов.

### Операции над таблицами
- Добавление и удаление полинома (во всех таблицах одновременно).
- Поиск полинома в активной таблице (во время вычисления выражений).
- Вывод на экран активной таблицы (в формате, как минимум, двух столбцов: имя полинома и строковое представление).

## Список объектов и основных алгоритмов
### Объекты
- Шаблонный класс `TLinkedList<T>`, описывающий реализацию связного списка. Предоставляет эффективное управление
последовательностью элементов. Внутренний узел списка `Node` содержит значение элемента и указатель на следующий узел списка.
- Структура `TMonom`, предназначенная для создания экземпляра типа моном.
- Класс `TPolynom`, предназначенный для создания экземпляра типа полином и выполнения преобразований и вычислений с полиномами, представленными в виде списка мономов.
- Класс `TStack`, представляющий собой реализацию абстрактной структуры данных, основанной на принципе «Last-In-First-Out». Обеспечивает использование операций добавления, извлечения и доступа к элементам стека.
- Класс `TPostfix`, предназначенный для обработки и вычисления арифметических выражений в инфиксной и постфиксной формах.

### Основные алгоритмы
- Преобразование инфиксной формы в постфиксную: `ToPostfix`.
- Расчёт значения полинома в указанной точке: `calculate`.
- Умножение полинома на константу.
- Операции сложения, вычитания и перемножения полиномов.

## Описание моделей объектов и основных алгоритмов
### Описание моделей объектов
- Класс `TLinkedList` представляет собой контейнер и реализует связный список с такими базовыми операциями, как добавление элемента в конец списка, удаление элемента по индексу, доступ к элементам по индексу, перегрузка операторов сравнения, копирование и перемещение. Также в представленном классе определён вложенный класс Iterator, предоставляющий возможность итерации по элементам списка.
- Структура `TMonom` предназначена для создания экземпляра типа моном и поддерживает операции умножения двух одночленов, позволяет выводить моном в поток вывода, а также имеет	метод `calculate`, вычисляющий значения одночлена при заданных значениях переменных x, y, z.
- Класс `TPolynom` предназначен для создания экземпляра типа полином и выполнения преобразований и вычислений с полиномами, представленными в виде списка мономов.
- Класс `TStack` представляет собой реализацию стека с поддержкой следующих операций:
  - Метод `top` возвращает значение верхнего элемента без извлечения.
  - Метод `pop` извлекает и возвращает значение верхнего элемента.
  - Метод `push` добавляет элемент в верх стека.
  - Метод `is_empty` проверяет, пуст ли стек.
  - Метод `size` возвращает текущий размер стека.
- Класс `TPostfix` предоставляет инструменты для обработки и вычисления арифметических выражений в инфиксной и постфиксной формах. Он содержит методы для получения инфиксной и постфиксной форм, метод `Parse`, преобразующий инфиксное выражение в последовательность лексем (операндов и операторов) с учётом приоритетов операторов и расстановки скобок; `ToPostfix`, использующий результат работы `Parse`, чтобы преобразовать инфиксное выражение в постфиксное; метод `Calculate`, вычисляющий значение постфиксного выражения, при этом используя стек для хранения операндов и выполнения операций.

### Описание основных алгоритмов
#### Преобразование инфиксной формы в постфиксную
Алгоритм преобразования инфиксной формы выражений в постфиксную объединяет методы `Parse` и `ToPostfix` класса `TPostfix`, где метод `Parse` преобразует инфиксное выражение в последовательность лексем, учитывая приоритеты операторов и расстановку скобок, а метод `ToPostfix` применяет результат работы `Parse` для преобразования инфиксного выражения в постфиксное.\
При преобразовании в постфиксную форму используется стек для управления операторами и их приоритетами. Лексемы добавляются в выходную строку в соответствии с правилами преобразования: левые скобки помещаются в стек, операторы сравниваются по приоритету с операторами, находящимися в стеке, и добавляются в стек или выходную строку, а операнды напрямую добавляются в выходную строку.

#### Расчёт значения полинома в указанной точке
Расчёт значения полинома в указанной точке производится за счёт последовательного выполнения арифметических операций после подстановки значений переменных.

#### Умножение полинома на константу
Умножение полинома на константу выполняется посредством умножения всех коэффициентов полинома на указанное число.

#### Операции сложения, вычитания и перемножения полиномов
- Сложение полиномов
  - Каждый моном из второго полинома добавляется к текущему полиному.
  - Мономы с одинаковыми степенями объединяются.
  - Мономы с нулевыми коэффициентами удаляются.
- Вычитание полиномов
  - Каждый моном из второго полинома умножается на (-1) и добавляется к текущему полиному.
- Перемножение полиномов
  - Каждый моном из первого полинома умножается на каждый моном из второго полинома.
  - Выполняется преобразование полученного полинома: мономы с одинаковыми степенями объединяются, а мономы с нулевыми коэффициентами удаляются.

## Структуры данных для хранения полиномов
Для хранения полиномов будут использоваться таблицы – это структуры данных, предназначенные для эффективного управления множеством полиномов. Полиномы хранятся во всех таблицах одновременно, ключом является имя.

#### Виды таблиц:

1. __Линейная таблица на массиве:__ Использует массив для хранения полиномов, доступ к элементам осуществляется по индексу массива. Поскольку размер массива фиксирован заранее, этот способ подходит в случаях, когда количество элементов заранее известно или ограничено.
2. __Линейная таблица на списке:__ Основана на связном списке, в такой таблице полиномы могут легко добавляться и удаляться, и она предоставляет гибкость в управлении данными. Однако доступ к элементам может быть медленнее, чем в массиве, так как требуется последовательный переход от одного узла к другому.
3. __Упорядоченная таблица на массиве:__ В этом типе таблицы полиномы хранятся в массиве, отсортированном в лексикографическом порядке по именам полиномов. Для сравнения полиномов используется их имя. Такой порядок обеспечивает эффективный поиск элементов благодаря использованию бинарного поиска вместо линейного. Однако, операции вставки и удаления могут потребовать перемещения большого количества элементов в массиве.
4. __Дерево (АВЛ или красно-чёрное):__ Это сбалансированное бинарное дерево, где каждый узел содержит информацию о полиноме и имеет не более двух дочерних узлов. Это обеспечивает эффективный поиск и удаление элементов.
5. __Хэш-таблицы:__ Используют хэш-функцию для быстрого доступа к элементам по ключу. В хэш-таблице ключи полиномов хэшируются, чтобы определить индекс в массиве, где хранится информация о полиномах. Это обеспечивает быстрый доступ к элементам. Хэш-таблицы могут быть реализованы с использованием открытого хэширования или метода цепочек.

#### Операции над таблицами:

- __Добавление полинома:__ При добавлении полинома он должен вставляться во все таблицы одновременно.
- __Удаление полинома:__ При удалении полинома он должен удаляться из всех таблиц.
- __Поиск полинома:__ Поиск полинома выполняется только в активной таблице. Эта операция используется в процессе вычисления выражений, составленных из имен полиномов.

#### Отображение активной таблицы
Активная таблица, выбранная пользователем, должна выводиться на экран. Каждый полином в таблице должен отображаться в формате, как минимум, двух столбцов: имя полинома и его строковое представление.

## Общая структура проекта
Структура проекта:

  - `gtest` — библиотека Google Test.
  - `base` — каталог с основным проектом ЛР.
  - `base_test` — каталог с модульными тестами к проекту.
  - `README.md` — техническое задание (ТЗ) на проект.
  - `mp2-lab1-polynom.sln` - файл с решением (solution) для Microsoft Visual Studio 2022 (скоро будет загружен)
  - Служебные файлы
    - `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.
