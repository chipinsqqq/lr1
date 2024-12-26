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
    string* data;    // Указатель на массив строк
    int size;        // Текущий размер массива
    int capacity;    // Вместимость массива

    SimpleArray(int cap);  // Конструктор
    ~SimpleArray();        // Деструктор
};

// Функции работы с массивом
void add(SimpleArray& arr, const string& value);
void addAtIndex(SimpleArray& arr, const string& index, const string& value);
void removeAtIndex(SimpleArray& arr, const string& index);
void getItem(const SimpleArray& arr, const string& index);
void replaceItem(SimpleArray& arr, const string& index, const string& value);
void printArray(const SimpleArray& arr);
void getLength(const SimpleArray& arr);

// Структура для хранения пары ключ-значение
struct KeyValue {
    string key;
    string value;
};

struct Node {
    string key;
    string value;
    Node* next;

    Node(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};
// Класс хеш-таблицы
class HashTable {
private:
    int size;                  // Размер таблицы
    int* buckets;              // Массив для хранения индексов
    KeyValue* elements;        // Массив для хранения элементов
    int elementCount;          // Текущее количество элементов

    int hashFunction(const string& key);  // Хеш-функция
    int findSlot(const string& key, bool isInsert); // Поиск слота для ключа

public:
    HashTable(int s);          // Конструктор
    ~HashTable();              // Деструктор

    void HSET(const string& key, const string& value, ofstream& outFile); // Добавление элемента
    void HDEL(const string& key, ofstream& outFile);                     // Удаление элемента
    string HGET(const string& key, ofstream& outFile);                   // Получение значения по ключу
    void PRINT(ofstream& outFile);                                       // Печать таблицы
};                                       // Печать таблицы

void clearFile(const std::string& fileName);
void Listcom(ListNode*& head, const string& command, ofstream& outFile);
