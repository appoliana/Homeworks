#include <iostream>
#include "tree.h"

using namespace std;

struct TreeNode
{
    int value;
    string key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

struct BinarySearchTree
{
    TreeNode *root;
};

TreeNode* findNode(TreeNode* tree, const string& key);
void zig(BinarySearchTree *tree, TreeNode *node);
void zigZag(BinarySearchTree *tree, TreeNode *node);
void zigZig(BinarySearchTree *tree, TreeNode *node);
void splayTree(TreeNode *tree, string& key);

BinarySearchTree *createTree()
{
    BinarySearchTree *tree = new BinarySearchTree;
    tree->root = nullptr;
    return tree;
}

/*void clearNode(TreeNode *node)
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
*/

/*bool containsNode(BinarySearchTree *tree, TreeNode *node, const string &key)
{
    if (node == nullptr)
        return false;
    
    if (node->key == key) {
        splayTree(tree, node);
        return true;
    }

    if (key < node->key)
        return containsNode(tree, node->left, key);
    else
        return containsNode(tree, node->right, key);
}

bool contains(BinarySearchTree *tree, const string &key)
{
    return containsNode(tree, tree->root, key);
}
 */

TreeNode *createNode(int value, const string &key, TreeNode *parent)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = parent;
    return node;
}

bool addNode(BinarySearchTree *tree, TreeNode *&node, int value, const string &key, TreeNode *parent)
{
    if (node == nullptr)
    {
        node = createNode(value, key, parent);
        splayTree(tree, node);
        return true;
    }
    if (node->key == key) // переобозначить value
        splayTree(tree, node);
        return false;

    if (value < node->value) {
        return addNode(tree, node->left, value, key, node);
    }
    else {
        return addNode(tree, node->right, value, key, node);
    }
}

bool add(BinarySearchTree *tree, int value, const string &key)
{
    return addNode(tree, tree->root, value, key, nullptr);
}

void printRoot(BinarySearchTree *tree)
{
    cout << tree->root->key;
}

void zigZig(BinarySearchTree *tree, TreeNode *node)
{
    TreeNode *x = node;
    TreeNode *p = node->parent;
    zig(tree, p);
    zig(tree, x);
}

void zigZag(BinarySearchTree *tree, TreeNode *node)
{
    TreeNode *x = node;
    zig(tree, x);
    zig(tree, x);
}

void zig(BinarySearchTree *tree, TreeNode *node)
{
    TreeNode *x = node;
    TreeNode *p = node->parent;
    TreeNode *b1 = node->right;
    TreeNode *b2 = node->left;
    TreeNode *g = node->parent->parent;
    if (p->key > x->key) {
        x->right = p;
        p->left = b1;
        if (g != nullptr) {
            if (g->left == p) 
            {
                g->left = x;
            }
            else 
            {
                g->right = x;
            }
        }
    }
    if (p->key < x->key) {
        x->left = p;
        p->right = b2;
        if (g != nullptr) {
            if (g->left == p) 
            {
                g->left = x;
            }
            else 
            {
                g->right = x;
            }
        }
    }
    if (x->parent == nullptr) {
        tree->root = x;
    }
}

void splayTree(BinarySearchTree *tree, TreeNode * node)
{
    TreeNode *element = node;
    if((element->parent->parent->key > element->parent->key && element->parent->key > element->key)
    || (element->parent->parent->key < element->parent->key && element->parent->key < element->key))
    {
        zigZig(tree, element);
    }
    if((element->parent->key > element->key && element->parent->parent == nullptr)
    || (element->parent->key < element->key && element->parent->parent == nullptr)) 
    {
        zig(tree, element);
    }
    if((element->parent->parent->key > element->parent->key && element->parent->key < element->key) 
    || (element->parent->parent->key < element->parent->key && element->parent->key > element->key))
    {
        zigZag(tree, element);
    }
}

/*TreeNode* findNode(TreeNode* tree, const string& key)
{
    TreeNode* current = tree;
    while (current != nullptr) {
        if (key < current->key) {
            current = current->left;
        } 
        else {
            if (key > current->key) {
                current = current->right;
            } else {    
                return current;
            }
        }
    }
    return nullptr;
*/