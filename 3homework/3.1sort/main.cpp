#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

const int arraySize = 100;

void insertSort(int array[], int aLeft, int aRight) 
{
    for (int i = aLeft + 1; i != aRight + 1; ++i) {
	int j = i;
	while (j > 1 && array[j] < array[j - 1]) {
            swap(array[j], array[j - 1]);
            --j;
        }
    }
}

int partition(int array[], int aLeft, int aRight) 
{
    int temporaryPivot = array[aLeft];
    int i = aLeft;
    int j = i; 
    for (i = aLeft + 1; i != aRight + 1; ++i) {                                              
	if (array[i] <= temporaryPivot) {            
            ++j;
            swap(array[j], array[i]);
	}
    }
    swap(array[aLeft], array[j]);
    return j;
}

void qSort(int array[], int aLeft, int aRight) 
{
    if (aLeft >= aRight) 
    {
	return;
    }
    if (aRight - aLeft < 10) 
    { 	
        insertSort(array, aLeft, aRight);       
    }
    else 
    {
	const int pivot = partition(array, aLeft, aRight); 
	qSort(array, aLeft, pivot - 1);
	qSort(array, pivot + 1, aRight);
    }
}

int main(int argc, char** argv) {
    int *array = new int [arraySize];
    for (int i = 0; i < arraySize; i ++) {
        array[i] = rand () % 1;
        cout << array[i] << " ";
    }
    cout << endl;
    
    qSort(array, 0, arraySize - 1);
    
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < arraySize; i ++) {
        cout << array[i] << " ";
    }
    
    delete[] array;
    return 0;
}

