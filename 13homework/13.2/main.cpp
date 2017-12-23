#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int definer(char simbol, char simbolNext)
{
    if (simbol == '/' && simbolNext == '*')
    {
        return 0;
    }
    if (simbol == '*' && simbolNext == '/')
    {
        return 1;
    }
    return 2;
}

int main(int argc, char** argv) {
    int matrix[3] = {1, 2, 3};
    char str[100] = "/*a1b1*/s1_2/*3*/";
    int state = 0;
    int i = 0;
    int beginOfComment = 0;
    int endOfComment = 0;
    bool begin = false;
    while (str[i] != '\0')
    {
        state = matrix[definer(str[i], str[i + 1])];
        if (state == 1)
        {
            beginOfComment = i;
            if (beginOfComment == 0) {
                begin = true;
            }
            i += 2;
        }
        if (state == 2)
        {
            endOfComment = i + 1;
            i += 2;
        }
        if (state == 3)
        {
            ++i;
        } 
        if ((beginOfComment != 0 && endOfComment != 0) || (beginOfComment == 0 && endOfComment != 0 && begin == true)) {
            begin = false;
            for (int j = beginOfComment; j < endOfComment; j++) {
                cout << str[j];
            }
            cout << endl;
            beginOfComment = 0;
            endOfComment = 0;
        }
    }
    return 0;
}

