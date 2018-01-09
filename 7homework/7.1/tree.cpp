#include <iostream>
#include "tree.h"

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct BinarySearchTree
{
    TreeNode *root;
};

BinarySearchTree *createTree()
{
    BinarySearchTree *tree = new BinarySearchTree;
    tree->root = nullptr;
    return tree;
}

void clearNode(TreeNode *node)
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

bool containsNode(TreeNode *node, int value)
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

TreeNode *createNode(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool addNode(TreeNode *&node, int value)
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

void printNodeMax(TreeNode *node)
{
    if (node == nullptr)
        return;

    printNodeMax(node->right);
    cout << node->value << " ";
    printNodeMax(node->left);
}

void printNodeMin(TreeNode *node)
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

TreeNode *findMin(TreeNode *node);

void deleteElement(TreeNode *&node, int value)
{
    if (value < node->value) {
        deleteElement(node->left, value);
    } else if (value > node->value) {
	deleteElement(node->right, value);
    } else {
	if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
	} else if (node->left == nullptr) {
            TreeNode *newNode = node->right;
            delete node;
            node = newNode;
	} else if (node->right == nullptr) {
            TreeNode *newNode = node->left;
            delete node;
            node = newNode;
	}
        else {
            TreeNode *newNode = findMin(node->right);
            node->value = newNode->value;
            deleteElement(node->right, node->value);
        }
    }
}

TreeNode *findMin(TreeNode *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void remove(BinarySearchTree *tree, int value)
{
    deleteElement(tree->root, value);
}


