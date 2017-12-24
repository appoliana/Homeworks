#pragma once
#include <string>

struct TreeElement;

struct Tree;

// создание дерева
Tree *createTree();

// добавление левого сына
TreeElement *pointerOnLeftElement(TreeElement *treeElement);

// добавление правого сына
TreeElement *pointerOnRightElement(TreeElement *treeElement);

// добавление в голову
TreeElement *pointerOnHead(Tree *tree);

// значение
std::string valueElement(TreeElement *treeElement);

// добавление элемента
void addElement(Tree *tree, std::string addedValue);

// печать дерева
void printTree(Tree *tree);

// удаление дерева
void deleteTree(Tree *tree);

// подсчет выражения
int countExpression(Tree *tree);