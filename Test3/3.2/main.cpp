#include <iostream>
#include <cstdlib>

using namespace std;

void printMinAndMax(int *arrayMinLine, int *arrayMaxPillar, int n, int m) {
    cout << "Минимальный элемент в каждой строке: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arrayMinLine[i] << " ";
    }
    cout << endl;
    
    cout << "Максимальный элемент в каждом столбце: " << endl;
    for (int i = 0; i < m; i++) {
        cout << arrayMaxPillar[i] << " ";
    }
    cout << endl;
}

void printArray(int **array, int n, int m) {
        
    cout << "Двумерный массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

void search(int **array, int n, int m) {
    int maxElement = -1;
    int minElement = 9999;
    int *arrayMinLine = new int[n];
    for (int i = 0; i < n; i++) {
        arrayMinLine[i] = 0;
    }
    
    int *arrayMaxPillar = new int[m];
    for (int i = 0; i < m; i++) {
        arrayMaxPillar[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] <= minElement) {
                minElement = array[i][j];
                arrayMinLine[i] = minElement;
            }    
        }
        minElement = 9999;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[j][i] >= maxElement) {
                maxElement = array[j][i];
                arrayMaxPillar[i] = maxElement;
            }    
        }
        maxElement = -1;
    }
    
    printMinAndMax(arrayMinLine, arrayMaxPillar, n, m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrayMinLine[i] == arrayMaxPillar[j]) {
                cout << "Найдена седловая точка " << arrayMinLine[i] << endl;
            }
        }
    }
    delete[] arrayMinLine;
    delete[] arrayMaxPillar;
}

int main(int argc, char** argv) {
    int n, m;
    cout << "Введите размерность двумерного массива: " << endl;
    cin >> n >> m;

    int** array = new int *[n];
    for (int i = 0; i < n; ++i) 
    {
        array[i] = new int[m];
    }
        
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
        cout << endl;
    }
    
    printArray(array, n, m);
    search(array, n, m);
    
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}

