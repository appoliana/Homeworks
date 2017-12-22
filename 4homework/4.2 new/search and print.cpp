#include "search and print.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int search (int *arrayN, int n) {
    int count = 1;
    int maxCount = 0;
    int countI = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (arrayN[i] == arrayN[i + 1])
        {
            count++;
        }    
        else {
            if (count >= maxCount) {
                maxCount = count;
                countI = arrayN[i];
                count = 1;
            }
        count = 1; 
        }
    }
    if (count >= maxCount) {
        maxCount = count;
        countI = arrayN[n - 1];
    }
    return countI;
}


void print(int *arrayN, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arrayN[i] << ", ";
    }
}

