#include <cstdlib>
#include <stdio.h>

using namespace std;

int fibonacchi2(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacchi2(n - 1) + fibonacchi2(n - 2);
}

int fibonacchi1(int n) {
    int sum = 0;
    int x1 = 1;
    int x2 = 1;
    if (n == 1 || n == 2)
        return 1;
    for (int i = 2; i < n; i++) {
        sum = x1 + x2;
        x1 = x2;
        x2 = sum;
    }
    return sum;
}

int main(int argc, char** argv) {
    int number = 0;
    printf("Введите номер числа Фибоначчи: \n");
    scanf("%d", &number);
    int sum = 0;
    int choose = 0;
    printf("Введите 1 для работы итеративной программы, 2 - для работы рекурсивной: \n");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
        {
            sum = fibonacchi1(number);
            break;
        }
        case 2: 
        {
            sum = fibonacchi2(number);
            break;
        }
    }
    
    printf("Искомое число Фибоначчи: \n");
    printf("%d", sum);
    
    return 0;
}