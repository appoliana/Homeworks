
#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int Prime_number;
    scanf("%d", &Prime_number);
    int divider;
    int count = 0;
    for(int number = 2; number < Prime_number; number++){
       for( divider = 2; divider < number; divider++){
            if (number % divider == 0)
                count++;
        }
       if (count == 0){
           printf("%d\n", number);
       } count = 0;
    }
    return 0;
}
