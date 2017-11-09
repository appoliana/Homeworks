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
  
    int choose = 0;
    cout << "Введите 1 для вывода элементов в порядке возрастания, 2 - в порядке убывания: " << endl;
    cin >> choose;
    switch (choose) {
        case 1:
        {
            printMin(tree);
            break;
        }
        case 2:
        {
            printMax(tree);
            break;
        }
        default:
        {
            cout << "Введена неопознанная команда!";
            return 1;
        }
    }
    clearTree(tree);
    return 0;
}

