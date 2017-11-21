#include <stdio.h>
#include <cstdlib>
#include <memory>

using namespace std;

int main(int argc, char** argv) {
    int longArray = 0;
    scanf("%d", &longArray);
    int array[longArray];
    for (int i = 0; i < longArray; i++) {
        array[i] = rand () % 10;
        printf("%d", array[i]);
    }
    printf("\n");
    
    for (int i = 0; i < longArray; i++) {
        for (int j = i; j < longArray; j++) {
         if (array[j] < array[j+1]){
             swap(array[j], array[j+1]);
         }   
        }
    }
    for (int i = 0; i < longArray; i++) {
        printf("%d", array[i]);
    }
    return 0;
}

