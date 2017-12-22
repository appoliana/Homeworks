#include <memory>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


void change(int *array, int left, int right) {
    int j = 0;
    for (int i = left; i <= (left + right) / 2 ; ++i) {
        swap(array[i], array[right - j]);
        j++;
    }
}

int main(int argc, char** argv) {
    int n = 0;
    int m = 0; 
    cout << "Введите количество эл-тов первой части массива: ";
    cin >> n;
    cout << "Введите количество эл-тов второй части массива: ";
    cin >> m;
    int sum = n + m;
    int  *array = new int[sum];
    
    cout << "Введите исходный массив: ";
    for (int i = 0; i < sum; i++) {
        cin >> array[i];
    }
    
    change(array, 0, n - 1);
    change(array, n, sum - 1);
    change(array, 0, sum - 1);

    cout << "Перевернутый массив: ";
    for (int i = 0; i < sum; i++) {
        cout << array[i];
    }
    
    delete[] array;
    return 0;
}