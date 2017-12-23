#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "cyclelist.h"

using namespace std;



int main(int argc, char** argv) 
{
	List list1;
        List list2;
        
        Node* tempNode1;
        Node* tempNode2;
        FILE* file = fopen("s.txt", "r");
        if (!feof(file)) {
            fscanf(file, "%d", &element);
            addElement(list1, element);
            fscanf(file, "%d", &element);
            addElement(list1, element);
            count++;
        }
        fclose(file);
        int choose = 0;
        cout << "Введите 1 для сортировки справочника по телефону, 2 - по имени: " << endl;
        cin >> choose;
        switch(choose) {
            case 1: 
            {
                initialisation(tempNode1, tempNode2, list1, list2, choose);
                printList(list1);
                break;
            }
            case 2:
            {
               initialisation(tempNode1, tempNode2, list1, list2, choose);
               printList(list1);
               break; 
            }
            default:
            {
                cout << "Введена неопознанная команда!";
                return 1;
            }
        }

	deleteList(list1);
	deleteList(list2);
                
	return 0;
}