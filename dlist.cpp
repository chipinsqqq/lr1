#include "header.h"

// Добавление элемента в голову двусвязного списка
// Создает новый узел и добавляет его в начало списка
void dlistInsertHead(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile, const string& operation) {
    DoubleListNode* newNode = new DoubleListNode{value, head, nullptr}; // Создаем новый узел
    if (head) head->prev = newNode; // Устанавливаем связь между новым узлом и текущей головой
    head = newNode; // Новый узел становится головой
    if (!tail) tail = newNode; // Если список был пуст, хвост также указывает на новый узел
    outFile << operation << " " << value << endl; // Логируем операцию
    cout << "Элемент '" << value << "' добавлен в двусвязный список (в голову)." << endl;
}

// Добавление элемента в хвост двусвязного списка
// Создает новый узел и добавляет его в конец списка
void dlistInsertTail(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile, const string& operation) {
    DoubleListNode* newNode = new DoubleListNode{value, nullptr, tail}; // Создаем новый узел
    if (tail) tail->next = newNode; // Устанавливаем связь между текущим хвостом и новым узлом
    tail = newNode; // Новый узел становится хвостом
    if (!head) head = newNode; // Если список был пуст, голова также указывает на новый узел
    outFile << operation << " " << value << endl; // Логируем операцию
    cout << "Элемент '" << value << "' добавлен в двусвязный список (в хвост)." << endl;
}

// Удаление элемента из начала списка
// Удаляет узел из начала списка и освобождает память
void dlistDeleteHead(DoubleListNode*& head, DoubleListNode*& tail, ofstream& outFile) {
    if (!head) { // Проверяем, пуст ли список
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    DoubleListNode* temp = head; // Сохраняем текущую голову
    head = head->next; // Перемещаем голову на следующий узел
    if (head) head->prev = nullptr; // Удаляем связь с предыдущим узлом
    else tail = nullptr; // Если список стал пустым, сбрасываем хвост

    outFile << "DDELHEAD " << temp->value << endl; // Логируем операцию
    cout << "Элемент '" << temp->value << "' удалён из начала двусвязного списка." << endl;
    delete temp; // Освобождаем память
}

// Удаление элемента из конца списка
// Удаляет узел из конца списка и освобождает память
void dlistDeleteEnd(DoubleListNode*& head, DoubleListNode*& tail, ofstream& outFile) {
    if (!tail) { // Проверяем, пуст ли список
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    DoubleListNode* temp = tail; // Сохраняем текущий хвост
    tail = tail->prev; // Перемещаем хвост на предыдущий узел
    if (tail) tail->next = nullptr; // Удаляем связь с текущим узлом
    else head = nullptr; // Если список стал пустым, сбрасываем голову

    outFile << "DDELEND " << temp->value << endl; // Логируем операцию
    cout << "Элемент '" << temp->value << "' удалён из конца двусвязного списка." << endl;
    delete temp; // Освобождаем память
}

// Удаление элемента по значению
// Находит узел с указанным значением и удаляет его
void dlistDelete(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile) {
    DoubleListNode* current = head;
    while (current && current->value != value) { // Ищем узел с заданным значением
        current = current->next;
    }

    if (!current) { // Если узел не найден
        cout << "Элемент '" << value << "' не найден." << endl;
        return;
    }

    if (current->prev) current->prev->next = current->next; // Устанавливаем связь между предыдущим и следующим узлом
    else head = current->next; // Если удаляем голову, сдвигаем её

    if (current->next) current->next->prev = current->prev; // Устанавливаем связь между следующим и предыдущим узлом
    else tail = current->prev; // Если удаляем хвост, сдвигаем его

    delete current; // Удаляем узел
    outFile << "DELETE " << value << endl; // Логируем операцию
    cout << "Элемент '" << value << "' удалён из двусвязного списка." << endl;
}

// Поиск элемента
// Ищет элемент в списке и выводит результат
void dlistGet(DoubleListNode* head, const string& value, ofstream& outFile) {
    while (head) { // Перебираем элементы списка
        if (head->value == value) { // Если найдено совпадение
            cout << "Число '" << value << "' найдено в двусвязном списке." << endl;
            outFile << "DGET " << value << ": found" << endl;
            return;
        }
        head = head->next; // Переходим к следующему узлу
    }
    cout << "Число '" << value << "' не найдено в двусвязном списке." << endl;
    outFile << "DGET " << value << ": not found" << endl;
}

// Печать содержимого двусвязного списка
// Выводит все элементы списка
void dlistPrint(DoubleListNode* head, ofstream& outFile, const string& operation) {
    if (!head) { // Проверяем, пуст ли список
        cout << "Список пуст!" << endl;
        outFile << operation << ": empty" << endl;
        return;
    }

    cout << "Содержимое двусвязного списка: ";
    outFile << operation << ": ";
    while (head) { // Перебираем элементы списка
        cout << head->value << " ";
        outFile << head->value << " ";
        head = head->next; // Переходим к следующему узлу
    }
    cout << endl;
    outFile << endl;
}
