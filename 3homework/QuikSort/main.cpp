#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;
// квиксорт
void qsort (int array[], int dopl, int dopr) { 
    int supporting = array[dopr / 2];// выбираем элемент, относительно которого будем сортировать массив
    int supporting1 = array[0];
    int supporting2 = array[dopr];
    if ((supporting1 > supporting && supporting1 < supporting2) || (supporting1 < supporting && supporting1 > supporting2)) {
        supporting = supporting1;
    } 
    if ((supporting2 > supporting && supporting2 < supporting1) || (supporting2 < supporting && supporting2 > supporting1)) {
        supporting = supporting2;
    } 
    int left = dopl;
    int right = dopr;
    while (left <= right) { //сортируем массив относительно выбранного эл-та
        while (array[left] <= supporting) {
            left++;
        }
        while (array[right] >= supporting) {
            right--;
        }
        if (left  <= right) {
            swap (array[left++], array[right--]);
        }
    }
    if (dopl <= right) qsort(array, dopl, right);
    if (dopr >= left) qsort(array, left, dopr);
}

void print(int Array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << Array[i] << ", ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    int length = 0;
    cout << "Введите длину массива: ";
    cin >> length;
    int array[length];
    for (int i = 0; i < length; ++i) {
        array[i] = rand () % 10;
    }
    
    cout << "Исходный массив: ";
    print(array, length);
    qsort (array, 0, length - 1);
    cout << "Отсортированный массив: ";
    print(array, length);
    
    return 0;
}
