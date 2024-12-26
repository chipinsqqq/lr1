#include "header.h"

// Конструктор массива
SimpleArray::SimpleArray(int cap) {
    capacity = cap;
    size = 0;
    data = new string[capacity]; // Заменено на строки
}

// Деструктор массива
SimpleArray::~SimpleArray() {
    delete[] data;
}

// Функции для работы с массивом

// Добавление элемента в конец массива
void add(SimpleArray& arr, const string& value) {
    if (arr.size == arr.capacity) {
        cout << "Ошибка: Массив заполнен!" << endl;
        return;
    }
    arr.data[arr.size++] = value;
    cout << "Добавлено: " << value << endl;
}

// Добавление элемента по строковому индексу
void addAtIndex(SimpleArray& arr, const string& index, const string& value) {
    int idx = stoi(index); // Преобразуем строку в число
    if (idx < 0 || idx > arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    if (arr.size == arr.capacity) {
        cout << "Ошибка: Массив заполнен!" << endl;
        return;
    }
    for (int i = arr.size; i > idx; i--) {
        arr.data[i] = arr.data[i - 1];
    }
    arr.data[idx] = value;
    arr.size++;
    cout << "Добавлено " << value << " на индекс " << index << endl;
}

// Удаление элемента по строковому индексу
void removeAtIndex(SimpleArray& arr, const string& index) {
    int idx = stoi(index);
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    for (int i = idx; i < arr.size - 1; i++) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
    cout << "Удалён элемент на индексе: " << index << endl;
}

// Получение элемента по строковому индексу
void getItem(const SimpleArray& arr, const string& index) {
    int idx = stoi(index);
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    cout << "Элемент на индексе " << index << ": " << arr.data[idx] << endl;
}

// Замена элемента по строковому индексу
void replaceItem(SimpleArray& arr, const string& index, const string& value) {
    int idx = stoi(index);
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    arr.data[idx] = value;
    cout << "Элемент на индексе " << index << " заменён на " << value << endl;
}

// Вывод всех элементов массива
void printArray(const SimpleArray& arr) {
    if (arr.size == 0) {
        cout << "Массив пуст!" << endl;
        return;
    }
    cout << "Массив: ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

// Получение текущего размера массива
void getLength(const SimpleArray& arr) {
    cout << "Текущий размер массива: " << arr.size << endl;
}
