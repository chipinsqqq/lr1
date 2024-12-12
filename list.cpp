#include "header.h"

// Добавление элемента в голову списка
void listInsertHead(ListNode*& head, const string& value, ofstream& outFile, const string& operation) {
    ListNode* newNode = new ListNode{value, head};
    head = newNode;
    outFile << operation << " " << value << endl;
    cout << "Элемент '" << value << "' добавлен в список (в голову)." << endl;
}

// Добавление элемента в хвост списка
void listInsertTail(ListNode*& head, const string& value, ofstream& outFile, const string& operation) {
    ListNode* newNode = new ListNode{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    outFile << operation << " " << value << endl;
    cout << "Элемент '" << value << "' добавлен в список (в хвост)." << endl;
}

// Удаление элемента по значению
void listDelete(ListNode*& head, const string& value, ofstream& outFile) {
    if (!head) {
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    if (head->value == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        outFile << "DELETE " << value << endl;
        cout << "Элемент '" << value << "' удалён." << endl;
        return;
    }

    ListNode* current = head;
    while (current->next && current->next->value != value) {
        current = current->next;
    }

    if (current->next) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        outFile << "DELETE " << value << endl;
        cout << "Элемент '" << value << "' удалён." << endl;
    } else {
        cout << "Элемент '" << value << "' не найден." << endl;
    }
}

// Удаление элемента из начала списка
void listDeleteHead(ListNode*& head, ofstream& outFile) {
    if (!head) {
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    ListNode* temp = head;
    head = head->next; // Смещаем указатель головы на следующий элемент
    outFile << "LDELHEAD " << temp->value << endl;
    cout << "Элемент '" << temp->value << "' удалён из начала списка." << endl;
    delete temp; // Удаляем старую голову
}


// Удаление элемента из конца списка
void listDeleteEnd(ListNode*& head, ofstream& outFile) {
    if (!head) {
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    if (!head->next) { // Если в списке только один элемент
        outFile << "LDELEND " << head->value << endl;
        cout << "Элемент '" << head->value << "' удалён из конца списка." << endl;
        delete head;
        head = nullptr;
        return;
    }

    ListNode* current = head;
    while (current->next->next) { // Находим предпоследний элемент
        current = current->next;
    }

    outFile << "LDELEND " << current->next->value << endl;
    cout << "Элемент '" << current->next->value << "' удалён из конца списка." << endl;
    delete current->next; // Удаляем последний элемент
    current->next = nullptr; // Обновляем указатель последнего элемента
}

// Поиск элемента
void listGet(ListNode* head, const string& value, ofstream& outFile) {
    while (head) {
        if (head->value == value) {
            cout << "Число '" << value << "' найдено." << endl;
            outFile << "LGET " << value << ": found" << endl;
            return;
        }
        head = head->next;
    }
    cout << "Число '" << value << "' не найдено." << endl;
    outFile << "LGET " << value << ": not found" << endl;
}

// Печать содержимого списка
void listPrint(ListNode* head, ofstream& outFile, const string& operation) {
    if (!head) {
        cout << "Список пуст!" << endl;
        outFile << operation << ": empty" << endl;
        return;
    }

    cout << "Содержимое списка: ";
    outFile << operation << ": ";
    while (head) {
        cout << head->value << " ";
        outFile << head->value << " ";
        head = head->next;
    }
    cout << endl;
    outFile << endl;
}
