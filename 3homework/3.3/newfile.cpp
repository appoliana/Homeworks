#include "newfile.h"

void Search ( int Array_n[n], int n ) {
    int count = 0;
    int maxcount = 0;
    int count_i = 0;
    for (int i = 0; i < n; i++){
        if (Array_n[i] == Array_n[i+1]){
            count ++;
        }
        else{
            maxcount = count > maxcount ? count : maxcount;
            count_i = Array_n[i];
        }
        cout << endl;
        cout << "Наиболее часто встречающийся элемент в массиве = " << count_i;
}
}

void Rand ( int Array_n[n], int n) {
    for (int i = 0; i < n; i++){
        Array_n[i] = rand () % 10;
        cout << Array_n[i] << ", ";
    }
    cout << endl;
}

void Print ( int Array_n[n], int n) {
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < n; i++){
        cout << Array_n[i] << ", ";
    }
}
