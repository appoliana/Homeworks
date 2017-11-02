#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

//сортировка пузырьком
int vial(int *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main(int argc, char** argv) {
    int length = 0;
    cout << " Введите количество элементов массива: " << endl;
    cin >> length;
    int *array = new int[length];
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }
    vial(array, length);
    cout << "Отсортированный массив после сортировки пузырьком: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    delete []array;
    return 0;
}

