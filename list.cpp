#include "header.h"

// Добавление элемента в голову списка
// Создает новый узел и вставляет его в начало списка
void listInsertHead(ListNode*& head, const string& value, ofstream& outFile, const string& operation) {
    ListNode* newNode = new ListNode{value, head}; // Создаем новый узел
    head = newNode; // Новый узел становится головой
    outFile << operation << " " << value << endl; // Логируем операцию
    cout << "Элемент '" << value << "' добавлен в список (в голову)." << endl;
}

// Добавление элемента в хвост списка
// Создает новый узел и вставляет его в конец списка
void listInsertTail(ListNode*& head, const string& value, ofstream& outFile, const string& operation) {
    ListNode* newNode = new ListNode{value, nullptr}; // Создаем новый узел
    if (!head) { // Если список пуст
        head = newNode; // Новый узел становится головой
    } else {
        ListNode* current = head;
        while (current->next) { // Находим последний узел
            current = current->next;
        }
        current->next = newNode; // Привязываем новый узел к концу списка
    }
    outFile << operation << " " << value << endl; // Логируем операцию
    cout << "Элемент '" << value << "' добавлен в список (в хвост)." << endl;
}

// Удаление элемента по значению
// Находит узел с указанным значением и удаляет его
void listDelete(ListNode*& head, const string& value, ofstream& outFile) {
    if (!head) { // Если список пуст
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    if (head->value == value) { // Если удаляемый элемент находится в голове
        ListNode* temp = head; // Сохраняем текущую голову
        head = head->next; // Перемещаем голову на следующий узел
        delete temp; // Удаляем старую голову
        outFile << "DELETE " << value << endl; // Логируем операцию
        cout << "Элемент '" << value << "' удалён." << endl;
        return;
    }

    ListNode* current = head;
    while (current->next && current->next->value != value) { // Ищем узел перед удаляемым
        current = current->next;
    }

    if (current->next) { // Если элемент найден
        ListNode* temp = current->next; // Сохраняем удаляемый узел
        current->next = current->next->next; // Пропускаем удаляемый узел
        delete temp; // Удаляем узел
        outFile << "DELETE " << value << endl; // Логируем операцию
        cout << "Элемент '" << value << "' удалён." << endl;
    } else {
        cout << "Элемент '" << value << "' не найден." << endl;
    }
}

// Удаление элемента из начала списка
// Удаляет первый элемент списка
void listDeleteHead(ListNode*& head, ofstream& outFile) {
    if (!head) { // Если список пуст
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    ListNode* temp = head; // Сохраняем текущую голову
    head = head->next; // Перемещаем голову на следующий узел
    outFile << "LDELHEAD " << temp->value << endl; // Логируем операцию
    cout << "Элемент '" << temp->value << "' удалён из начала списка." << endl;
    delete temp; // Удаляем старую голову
}

// Удаление элемента из конца списка
// Удаляет последний элемент списка
void listDeleteEnd(ListNode*& head, ofstream& outFile) {
    if (!head) { // Если список пуст
        cout << "Список пуст! Нечего удалять." << endl;
        return;
    }

    if (!head->next) { // Если в списке только один элемент
        outFile << "LDELEND " << head->value << endl; // Логируем операцию
        cout << "Элемент '" << head->value << "' удалён из конца списка." << endl;
        delete head; // Удаляем голову
        head = nullptr; // Сбрасываем указатель головы
        return;
    }

    ListNode* current = head;
    while (current->next->next) { // Находим предпоследний элемент
        current = current->next;
    }

    outFile << "LDELEND " << current->next->value << endl; // Логируем операцию
    cout << "Элемент '" << current->next->value << "' удалён из конца списка." << endl;
    delete current->next; // Удаляем последний элемент
    current->next = nullptr; // Сбрасываем указатель последнего элемента
}

// Поиск элемента
// Ищет элемент в списке и выводит результат
void listGet(ListNode* head, const string& value, ofstream& outFile) {
    while (head) { // Перебираем элементы списка
        if (head->value == value) { // Если найдено совпадение
            cout << "Число '" << value << "' найдено." << endl;
            outFile << "LGET " << value << ": found" << endl;
            return;
        }
        head = head->next; // Переходим к следующему узлу
    }
    cout << "Число '" << value << "' не найдено." << endl;
    outFile << "LGET " << value << ": not found" << endl;
}

// Печать содержимого списка
// Выводит все элементы списка
void listPrint(ListNode* head, ofstream& outFile, const string& operation) {
    if (!head) { // Если список пуст
        cout << "Список пуст!" << endl;
        outFile << operation << ": empty" << endl;
        return;
    }

    cout << "Содержимое списка: ";
    outFile << operation << ": ";
    while (head) { // Перебираем элементы списка
        cout << head->value << " ";
        outFile << head->value << " ";
        head = head->next; // Переходим к следующему узлу
    }
    cout << endl;
    outFile << endl;
}
