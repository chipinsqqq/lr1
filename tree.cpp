#include "header.h"

// Добавление элемента в дерево
void addTree(Tree*& root, int value, ofstream& outFile) {
    if (!root) {
        root = new Tree(value);
        outFile << "ADD " << value << endl;
        cout << "Элемент '" << value << "' добавлен как корень дерева." << endl;
        return;
    }

    if (value <= root->value) {
        addTree(root->left, value, outFile);
    } else {
        addTree(root->right, value, outFile);
    }
}

// Печать дерева
void printTree(Tree* root, int level) {
    if (root != nullptr) {
        printTree(root->right, level + 1); // Сначала обрабатываем правое поддерево

        // Печатаем текущий узел с отступами
        for (int i = 0; i < level; ++i) {
            cout << "   ";
        }
        cout << root->value << endl;

        printTree(root->left, level + 1); // Затем обрабатываем левое поддерево
    }
}

// Проверка на полное дерево
bool checkComplete(Tree* root, int index, int numberNodes, ofstream& outFile) {
    if (!root) return true;

    if (index >= numberNodes) {
        outFile << "COMPLETE: no" << endl;
        cout << "Дерево не является полным." << endl;
        return false;
    }

    return checkComplete(root->left, 2 * index + 1, numberNodes, outFile) &&
           checkComplete(root->right, 2 * index + 2, numberNodes, outFile);
}

// Поиск элемента
bool searchTree(Tree* root, int value, ofstream& outFile) {
    if (!root) return false;

    if (root->value == value) {
        outFile << "SEARCH " << value << ": found" << endl;
        cout << "Элемент '" << value << "' найден в дереве." << endl;
        return true;
    }

    return searchTree(root->left, value, outFile) || searchTree(root->right, value, outFile);
}

// Подсчёт количества узлов в дереве
int countNumNodes(Tree* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNumNodes(root->left) + countNumNodes(root->right);
}