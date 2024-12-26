#include "header.h"
// Выполнение команды для односвязного списка
void Listcom(ListNode*& head, const string& command, ofstream& outFile) {
    if (command.rfind("LPUSH", 0) == 0) {
        string value = command.substr(6); // Извлечение значения после "LPUSH "
        listInsertHead(head, value, outFile, "LPUSH");
    } else if (command.rfind("LAPPEND", 0) == 0) {
        string value = command.substr(8); // Извлечение значения после "LAPPEND "
        listInsertTail(head, value, outFile, "LAPPEND");
    } else if (command.rfind("LREMOVE", 0) == 0) {
        string value = command.substr(8); // Извлечение значения после "LREMOVE "
        listDelete(head, value, outFile);
    } else if (command == "LDELHEAD") {
        listDeleteHead(head, outFile);
    } else if (command == "LDELEND") {
        listDeleteEnd(head, outFile);
    } else if (command.rfind("LGET", 0) == 0) {
        string value = command.substr(5); // Извлечение значения после "LGET "
        listGet(head, value, outFile);
    } else if (command == "PRINT") {
        listPrint(head, outFile, "PRINT");
    } else {
        cout << "Неизвестная команда для односвязного списка." << endl;
    }
}

// Выполнение команды для двусвязного списка
void DListcom(DoubleListNode*& head, DoubleListNode*& tail, const string& command, ofstream& outFile) {
    if (command.rfind("DPUSH", 0) == 0) {
        string value = command.substr(6); // еИзвлечение значения после "DPUSH "
        dlistInsertHead(head, tail, value, outFile, "DPUSH");
    } else if (command.rfind("DAPPEND", 0) == 0) {
        string value = command.substr(8); // Извлечение значения после "DAPPEND "
        dlistInsertTail(head, tail, value, outFile, "DAPPEND");
    } else if (command == "DDELHEAD") {
        dlistDeleteHead(head, tail, outFile);
    } else if (command == "DDELEND") {
        dlistDeleteEnd(head, tail, outFile);
    } else if (command.rfind("DGET", 0) == 0) {
        string value = command.substr(5); // Извлечение значения после "DGET "
        dlistGet(head, value, outFile);
    } else if (command.rfind("DREMOVE", 0) == 0) {
        string value = command.substr(8); // Извлечение значения после "DELETE "
        dlistDelete(head, tail, value, outFile);
    } else if (command == "PRINT") {
        dlistPrint(head, outFile, "PRINT");
    } else {
        cout << "Неизвестная команда для двусвязного списка." << endl;
    }
}
// Выполнение команды для стека
void Stackcom(Stack& stack, const string& command, ofstream& outFile, const string& fileName) {
    if (command.rfind("SPUSH", 0) == 0) {
        string value = command.substr(6); // Извлечение значения после "SPUSH "
        push(stack, value, outFile);
    } else if (command == "SPOP") {
        pop(stack, outFile);
    } else if (command == "PRINT") {
        printStack(stack, outFile);
    } else {
        outFile << "Unknown command: " << command << endl;
        cout << "Неизвестная команда: " << command << endl;
    }
}
// Выполнение команды для очереди
void Queuecom(Queue& queue, const string& command, ofstream& outFile, const string& fileName) {
    if (command.rfind("QPUSH", 0) == 0) {
        string value = command.substr(6); // Извлечение значения после "QPUSH "
        enqueue(queue, value, outFile);
    } else if (command == "QPOP") {
        dequeue(queue, outFile);
    } else if (command == "PRINT") {
        printQueue(queue, outFile);
    } else {
        outFile << "Unknown command: " << command << endl;
        cout << "Неизвестная команда: " << command << endl;
    }
}

// Выполнение команды для дерева
void Treecom(Tree*& root, const string& command, ofstream& outFile) {
    if (command.rfind("TADD", 0) == 0) {
        int value = stoi(command.substr(5)); // Извлечение значения после "TADD "
        addTree(root, value, outFile);
    } else if (command == "PRINT") {
        printTree(root, 0);
    } else if (command.rfind("TSEARCH", 0) == 0) {
        int value = stoi(command.substr(8)); // Извлечение значения после "TSEARCH "
        if (!searchTree(root, value, outFile)) {
            outFile << "SEARCH " << value << ": not found" << endl;
            cout << "Элемент '" << value << "' не найден в дереве." << endl;
        }
    } else if (command == "TCOMPLETE") {
        int totalNodes = countNumNodes(root);
        if (checkComplete(root, 0, totalNodes, outFile)) {
            outFile << "COMPLETE: yes" << endl;
            cout << "Дерево является полным." << endl;
        } else {
            cout << "Дерево не является полным." << endl;
        }
    } else {
        cout << "Неизвестная команда для дерева." << endl;
    }
}

// Выполнение команды для массива
void Arraycom(SimpleArray& arr, const string& command) {
    if (command.rfind("AADD", 0) == 0) {
        string value = command.substr(5);
        add(arr, value);
    } else if (command.rfind("ADDINDEX", 0) == 0) {
        size_t firstSpace = command.find(' ', 9);
        string index = command.substr(9, firstSpace - 9);
        string value = command.substr(firstSpace + 1);
        addAtIndex(arr, index, value);
    } else if (command.rfind("AREMOVE", 0) == 0) {
        string index = command.substr(8);
        removeAtIndex(arr, index);
    } else if (command.rfind("AREPLACE", 0) == 0) {
        size_t firstSpace = command.find(' ', 9);
        string index = command.substr(9, firstSpace - 9);
        string value = command.substr(firstSpace + 1);
        replaceItem(arr, index, value);
    } else if (command.rfind("AGET", 0) == 0) {
        string index = command.substr(5);
        getItem(arr, index);
    } else if (command == "PRINT") {
        printArray(arr);
    } else if (command == "LENGTH") {
        getLength(arr);
    } else {
        cout << "Неизвестная команда для массива!" << endl;
    }
}

// Выполнение команды для хеш-таблицы
void HashTablecom(HashTable& ht, const string& command, ofstream& outFile) {
    if (command.rfind("HSET", 0) == 0) {
        istringstream iss(command.substr(5));
        string key, value;
        iss >> key >> value;
        ht.HSET(key, value, outFile);
    } else if (command.rfind("HDEL", 0) == 0) {
        string key = command.substr(5);
        ht.HDEL(key, outFile);
    } else if (command.rfind("HGET", 0) == 0) {
        string key = command.substr(5);
        ht.HGET(key, outFile);
    } else if (command == "PRINT") {
        ht.PRINT(outFile);
    } else {
        cout << "Неизвестная команда для хеш-таблицы!" << endl;
    }
}


// Очистка файла
void clearFile(const string& fileName) {
    ofstream file(fileName, ios::out); // Открытие файла в режиме записи
    if (file.is_open()) {
        file.close(); // Закрываем файл после очистки
        cout << "Файл \"" << fileName << "\" успешно очищен." << endl;
    } else {
        cerr << "Не удалось открыть файл \"" << fileName << "\" для очистки." << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Использование: ./program --file file.data" << endl;
        return 1;
    }

    string fileName = argv[2]; // Имя файла передается через аргументы
    ofstream outFile(fileName, ios::app); // Открываем файл для добавления записей
    if (!outFile.is_open()) {
        cerr << "Не удалось открыть файл для записи: " << fileName << endl;
        return 1;
    }

    Stack myStack = {nullptr};              // Инициализация пустого стека
    Queue myQueue = {nullptr, nullptr};    // Инициализация пустой очереди
    ListNode* myList = nullptr;            // Инициализация пустого односвязного списка
    DoubleListNode* dListHead = nullptr;   // Инициализация пустого двусвязного списка
    DoubleListNode* dListTail = nullptr;
    Tree* myTree = nullptr; // Инициализация пустого дерева
    SimpleArray myArray(10); // Массив с вместимостью 10
    HashTable myHashTable(10);

    cout << "Введите команду. Для выхода введите EXIT. Для очистки файла введите CLEAR." << endl;

    string command;
    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "EXIT") {
            break;
        } else if (command == "CLEAR") {
            clearFile(fileName);
            cout << "Все данные очищены. Продолжайте работу." << endl;
        } else {
            // Проверяем, к какой структуре данных относится команда
            if (command[0] == 'S') { // Команды для стека
                Stackcom(myStack, command.substr(2), outFile, fileName);
            } else if (command[0] == 'Q') { // Команды для очереди
                Queuecom(myQueue, command.substr(2), outFile, fileName);
            } else if (command[0] == 'L') { // Команды для односвязного списка
                Listcom(myList, command.substr(2), outFile);
            } else if (command[0] == 'D') { // Команды для двусвязного списка
                DListcom(dListHead, dListTail, command.substr(2), outFile);
            } else if (command[0] == 'T') { // Команды для дерева
                Treecom(myTree, command.substr(2), outFile);
            } else if (command[0] == 'A') { // Команды для массива
                Arraycom(myArray, command.substr(2));
            } else if (command[0] == 'H') { // Команды для массива
                HashTablecom(myHashTable, command.substr(2), outFile);
            } else {
                cout << "Неизвестная команда или структура данных. Попробуйте снова." << endl;
            }
        }
    }

    outFile.close();
    return 0;
}
