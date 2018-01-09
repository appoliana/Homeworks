#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

int main(int argc, char** argv) {
    Stack* stack = createStack();
    char *array = new char[10000];
    cout << "Введите выражение в постфиксной форме без пробелов: " << endl;
    cin >> array;
    for (int i = 0; i < strlen(array); ++i) {
        if (array[i] == '*' || array[i] == '+' || array[i] == '-' || array[i] == '/') {
            if (isEmpty(stack)) {
                cout << "Введите выражение в ПОСТФИКСНОЙ форме" << endl;
                deleteStack(stack);
                delete[] array;
                return 1;
            }
            else { 
                int dopValue = 0;
                if (array[i] == '*') { 
                    dopValue = pop(stack) * pop(stack);
                }
                if (array[i] == '/') { 
                    dopValue = pop(stack) / pop(stack);
                }
                if (array[i] == '+') { 
                    dopValue = pop(stack) + pop(stack);
                }
                if (array[i] == '-') { 
                    dopValue = pop(stack) - pop(stack);
                }
                push(stack, dopValue);
            } 
        }
        else {
            push(stack, array[i] - '0');
        }
    }
    int result = pop(stack);
    cout << "Результат вычисления = " << result;
    deleteStack(stack);
    delete[] array;
    return 0;
}

//не работает ни на каких тестах

