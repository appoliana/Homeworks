#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    Tree *tree = createTree();
    add(tree, 5);
    add(tree, 3);
    add(tree, 9);
    add(tree, 10);
    add(tree, 7);
    add(tree, 6);
    add(tree, 8);
    remove(tree, 7);
    print(tree);
    clearTree(tree);
    return 0;
}