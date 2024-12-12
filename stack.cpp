#include "header.h"

// Добавление элемента в стек
void push(Stack& stack, const string& value, ofstream& outFile) {
    StackNode* newNode = new StackNode{value, stack.top};
    stack.top = newNode;

    // Запись действия в файл
    outFile << "SPUSH " << value << endl;
    cout << "Элемент '" << value << "' добавлен в стек." << endl;
}

// Удаление элемента из стека
void pop(Stack& stack, ofstream& outFile) {
    if (stack.top == nullptr) {
        outFile << "SPOP: Error - Stack is empty!" << endl;
        cout << "Стек пуст! Нечего удалять." << endl;
        return;
    }

    StackNode* temp = stack.top;
    string removedValue = temp->value;
    stack.top = stack.top->next;
    delete temp;

    // Запись действия в файл
    outFile << "SPOP: Removed '" << removedValue << "'" << endl;
    cout << "Удален элемент: '" << removedValue << "'" << endl;
}

// Печать содержимого стека
void printStack(const Stack& stack, ofstream& outFile) {
    if (stack.top == nullptr) {
        outFile << "PRINT: Stack is empty!" << endl;
        cout << "Стек пуст!" << endl;
        return;
    }

    // Печать стека
    cout << "Содержимое стека: ";
    outFile << "PRINT: ";
    StackNode* current = stack.top;
    while (current != nullptr) {
        cout << current->value << " ";
        outFile << current->value << " ";
        current = current->next;
    }
    cout << endl;
    outFile << endl;
}
