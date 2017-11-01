#include "stack.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdlib>

using namespace std;

int translateBrace(char brace) {
    switch (brace) {
        case '{':
        {
            return 1;
        }
        case '}':
        {
            return -1;
        }
        case '(':
        {
            return 2;
        }
        case ')':
        {
            return -2;
        }
        case '[':
        {
            return 3;
        }
        case ']':
        {
            return -3;
        }
        default:
        {
            cout << "Введена неопознанная скобка" << endl;
            return 4;
        }
    }
}

int main(int argc, char** argv) {
    Stack* stack = createStack();
    char *arrayBrace = new char[10000];
    char brace = '0';
    int value = 0;
    cout << "Введите скобочки (они могут быть шести типов: {, }, [, ], (, ): ";
    cin >> arrayBrace;
    for (int i = 0; i < strlen(arrayBrace); i++) {
        value = translateBrace(arrayBrace[i]);
        if (value > 0) {
            push(stack, value);
        }
        else {
            if (isEmpty(stack)) {
                cout << "Баланс скобок не соблюден";
                deleteStack(stack);
                delete[] arrayBrace;
                return 3;
            }
            else {
                int dop = translateBrace(arrayBrace[i]);
                if (dop + pop(stack) == 0) {
                    continue;
                }
                else {
                    cout << "Баланс скобок не соблюден";
                    deleteStack(stack);
                    delete[] arrayBrace;
                    return 1;
                }
            }
        }    
    }
    cout << "Баланс скобок соблюден! =)";
    deleteStack(stack);
    delete[] arrayBrace;
    return 0;
}

// ввод: ([{}()]) вывод: Баланс скобок соблюден! =)
// ввод: ){} вывод: Баланс скобок не соблюден


