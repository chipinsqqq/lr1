#include "header.h"

// Добавление элемента в очередь
void enqueue(Queue& queue, const string& value, ofstream& outFile) {
    QueueNode* newNode = new QueueNode{value, nullptr};
    if (queue.rear != nullptr) {
        queue.rear->next = newNode;
    }
    queue.rear = newNode;
    if (queue.front == nullptr) {
        queue.front = queue.rear;
    }

    // Запись действия в файл
    outFile << "QPUSH " << value << endl;
    cout << "Элемент '" << value << "' добавлен в очередь." << endl;
}

// Удаление элемента из очереди
void dequeue(Queue& queue, ofstream& outFile) {
    if (queue.front == nullptr) {
        outFile << "QPOP: Error - Queue is empty!" << endl;
        cout << "Очередь пуста! Нечего удалять." << endl;
        return;
    }

    QueueNode* temp = queue.front;
    string removedValue = temp->value;
    queue.front = queue.front->next;
    if (queue.front == nullptr) {
        queue.rear = nullptr;
    }
    delete temp;

    // Запись действия в файл
    outFile << "QPOP: Removed '" << removedValue << "'" << endl;
    cout << "Удалён элемент: '" << removedValue << "'" << endl;
}

// Печать содержимого очереди
void printQueue(const Queue& queue, ofstream& outFile) {
    if (queue.front == nullptr) {
        outFile << "PRINT: Queue is empty!" << endl;
        cout << "Очередь пуста!" << endl;
        return;
    }

    // Печать содержимого очереди
    QueueNode* current = queue.front;
    cout << "Содержимое очереди: ";
    outFile << "PRINT: ";
    while (current != nullptr) {
        cout << current->value << " ";
        outFile << current->value << " ";
        current = current->next;
    }
    cout << endl;
    outFile << endl;
}
