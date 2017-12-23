#include "list.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    List *list = createList();
    int value = 0;
    int dop = 1;
    while (dop != 0) {
        cout << "Список возможных команд" << endl;
        cout << "0 - выйти" << endl;
        cout << "1 - добавить значение в сортированный список" << endl;
        cout << "2 - удалить значение из списка" << endl;
        cout << "3 - распечатать список" << endl;
        cout << "Введите команду: ";
        cin >> dop;
        switch (dop) {
            case 0:
            {
                deleteList(list);
                break;
            } 
            case 1:
            {
                cout << "Введите следующее значение: ";
                cin >> value;
                insert(list, value);
                break;
            } 
            case 2:
            {
                cout << "Введите значение, которое вы хотите удалить: ";
                deleteElement(list, value);
                break;
            }
            case 3:
            {
                print(list);
                break;
            }
            default:
            {
                cout << "Такая команда не найдена";
                break;
            }    
        }
    }
    deleteList(list);
    return 0;
}