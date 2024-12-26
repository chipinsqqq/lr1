#include "header.h"

// Добавление элемента в очередь
// Создает новый узел и добавляет его в конец очереди
void enqueue(Queue& queue, const string& value, ofstream& outFile) {
    QueueNode* newNode = new QueueNode{value, nullptr}; // Создаем новый узел
    if (queue.rear != nullptr) { // Если очередь не пуста
        queue.rear->next = newNode; // Привязываем новый узел к концу очереди
    }
    queue.rear = newNode; // Обновляем указатель на конец очереди
    if (queue.front == nullptr) { // Если очередь была пуста
        queue.front = queue.rear; // Обновляем указатель на начало очереди
    }

    // Запись действия в файл
    outFile << "QPUSH " << value << endl;
    cout << "Элемент '" << value << "' добавлен в очередь." << endl;
}

// Удаление элемента из очереди
// Удаляет узел из начала очереди и освобождает память
void dequeue(Queue& queue, ofstream& outFile) {
    if (queue.front == nullptr) { // Проверяем, пуста ли очередь
        outFile << "QPOP: Error - Queue is empty!" << endl;
        cout << "Очередь пуста! Нечего удалять." << endl;
        return;
    }

    QueueNode* temp = queue.front; // Сохраняем текущую голову очереди
    string removedValue = temp->value; // Сохраняем значение удаляемого узла
    queue.front = queue.front->next; // Перемещаем указатель на следующий узел
    if (queue.front == nullptr) { // Если очередь стала пустой
        queue.rear = nullptr; // Сбрасываем указатель на конец очереди
    }
    delete temp; // Удаляем узел

    // Запись действия в файл
    outFile << "QPOP: Removed '" << removedValue << "'" << endl;
    cout << "Удалён элемент: '" << removedValue << "'" << endl;
}

// Печать содержимого очереди
// Выводит все элементы очереди
void printQueue(const Queue& queue, ofstream& outFile) {
    if (queue.front == nullptr) { // Проверяем, пуста ли очередь
        outFile << "PRINT: Queue is empty!" << endl;
        cout << "Очередь пуста!" << endl;
        return;
    }

    // Печать содержимого очереди
    QueueNode* current = queue.front; // Начинаем с головы очереди
    cout << "Содержимое очереди: ";
    outFile << "PRINT: ";
    while (current != nullptr) { // Перебираем узлы очереди
        cout << current->value << " "; // Печатаем значение узла
        outFile << current->value << " "; // Записываем значение узла в файл
        current = current->next; // Переходим к следующему узлу
    }
    cout << endl;
    outFile << endl;
}
