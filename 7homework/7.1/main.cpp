#include <iostream>
#include "tree.h"

using namespace std;

void menu() {
    cout << "Введите 1 для вывода элементов в порядке возрастания;" << endl;
    cout << "Введите 2 для вывода элементов в порядке убывания;" << endl;
    cout << "Введите 0 для завершения работы программы;" << endl;
    cout << "Введите 3 для удаления элемента;" << endl;
}

int main(int argc, char** argv) {
    BinarySearchTree *tree = createTree();
    
    add(tree, 2);
    add(tree, 1);
    add(tree, 6);
    add(tree, 3);
    add(tree, 7);
    add(tree, 5);
    add(tree, 4);
  
    int choose = 3;
    menu();
    while (choose != 0) {
        cin >> choose;
        switch (choose) {
            case 0:
            {
                return 2;
            }
            case 1:
            {
                printMin(tree);
                cout << endl;
                break;
            }
            case 2:
            {
                printMax(tree);
                cout << endl;
                break;
            }
            case 3:
            {
                int element = 0;
                cout << "Введите элемент, который хотите удалить: ";
                cin >> element;
                remove(tree, element);
                cout << endl;
                break;
            }
            default:
            {
                cout << "Введена неопознанная команда!";
                return 1;
            }
        }
    }
    clearTree(tree);
    return 0;
}

