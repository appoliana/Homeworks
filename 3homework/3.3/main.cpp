#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

int print(int *ArrayN, int n) {
    for (int i = 0; i < n; i++) {
        cout << ArrayN[i] << ", ";
    }
    return 0;
}

int search (int *ArrayN, int n) {
    int count = 0;
    int maxcount = 0;
    int countI = 0;
    for (int i = 0; i < n; ++i) {
        if (ArrayN[i] == ArrayN[i + 1]) {
            count ++;
        }
        else {
            maxcount = count > maxcount ? count : maxcount;
            count = 0;
            countI = ArrayN[i];
        }
    }
    cout << endl;
    cout << "Наиболее часто встречающийся элемент в массиве = " << countI;  
    return 0;
}

int main(int argc, char** argv) {
    int n = 0;
    cout << "Введите длину массива: ";
    cin >> n;
    int *ArrayN = new int[n];
    cout << "Массив: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> ArrayN[i];
    }
    cout << endl;
    
    sort(ArrayN, &ArrayN[n]);
    cout << "Отсортированный массив: " << endl;
    print(ArrayN, n);
    search(ArrayN, n);
    
    delete[] ArrayN;
    return 0;
}

