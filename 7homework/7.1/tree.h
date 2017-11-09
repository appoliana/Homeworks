#pragma once

struct Tree;

struct BinarySearchTree
{
    Tree *root;
};

//бинарный поиск
BinarySearchTree *createTree();

//удаление узла
void clearNode(Tree *node);

//удаление дерева  
void clearTree(BinarySearchTree *tree);

//поиск значения
bool contains(BinarySearchTree *tree, int value);

//добавление значения
bool add(BinarySearchTree *tree, int value);

//печать элементов дерева по убыванию
void printMax(BinarySearchTree *tree);

//печать элементов дерева по возрастанию
void printMin(BinarySearchTree *tree);