#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    BinarySearchTree *tree = createTree();
    add(tree, 4);
    add(tree, 8);
    add(tree, 3);
    add(tree, 1);
    printMax(tree);
    printMin(tree);

    return 0;
}

