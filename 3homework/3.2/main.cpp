#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int contains(int* array, int start, int end, int element) {
    if (start > end) 
        return 0;
    if (element == array[(start + end) / 2]) 
        return 1;
    if (element < array[(start + end) / 2])
        return contains(array, start, (start + end) / 2 - 1, element);
    return contains(array, (start + end) / 2 + 1, end, element);
}

int main(int argc, char** argv)
{
    int n = 0;
    cout << "Введите количество n чисел: ";
    cin >> n;
    int *arraySource = new int[n];
    int k = 0;
    cout << "Введите количество k чисел: ";
    cin >> k;
    int *array = new int [k];
    for (int i = 0; i < n; i++) {
        arraySource[i] = rand() % 10 + 0;
    }
    cout << endl;
    for (int i = 0; i < k; i++) {
        array[i] = rand() % 10 + 0;
    }

    sort(arraySource, &arraySource[n]);
    cout << "n чисел: ";
    printArray(arraySource, n);
    cout << endl;
    cout << "Сгенерированные k чисел: ";
    printArray(array, k);

    for (int i = 0; i < k; i++) {
        if (contains(arraySource, 0, n, array[i])) {
            cout << "Элемент " << array[i] << " найден в массиве";
        }
        else {
            cout << "Элемент " << array[i] << " не найден в массиве";
        }
        cout << endl;
    }
    delete[] arraySource;
    delete[] array;
    return 0;
}