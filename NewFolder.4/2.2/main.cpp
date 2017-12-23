#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

int main(int argc, char** argv) {
    Stack* stack = createStack();
    int choose = 5;
    while (choose != 0) {
        cout << "Введите 0 - выйти, " << "1 - добавить число, " << "2 - удалить число, " 
             << "3 - дублировать на вершину, " << "4 - распечатать стек" << endl;
        cin >> choose;
        switch (choose) {
            case 0:
            {
                cout << "Завершение работы программы";
                return 1;
            }
            case 1:
            {
                int number = 0;
                cout << "Введите число, которое вы хотите поместить в вершину стека: ";
                cin >> number;
                push(stack, number);
                break;
            }
            case 2:
            {
                pop(stack);
                break;
            }
            case 3:
            {
                int dop = pop(stack);
                push(stack, dop);
                push(stack, dop);
                break;
            }
            case 4:
            {
                cout << "Распечатанный стек: " << endl;
                while (!isEmpty(stack)) 
                {
                    int temp = topElement(stack);
                    cout << temp << " ";
                }
                cout << endl;
                break;
            }
            default:
            {
                cout << "Введена неопознанная команда!";
                return 2;
            }
        }
    }
    deleteStack(stack);
    return 0;
}

