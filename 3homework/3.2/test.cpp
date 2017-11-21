#include <iostream>
#include <cstdlib>
#include <algorithm>
dfdf
        
using namespace std;


int main(int argc, char** argv) {
    int n = 0;
    int k = 0;
    cout << "Введите k: ";
    cin >> k;
    cout << "Введите n: ";
    cin >> n;
    int Array_n[n];
    int Array_k[k];
    cout << "Массив из n элементов: " << endl;
    for (int i = 0; i < n; i++){
        Array_n[i] = rand () % 5000;
        cout << Array_n[i] << ", ";
    }
    cout << endl;
    cout << "K чисел: " << endl;
    for (int i = 0; i < k; i++){
        Array_k[i] = rand () % 3000000;
        cout << Array_k[i] << ", ";
    }
    sort(Array_n, Array_n + n);
    sort(Array_k, Array_k + k);
    cout << "Отсортированный массив из n элементов: " << endl;
    for (int i = 0; i < n; i++){
        cout << Array_n[i] << ", ";
    }
    cout << endl;
    cout << "K отсортированных чисел: " << endl;
    for (int i = 0; i < k; i++){
        cout << Array_k[i] << ", ";
    }
    return 0;
}