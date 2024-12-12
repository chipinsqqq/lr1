#include "header.h"

// Добавление элемента в голову двусвязного списка
void dlistInsertHead(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile, const string& operation) {
    DoubleListNode* newNode = new DoubleListNode{value, head, nullptr};
    if (head) head->prev = newNode;
    head = newNode;
    if (!tail) tail = newNode;
    outFile << operation << " " << value << endl;
    cout << "Элемент '" << value << "' добавлен в двусвязный список (в голову)." << endl;
}

// Добавление элемента в хвост двусвязного списка
void dlistInsertTail(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile, const string& operation) {
    DoubleListNode* newNode = new DoubleListNode{value, nullptr, tail};
    if (tail) tail->next = newNode;
    tail = newNode;
    if (!head) head = newNode;
    outFile << operation << " " << value << endl;
    cout << "Элемент '" << value << "' добавлен в двусвязный список (в хвост)." << endl;
}

// Удаление элемента из начала списка
void dlistDeleteHead(DoubleListNode*& head, DoubleListNode*& tail, ofstream& outFile) {
    if (!head) {
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    DoubleListNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr; // Если список стал пустым

    outFile << "DDELHEAD " << temp->value << endl;
    cout << "Элемент '" << temp->value << "' удалён из начала двусвязного списка." << endl;
    delete temp;
}

// Удаление элемента из конца списка
void dlistDeleteEnd(DoubleListNode*& head, DoubleListNode*& tail, ofstream& outFile) {
    if (!tail) {
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    DoubleListNode* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr; // Если список стал пустым

    outFile << "DDELEND " << temp->value << endl;
    cout << "Элемент '" << temp->value << "' удалён из конца двусвязного списка." << endl;
    delete temp;
}

// Удаление элемента по значению
void dlistDelete(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile) {
    DoubleListNode* current = head;
    while (current && current->value != value) {
        current = current->next;
    }

    if (!current) {
        cout << "Элемент '" << value << "' не найден." << endl;
        return;
    }

    if (current->prev) current->prev->next = current->next;
    else head = current->next;

    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;

    delete current;
    outFile << "DELETE " << value << endl;
    cout << "Элемент '" << value << "' удалён из двусвязного списка." << endl;
}

// Поиск элемента
void dlistGet(DoubleListNode* head, const string& value, ofstream& outFile) {
    while (head) {
        if (head->value == value) {
            cout << "Число '" << value << "' найдено в двусвязном списке." << endl;
            outFile << "DGET " << value << ": found" << endl;
            return;
        }
        head = head->next;
    }
    cout << "Число '" << value << "' не найдено в двусвязном списке." << endl;
    outFile << "DGET " << value << ": not found" << endl;
}

// Печать содержимого двусвязного списка
void dlistPrint(DoubleListNode* head, ofstream& outFile, const string& operation) {
    if (!head) {
        cout << "Список пуст!" << endl;
        outFile << operation << ": empty" << endl;
        return;
    }

    cout << "Содержимое двусвязного списка: ";
    outFile << operation << ": ";
    while (head) {
        cout << head->value << " ";
        outFile << head->value << " ";
        head = head->next;
    }
    cout << endl;
    outFile << endl;
}
