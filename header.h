#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
using namespace std;

// Узел стека
struct StackNode {
    string value;
    StackNode* next;
};

// Стек
struct Stack {
    StackNode* top; // Указатель на вершину стека
};

// Функции для работы со стеком
void push(Stack& stack, const string& value, ofstream& outFile);
void pop(Stack& stack, ofstream& outFile);
void printStack(const Stack& stack, ofstream& outFile);

// Узел очереди
struct QueueNode {
    string value;
    QueueNode* next;
};

// Очередь
struct Queue {
    QueueNode* front; // Указатель на первый элемент
    QueueNode* rear;  // Указатель на последний элемент
};

// Операции для очереди
void enqueue(Queue& queue, const string& value, ofstream& outFile);
void dequeue(Queue& queue, ofstream& outFile);
void printQueue(const Queue& queue, ofstream& outFile);

// Узел двусвязного списка
struct DoubleListNode {
    string value;
    DoubleListNode* next;
    DoubleListNode* prev;
};

// Функции для работы с двусвязным списком
void dlistInsertHead(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile, const string& operation);
void dlistInsertTail(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile, const string& operation);
void dlistDeleteHead(DoubleListNode*& head, DoubleListNode*& tail, ofstream& outFile);
void dlistDeleteEnd(DoubleListNode*& head, DoubleListNode*& tail, ofstream& outFile);
void dlistDelete(DoubleListNode*& head, DoubleListNode*& tail, const string& value, ofstream& outFile);
void dlistGet(DoubleListNode* head, const string& value, ofstream& outFile);
void dlistPrint(DoubleListNode* head, ofstream& outFile, const string& operation);

// Функция для обработки команд, связанных с двусвязным списком
void DListcom(DoubleListNode*& head, DoubleListNode*& tail, const string& command, ofstream& outFile);

// Узел односвязного списка
struct ListNode {
    string value;
    ListNode* next;
};

// Функции для работы с односвязным списком
void listInsertHead(ListNode*& head, const string& value, ofstream& outFile, const string& operation);
void listInsertTail(ListNode*& head, const string& value, ofstream& outFile, const string& operation);
void listDelete(ListNode*& head, const string& value, ofstream& outFile);
void listDeleteHead(ListNode*& head, ofstream& outFile);
void listDeleteEnd(ListNode*& head, ofstream& outFile);
void listGet(ListNode* head, const string& value, ofstream& outFile);
void listPrint(ListNode* head, ofstream& outFile, const string& operation);

// Узел бинарного дерева
struct Tree {
    int value;
    Tree* left;
    Tree* right;

    Tree(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функции для работы с деревом
void addTree(Tree*& root, int value, ofstream& outFile);
void printTree(Tree* root, int level);
bool checkComplete(Tree* root, int index, int numberNodes, ofstream& outFile);
bool searchTree(Tree* root, int value, ofstream& outFile);
void Treecom(Tree*& root, const string& command, ofstream& outFile);
int countNumNodes(Tree* root);

struct SimpleArray {
    int* data;       // Указатель на массив
    int size;        // Текущий размер массива
    int capacity;    // Вместимость массива

    SimpleArray(int cap);  // Конструктор
    ~SimpleArray();        // Деструктор
};

// Функции работы с массивом
void add(SimpleArray& arr, int value);
void addAtIndex(SimpleArray& arr, int index, int value);
void removeAtIndex(SimpleArray& arr, int index);
void getItem(const SimpleArray& arr, int index);
void replaceItem(SimpleArray& arr, int index, int value);
void printArray(const SimpleArray& arr);
void getLength(const SimpleArray& arr);
void Arraycom(SimpleArray& arr, const string& command);

// Структура для хранения пары ключ-значение
struct KeyValue {
    string key;
    string value;
};

// Хеш-таблица с обработкой коллизий
struct HashTable {
    int size;                  // Размер таблицы
    int* buckets;              // Массив для хранения индексов (начало цепочек)
    KeyValue* elements;        // Массив для хранения элементов
    int capacity;              // Вместимость элементов
    int elementCount;          // Текущее количество элементов

    HashTable(int s);          // Конструктор
    ~HashTable();              // Деструктор

    int hashFunction(const string& key);  // Хеш-функция
    void HSET(const string& key, const string& value, ofstream& outFile); // Добавление элемента
    void HDEL(const string& key, ofstream& outFile);                     // Удаление элемента
    string HGET(const string& key, ofstream& outFile);                   // Получение значения по ключу
    void PRINT(ofstream& outFile);                                       // Печать таблицы
};

void clearFile(const std::string& fileName);
void Listcom(ListNode*& head, const string& command, ofstream& outFile);