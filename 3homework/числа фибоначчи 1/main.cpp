/* 
 * File:   main.cpp
 * Author: polinapicchio
 *
 * Created on 19 сентября 2017 г., 10:47
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int fibonacchi(int n) {
if (n == 0 || n == 1)
return 1;
return fibonacchi(n-1) + fibonacchi(n-2);
}

int main(int argc, char** argv) {
    int number = 0;
    printf("Введите номер искомого числа: \n");
    scanf("%d", &number);
    int value = fibonacci(number);
    printf("%d", value);
    return 0;
}

