#include <iostream>
#include "tree.h"

using namespace std;

struct Tree
{
    int value;
    Tree *left;
    Tree *right;
};

BinarySearchTree *createTree()
{
    BinarySearchTree *tree = new BinarySearchTree;
    tree->root = nullptr;
    return tree;
}

void clearNode(Tree *node)
{
    if (node == nullptr)
        return;

    clearNode(node->left);
    clearNode(node->right);
    delete node;
}

void clearTree(BinarySearchTree *tree)
{
    clearNode(tree->root);
    tree->root = nullptr;
}

bool containsNode(Tree *node, int value)
{
    if (node == nullptr)
        return false;

    if (node->value == value)
        return true;

    if (value < node->value)
        return containsNode(node->left, value);
    else
        return containsNode(node->right, value);
}

bool contains(BinarySearchTree *tree, int value)
{
    return containsNode(tree->root, value);
}

Tree *createNode(int value)
{
    Tree *node = new Tree;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool addNode(Tree *&node, int value)
{
    if (node == nullptr)
    {
        node = createNode(value);
        return true;
    }

    if (node->value == value)
        return false;

    if (value < node->value)
        return addNode(node->left, value);
    else
        return addNode(node->right, value);
}

bool add(BinarySearchTree *tree, int value)
{
    return addNode(tree->root, value);
}

Tree *findMax(Tree *node)
{
    while (node->right != nullptr)
        node = node->right;
    return node;
}

void printNodeMax(Tree *node)
{
    if (node == nullptr)
        return;

    printNodeMax(node->right);
    cout << node->value << " ";
    printNodeMax(node->left);
}

void printNodeMin(Tree *node)
{
    if (node == nullptr)
        return;

    printNodeMin(node->left);
    cout << node->value << " ";
    printNodeMin(node->right);
}

void printMax(BinarySearchTree *tree)
{
    printNodeMax(tree->root);
    cout << endl;
}

void printMin(BinarySearchTree *tree)
{
    printNodeMin(tree->root);
    cout << endl;
}


