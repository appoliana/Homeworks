#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    FILE *outF = fopen("f.txt", "r"); 
    if (outF == nullptr) { 
        printf("File not opened");
        return 1;
    }

    int length = -1;
    int value = 0;
    while(!feof(outF)) {
        value = fgetc(outF);
        length ++;
    }
    cout << length << endl;
    
    int * array = new int [length];
    int i = 0;
    //здесь какой-то баг
    while ((array[i] = fgetc(outF)) != EOF) {
        cout << array[i];
        i++;
    }
    fclose(outF);
    
    FILE *outR = fopen("f.txt", "w"); 
    cout << "Перевернутые числа: ";
    for (int i = length; i > 0; i--) {
        fprintf(outR, "%d" , array[i]); 
    }
    fclose(outR);
    
    delete[] array;
    return 0;
}

// 15 3 82 13 7
// 7 31 28 3 51


