#include "header.h"

// Добавление элемента в стек
// Создает новый узел и помещает его на вершину стека
void push(Stack& stack, const string& value, ofstream& outFile) {
    StackNode* newNode = new StackNode{value, stack.top}; // Создаем новый узел и связываем его с текущей вершиной
    stack.top = newNode; // Новый узел становится вершиной стека

    // Запись действия в файл
    outFile << "SPUSH " << value << endl;
    cout << "Элемент '" << value << "' добавлен в стек." << endl;
}

// Удаление элемента из стека
// Удаляет узел с вершины стека и освобождает память
void pop(Stack& stack, ofstream& outFile) {
    if (stack.top == nullptr) { // Проверяем, пуст ли стек
        outFile << "SPOP: Error - Stack is empty!" << endl;
        cout << "Стек пуст! Нечего удалять." << endl;
        return;
    }

    StackNode* temp = stack.top; // Сохраняем текущую вершину стека
    string removedValue = temp->value; // Сохраняем значение удаляемого узла
    stack.top = stack.top->next; // Перемещаем вершину на следующий узел
    delete temp; // Удаляем старую вершину

    // Запись действия в файл
    outFile << "SPOP: Removed '" << removedValue << "'" << endl;
    cout << "Удален элемент: '" << removedValue << "'" << endl;
}

// Печать содержимого стека
// Выводит все элементы стека, начиная с вершины
void printStack(const Stack& stack, ofstream& outFile) {
    if (stack.top == nullptr) { // Проверяем, пуст ли стек
        outFile << "PRINT: Stack is empty!" << endl;
        cout << "Стек пуст!" << endl;
        return;
    }

    // Печать содержимого стека
    cout << "Содержимое стека: ";
    outFile << "PRINT: ";
    StackNode* current = stack.top; // Начинаем с вершины стека
    while (current != nullptr) { // Перебираем узлы стека
        cout << current->value << " "; // Печатаем значение узла
        outFile << current->value << " "; // Записываем значение узла в файл
        current = current->next; // Переходим к следующему узлу
    }
    cout << endl;
    outFile << endl;
}
