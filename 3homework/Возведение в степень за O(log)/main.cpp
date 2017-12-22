

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int Binpow(int number, int power) {
   if (power == 0) {
      return 1;
   }
   if (power % 2 == 1) {
      return (Binpow(number, power - 1) * number);
   }
   if (power % 2 == 0) {
      int dop = Binpow(number, power - 1);
      return (dop * dop); 
   }
}

int main(int argc, char** argv) {
    int number = 0;
    int power = 0;
    int value = 0;
    printf("Введите число: \n");
    scanf("%d", &number);
    printf("Введите степень числа: \n");
    scanf("%d", &power);
    printf("Полученное значение: \n");
    value = Binpow(number, power);
    printf("%d", value);
    return 0;
}

