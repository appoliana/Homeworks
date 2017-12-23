#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void withoutRepetitions(int *array, int n) {
    cout << "Элементы без повторений: " << endl;
    for (int i = 0; i < n; i++) {
        while (array[i] == array[i + 1]) {
            i++;
        }
        cout << array[i] << " ";
    }
    cout << endl;
}

void itemCounter(int *array, int n) {
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        while (array[i] == array[i + 1]) {
            i++;
            count++;
        }
        cout << "Элемент " << array[i] << " встречается в массиве " << count << " раз(а)." << endl; 
        count = 1;
    }
}

int main(int argc, char** argv) {
    int n = 0;
    cout << "Введите количество добавляемых элементов: " << endl;
    cin >> n;
    int *array = new int[n];
    cout << "Последовательность введеных чисел обяхательно должна заканчиваться 0! " << endl;
    cout << "Введите последовательность: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    sort(array, &array[n]);
    withoutRepetitions(array, n);
    itemCounter(array, n);
    
    delete [] array;
    return 0;
}

