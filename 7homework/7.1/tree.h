#pragma once

struct TreeNode;

struct BinarySearchTree;

// бинарный поиск
BinarySearchTree *createTree();

// удаление узла
void clearNode(TreeNode *node);

// удаление дерева  
void clearTree(BinarySearchTree *tree);

// поиск значения
bool contains(BinarySearchTree *tree, int value);

// добавление значения
bool add(BinarySearchTree *tree, int value);

// печать элементов дерева по убыванию
void printMax(BinarySearchTree *tree);

// печать элементов дерева по возрастанию
void printMin(BinarySearchTree *tree);