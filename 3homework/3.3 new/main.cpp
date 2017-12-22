#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

void print(int *arrayN, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arrayN[i] << ", ";
    }
}

void search (int *arrayN, int n) {
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
    cout << endl;
    cout << "Наиболее часто встречающийся элемент в массиве = " << countI;  
}

int main(int argc, char** argv) {
    int n = 0;
    cout << "Введите длину массива: ";
    cin >> n;
    int *arrayN = new int[n];
    cout << "Массив: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arrayN[i];
    }
    cout << endl;
    
    sort(arrayN, &arrayN[n]);
    cout << "Отсортированный массив: " << endl;
    print(arrayN, n);
    search(arrayN, n);
    
    delete[] arrayN;
    return 0;
}


