
#include <memory>  
#include <cstdlib>
#include <stdio.h>
using namespace std;

int vial(int *array, int number) {
    for (int i = 0; i < number; ++i) {
        array[i] = rand() % 10;
        printf("%d", array[i]);
    }
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < number - i - 1; ++j) {
            if (array[j] < array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
    printf("\n");
    for (int i = 0; i < number; ++i) { 
        printf("%d", array[i]);
    }
    return 0;
}

int insert(int *array, int number) {
    printf("Числа в массиве принимают значения в диапазоне от 0 до 100: \n");
    for (int i = 0; i < number; i++) {
        array[i] = rand() % 100;
        printf("%d,", array[i]);
    }
    int count[100] = {0};
    for (int i = 0; i < number; i++) {
        count[array[i]]++;
    }
    printf("\n");
    for (int i = 0; i < 100; i++) {
        while (count[i] != 0) {
            printf("%d,", i);
            count[i]--;
        }
    }
    return 0;
}


int main(int argc, char** argv) {
    int n = 0;
    printf("Введите количество эл-тов массива: \n");
    scanf("%d", &n);
    int *array = new int[n];
    int choose = 0;
    printf("Введите 1  для запуска сортировки пузырьком, 2 - подсчетом: \n");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
        {  
            vial(array, n);
            break;
        }
        case 2 :
        {
            insert(array, n);
            break;
        }
    }
    delete[] array;
    return 0;
}

