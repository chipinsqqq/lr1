#include "header.h"

// Конструктор хеш-таблицы
HashTable::HashTable(int s) {
    size = s;
    buckets = new int[size];
    elements = new KeyValue[size];
    for (int i = 0; i < size; i++) {
        buckets[i] = -1; // Инициализация пустых бакетов
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
        hash = (hash + c) % size;
    }
    return hash + 1; // Индексация с 1
}


// Добавление элемента (ключ-значение)
void HashTable::HSET(const string& key, const string& value, ofstream& outFile) {
    int index = hashFunction(key) + 1; // Индексация начинается с 1

    // Проверяем, существует ли ключ
    for (int i = 0; i < elementCount; i++) {
        if (elements[i].key == key) {
            elements[i].value = value; // Обновляем значение
            outFile << "HSET " << key << " " << value << endl;
            cout << "Обновлено: [" << key << "] = " << value << endl;
            return;
        }
    }

    // Обработка коллизий
    while (buckets[index - 1] != -1) { // -1 для корректной работы с массивом
        index++;
        if (index > size) index = 1; // Переход на начало, если индекс превышает размер
    }

    // Добавляем новый элемент
    buckets[index - 1] = elementCount; // Сохраняем индекс элемента
    elements[elementCount] = {key, value}; // Сохраняем ключ и значение
    elementCount++;
    outFile << "HSET " << key << " " << value << endl;
    cout << "Добавлено: [" << key << "] = " << value << endl;
}



void HashTable::HDEL(const string& key, ofstream& outFile) {
    int index = hashFunction(key);

    // Если бакет пуст
    if (buckets[index] == -1) {
        cout << "Ключ [" << key << "] не найден!" << endl;
        return;
    }

    // Проверяем элементы в массиве
    bool found = false;
    for (int i = buckets[index]; i < elementCount; ++i) {
        if (elements[i].key == key) {
            elements[i].key.clear(); // Удаляем ключ
            elements[i].value.clear();
            found = true;
            cout << "Удалено: [" << key << "]" << endl;
            outFile << "HDEL " << key << endl;
        }
    }

    // Если ключ найден и удалён
    if (found) {
        buckets[index] = -1; // Сбрасываем бакет
        return;
    }

    // Если ключ не найден
    cout << "Ключ [" << key << "] не найден!" << endl;
}


// Получение значения элемента по ключу
string HashTable::HGET(const string& key, ofstream& outFile) {
    int index = hashFunction(key);

    // Поиск ключа
    for (int i = buckets[index]; i != -1; i = elements[i].key.empty() ? -1 : i + 1) {
        if (elements[i].key == key) {
            outFile << "HGET " << key << ": " << elements[i].value << endl;
            cout << "Найдено: [" << key << "] = " << elements[i].value << endl;
            return elements[i].value;
        }
    }

    outFile << "HGET " << key << ": not found" << endl;
    cout << "Ключ [" << key << "] не найден!" << endl;
    return "";
}

// Печать таблицы
void HashTable::PRINT(ofstream& outFile) {
    for (int i = 1; i <= size; i++) { // Индексация от 1
        cout << "Индекс " << i << ": ";
        outFile << "Индекс " << i << ": ";
        if (buckets[i - 1] != -1) { // Проверяем наличие элемента
            int elementIndex = buckets[i - 1];
            cout << "[" << elements[elementIndex].key << ": " << elements[elementIndex].value << "] ";
            outFile << "[" << elements[elementIndex].key << ": " << elements[elementIndex].value << "] ";
        } else {
            cout << "Пусто";
            outFile << "Пусто";
        }
        cout << endl;
        outFile << endl;
    }
}


