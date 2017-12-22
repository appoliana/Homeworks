#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack1.h"
using namespace std;

void stOper(char s, Stack* stack, Stack* stackLet);
bool isNumber(char Symbol);

int main() {
    int k = 0;
    int n;
    Stack* stackLet = createStack();
    Stack* stack = createStack();
    string s;
    string s1;
    cout << "Введите строку в постфиксной форме: " << endl;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        k = i;
        n = 0;
        if (s[i] == '*') {
            while (!isEmpty(stack)) {
                if (top(stack) == '+' || top(stack) == '-' || top(stack) == '(') {
                    break;
                }
                stOper(top(stack), stack, stackLet);
            }
        push(stack, s[i]);
        }
        else if (s[i] == '/') {
            while (!isEmpty(stack)) {
                if (top(stack) == '+' || top(stack) == '-' || top(stack) == '(') {
                    break;
                }
                stOper(top(stack), stack, stackLet);
            }
        push(stack, s[i]);
        }
        else  if (s[i] == '+') {
            while (!isEmpty(stack)) {
                if (top(stack) == '(') break;
                stOper(top(stack), stack, stackLet);
            }
        push(stack, s[i]);
        }
        else   if (s[i] == '-') {
            while (!isEmpty(stack)) {
                if (top(stack) == '(') break;
                stOper(top(stack), stack, stackLet);
            }
            push(stack, s[i]);
        }
        else if (s[i] == '(') {
           push(stack, s[i]);
        }
        else if (s[i] == ')') {
            while (!isEmpty(stack)) {
                if (top(stack) == '(')
                {
                    pop(stack);
                    break;
                }
                stOper(top(stack), stack, stackLet);
            }
        }
        else if (isNumber(s[i])) {
            while (isNumber(s[k])) {
                if (k == s.size())break;
                s1[n] = s[k];
                n++;
                k++;
            }
            k--;
            i = k;
            int dop = atoi(s1.c_str() );
            push(stackLet, dop);
        }
    }
    while (!isEmpty(stack)) {
        stOper(top(stack), stack, stackLet);
    }
    cout << top(stackLet);
}

void stOper(char s, Stack* stack, Stack* stackLet)
{
    int a, b;
    if (!isEmpty(stackLet))
    {
        a = pop(stackLet);
        b = pop(stackLet);

        if (s == '+')
        {
            b += a;
            pop(stack);
            push(stackLet, b);
        }
        else if (s == '-')
        {
            b -= a;
            pop(stack);
            push(stackLet, b);
        }
        else  if (s == '*')
        {
            b *= a;
            pop(stack);
            push(stackLet,b);
        }
        else  if (s == '/')
        {
            b /= a;
            pop(stack);
            push(stackLet,b);
        }
    }
}

bool isNumber(char Symbol)
{
    if (Symbol >= '0' && Symbol <= '9')
        return true;
    return false;
}
