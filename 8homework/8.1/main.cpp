#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char** argv)
{
    BinarySearchTree *tree = createTree();
    printRoot(tree);
    add(tree, 4, "pddp");
    printRoot(tree);
    add(tree, 8, "fdkf");
    add(tree, 3, "d[d[");
    add(tree, 1, "dldk");
    
    printRoot(tree);
  
    clearTree(tree);
    return 0;
}

