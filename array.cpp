#include "header.h"

// Конструктор массива
SimpleArray::SimpleArray(int cap) {
    capacity = cap;
    size = 0;
    data = new int[capacity];
}

// Деструктор массива
SimpleArray::~SimpleArray() {
    delete[] data;
}

// Функции для работы с массивом
void add(SimpleArray& arr, int value) {
    if (arr.size == arr.capacity) {
        cout << "Ошибка: Массив заполнен!" << endl;
        return;
    }
    arr.data[arr.size++] = value;
    cout << "Добавлено: " << value << endl;
}

void addAtIndex(SimpleArray& arr, int index, int value) {
    if (index < 0 || index > arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    if (arr.size == arr.capacity) {
        cout << "Ошибка: Массив заполнен!" << endl;
        return;
    }
    for (int i = arr.size; i > index; i--) {
        arr.data[i] = arr.data[i - 1];
    }
    arr.data[index] = value;
    arr.size++;
    cout << "Добавлено " << value << " на индекс " << index << endl;
}

void removeAtIndex(SimpleArray& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    for (int i = index; i < arr.size - 1; i++) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
    cout << "Удалён элемент на индексе: " << index << endl;
}

void getItem(const SimpleArray& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    cout << "Элемент на индексе " << index << ": " << arr.data[index] << endl;
}

void replaceItem(SimpleArray& arr, int index, int value) {
    if (index < 0 || index >= arr.size) {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return;
    }
    arr.data[index] = value;
    cout << "Элемент на индексе " << index << " заменён на " << value << endl;
}

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

void getLength(const SimpleArray& arr) {
    cout << "Текущий размер массива: " << arr.size << endl;
}
