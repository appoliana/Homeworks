#include <stdio.h>
#include <cstdlib>
#include <memory>
#include <iostream>

using namespace std;
void sort (int array[], int length) {
    int supporting = array[0];
    int left = 1;
    int right = length - 1;
    while (left <= right) {
        while (array[left] < supporting)
            left++;
        while (array[right] > supporting)
            right--;
        if (array[left] >= array[right]) {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    }   
}


void print (int array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main (int argc, char** argv){
    int length = 0;
    cout << "Введите длину массива: ";
    cin >> length;
    int *array = new int[length];
    for (int i = 0; i < length; ++i) {
       cin >> array[i];
    }
    
    print(array, length);
    sort(array, length);
    print(array, length);
    
    delete[] array;
    return 0;
}

