#pragma once
#include <string>

struct TreeNode;

struct BinarySearchTree;

// создание дерева
BinarySearchTree *createTree();

// удаление узла
//void clearNode(TreeNode *node);

// удаление дерева  
//void clearTree(BinarySearchTree *tree);

// поиск значения
//bool contains(BinarySearchTree *tree, int value);

// добавление значения
bool add(BinarySearchTree *tree, int value, const std::string &key);

// печать дерева
void printRoot(BinarySearchTree *tree);

//поворот дерева
void removeTree(BinarySearchTree *tree);

// балансировка дерева
void splayTree(BinarySearchTree *tree, TreeNode* node);