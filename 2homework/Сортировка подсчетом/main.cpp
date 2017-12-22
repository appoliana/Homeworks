
#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n = 0;
    printf("Введите количество эл-тов массива: \n");
    scanf("%d", &n);
    int A[n];
    printf("Числа в массиве принимают значения в диапазоне от 0 до 100: \n");
    for(int i = 0; i < n; i++){
        A[i] = rand() % 100;
        printf("%d,", A[i]);
    }
    int Count[100] = {0};
    for(int i = 0; i < n; i++){
        Count[A[i]]++;
    }
    printf("\n");
    for(int i = 0; i < 100; i++){
        while(Count[i]!=0){
        printf("%d,", i);
        Count[i]--;
        }
    }
    return 0;
}

