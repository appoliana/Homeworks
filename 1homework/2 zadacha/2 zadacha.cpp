/* 
 * File:   main.cpp
 * Author: polinapicchio
 *
 * Created on 9 сентября 2017 г., 12:33
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a = 0; 
    int b = 0;
    printf("Введите делимое: ");
    scanf("%d", &a);
    printf("Введите делитель: ");
    scanf("%d", &b);
    int count = 0;
    int znak = (a*b > 0) ? 1 : -1;
    int a1 = (a > 0) ? a : -a;
    int b1 = (b > 0) ? b : -b;
    while (a1 >= b1) {
        a1 = a1 - b1;
        count ++;
    }
    printf("Неполное частное: ");
    if (znak > 0) {
        printf("%d", count);
    }
    else {
        printf(" - %d", count+1);
    }
    return 0;
}

