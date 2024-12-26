#include "header.h"

// Конструктор хеш-таблицы
HashTable::HashTable(int s) {
    size = s;
    buckets = new int[size];      // Индексы в массиве элементов
    elements = new KeyValue[size]; // Ключи и значения
    for (int i = 0; i < size; i++) {
        buckets[i] = -1; // Инициализация бакетов как пустых
        elements[i].key = ""; // Пустой ключ
        elements[i].value = ""; // Пустое значение
    }
    elementCount = 0;
}

// Деструктор хеш-таблицы
HashTable::~HashTable() {
    delete[] buckets;
    delete[] elements;
}

// Хеш-функция
int HashTable::hashFunction(const string& key) {
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % size; // Приведение индекса к диапазону [0, size - 1]
    }
    return hash;
}

// Линейное пробирование для разрешения коллизий
int HashTable::findSlot(const string& key, bool isInsert) {
    int index = hashFunction(key); // Начальный индекс через хеш-функцию
    int originalIndex = index;
    int step = 0;

    while (buckets[index] != -1 && elements[buckets[index]].key != key) {
        if (!isInsert && elements[buckets[index]].key == "") {
            break; // Пропускаем удалённые элементы
        }
        step++;
        index = (originalIndex + step) % size; // Линейное пробирование
        if (index == originalIndex) {
            return -1; // Таблица переполнена
        }
    }
    return index;
}

// Добавление элемента
void HashTable::HSET(const string& key, const string& value, ofstream& outFile) {
    int slot = findSlot(key, true); // Найти слот с учётом хеш-функции
    if (slot == -1) {
        cout << "Ошибка: хеш-таблица переполнена!" << endl;
        return;
    }

    if (buckets[slot] != -1) {
        // Обновляем существующее значение
        int elementIndex = buckets[slot];
        elements[elementIndex].value = value;
        outFile << "HSET " << key << " " << value << endl;
        cout << "Обновлено: [" << key << "] = " << value << endl;
    } else {
        // Добавляем новый элемент
        buckets[slot] = elementCount;
        elements[elementCount].key = key;
        elements[elementCount].value = value;
        elementCount++;
        outFile << "HSET " << key << " " << value << endl;
        cout << "Добавлено: [" << key << "] = " << value << endl;
    }
}

// Удаление элемента
void HashTable::HDEL(const string& key, ofstream& outFile) {
    int slot = findSlot(key, false);
    if (slot == -1 || buckets[slot] == -1 || elements[buckets[slot]].key == "") {
        cout << "Ключ [" << key << "] не найден!" << endl;
        return;
    }

    int elementIndex = buckets[slot];
    elements[elementIndex].key = "";   // Очищаем ключ
    elements[elementIndex].value = ""; // Очищаем значение
    buckets[slot] = -1;               // Сбрасываем бакет
    outFile << "HDEL " << key << endl;
    cout << "Удалено: [" << key << "]" << endl;
}

// Получение значения по ключу
string HashTable::HGET(const string& key, ofstream& outFile) {
    int slot = findSlot(key, false);
    if (slot == -1 || buckets[slot] == -1 || elements[buckets[slot]].key == "") {
        outFile << "HGET " << key << ": not found" << endl;
        cout << "Ключ [" << key << "] не найден!" << endl;
        return "";
    }

    int elementIndex = buckets[slot];
    string value = elements[elementIndex].value;
    outFile << "HGET " << key << ": " << value << endl;
    cout << "Найдено: [" << key << "] = " << value << endl;
    return value;
}

// Печать таблицы
void HashTable::PRINT(ofstream& outFile) {
    cout << "Состояние хеш-таблицы:" << endl;
    outFile << "Состояние хеш-таблицы:" << endl;

    for (int i = 0; i < size; i++) {
        cout << "Индекс " << i << ": ";
        outFile << "Индекс " << i << ": ";

        if (buckets[i] != -1) { // Если бакет содержит элемент
            int elementIndex = buckets[i];
            cout << "[" << elements[elementIndex].key << ": " << elements[elementIndex].value << "]";
            outFile << "[" << elements[elementIndex].key << ": " << elements[elementIndex].value << "]";
        } else {
            cout << "Пусто";
            outFile << "Пусто";
        }

        cout << endl;
        outFile << endl;
    }
}
