
#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int number = 0;
    int power = 0;
    int value = 1;
    printf("Введите число: \n");
    scanf("%d", &number);
    printf("Введите степень числа: \n");
    scanf("%d", &power);
    for (int i = 0; i < power; ++i) {
        value *= number;
    }
    printf("Полученное значение: \n");
    printf("%d", value);
    return 0;
}

