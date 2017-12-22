#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "newfile.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n = 0;
    cout << "Введите n: ";
    cin >> n;
    int Array_n[n];
    cout << "Массив из n элементов: " << endl;
    
    Rand( Array_n[n], n);
    sort( Array_n, Array_n + n);
    Print( Array_n[n], n)
    Search( Array_n[n], n);
    
    return 0;
}

