#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "stack.h"

using namespace std;

int main(int argc, char** argv) 
{
    Stack* stackOfFunctions = createStack();
    string s;
    cout << "Enter the string " << endl;
    cin >> s;
    int length = s.length();
    int *outputQueue = new int [length];
    int *arrayCout = new int [length];

    int iQueue = 0;
    int iCout = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            outputQueue[iQueue] = s[i];
            iQueue++;
        }
        if (s[i] == '(') 
        {
            push(stackOfFunctions, s[i]);
        }
        if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/')
        {
            push(stackOfFunctions, s[i]);
        }
        if (s[i] == ')') 
        {
            while (top(stackOfFunctions) != '(') {
                outputQueue[iQueue] = pop(stackOfFunctions);
                ++iQueue;
            }
            pop(stackOfFunctions);
        }
    }
    for (int i = 0; i < length; ++i) 
    {
        cout << outputQueue[i];
    }
}
