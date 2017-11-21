#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv) {
    int count = 0;
    int A[28] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int n = 0; n < 10; n++){
                A[i + j + n]++;
            }
        }
    }
    for(int i = 0; i < 28; i++){
        count += A[i]*A[i];
    }
    printf("В диапазоне от 1 до 1000000 счастливых билетиков ");
    printf("%d", count);
        return 0;
}