#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    int a = 0;
    int b = 0;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    bool *array1 = new bool[32];
    bool *array2 = new bool[32];
    bool *arraySum = new bool[32];
    
    for (int i = 0; i < 32; ++i) {
	array1[i] = a >> i & 1;
        array2[i] = b >> i & 1;
    }
    
    cout << "Число а в двоичном представлении: ";
    for (int i = 31; i >= 0; --i) {
	cout << array1[i];
    }
    cout << endl;
    
    cout << "Число b в двоичном представлении: ";
    for (int i = 31; i >= 0; --i) {
	cout << array2[i];
    }
    cout << endl;
    
    bool bit = 0;
    for (int i = 0; i < 32; ++i) {
        arraySum[i] = bit ^ array1[i] ^ array2[i];
	bit = (bit & array1[i]) | (bit & array2[i]) | (array2[i] & array1[i]);
    }
 
    cout << "Сумма в десятичном представлении: ";
    for (int i = 31; i >= 0; --i) {
        cout << arraySum[i];
    }
    
    delete[] array1;
    delete[] array2;
    delete[] arraySum;
    return 0;  
}