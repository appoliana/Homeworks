#include "search and print.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


int main(int argc, char** argv) {
    ifstream input("File.txt");
    int n = 0;
    input >> n;
    cout << "Длина массива = " << n << endl;
    int *arrayN = new int[n];
    cout << "Массив: " << endl;
    for (int i = 0; i < n; ++i) {
        input >> arrayN[i];
        cout << arrayN[i] << ", ";
    }
    input.close();
    cout << endl;
    
    sort(arrayN, &arrayN[n]);
    cout << "Отсортированный массив: " << endl;
    print(arrayN, n);
    int dop = search(arrayN, n);
    cout << endl;
    cout << "Наиболее часто встречающийся элемент в массиве = " << dop;  
    
    delete[] arrayN;
    return 0;
}

