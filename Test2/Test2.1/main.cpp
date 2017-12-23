#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

void searchMaxDate(int length, int arrayDay[], int arrayMonce[], int arrayYear[]) {
    int maxDay = 0;
    int maxMonce = 0;
    int maxYear = 0;
    for (int i = 0; i < length; i++) {
        if (arrayYear[i] > maxYear) {
                maxYear = arrayYear[i];
                maxMonce = arrayMonce[i];
                maxDay = arrayDay[i];
        }
        if (arrayYear[i] == maxYear) {
            if (arrayMonce[i] > maxMonce) {
                maxMonce = arrayMonce[i];
                maxDay = arrayDay[i];
            }
            if (arrayMonce[i] == maxMonce) {
                if (arrayDay[i] > maxDay) {
                    maxDay = arrayDay[i];
                }
            }  
        }
    }
    cout << "Наибольшая дата: " << maxDay << "/" << maxMonce << "/" << maxYear;
}

int main(int argc, char** argv) {
    FILE *outS = fopen("s.txt", "r"); 
    if (outS == nullptr) { 
        printf("File not opened");
        return 1;
    }
    int value = 0;
    int length = 4;
    while(!feof(outS)) {
        if (fscanf(outS, "%d", &value) != -1)
            length ++;
    }
    length = length / 3;
    cout << "Количество дат в файле: " << length << endl;
    
    int *arrayDay = new int[length];
    int *arrayMonce = new int[length];
    int *arrayYear = new int[length];
    for (int i = 0; i < length; i++) {
        arrayDay[i] = fscanf(outS, "%d", &value);
        arrayMonce[i] = fscanf(outS, "%d", &value);
        arrayYear[i] = fscanf(outS, "%d", &value);
    }
    fclose(outS);
    
    searchMaxDate(length, arrayDay, arrayMonce, arrayYear);
    
    delete[] arrayYear;
    delete[] arrayMonce;
    delete[] arrayDay;
    return 0;
}

