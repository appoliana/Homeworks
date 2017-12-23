#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

long change(long x)
{
    long y = 0;
    while (x) {
	y = y * 10 + x % 10;
	x /= 10;
    }
    return y;
}

void countElements(int &length) 
{
    FILE * File = fopen("f.txt", "r");
    int p = 0;
    while (!feof(File)) {
	fscanf(File, "%d", &p);
	++length;
    }
    fclose(File);
}


int main(int argc, char** argv)
{
    int length = 0;
    countElements(length);
    int *array = new int[length];

    cout << length << endl;

    FILE * File = fopen("f.txt", "r");
    for (int i = 0; i < length; ++i) {
	fscanf(File, "%d", &array[i]);
    }
    fclose(File);

    for (int i = 0; i < length; ++i) {
	array[i] = change(array[i]);
    }

    FILE * File1 = fopen("f.txt", "w");
    for (int i = 0; i < length; ++i) {
        fprintf(File1, "%d ", array[i]);
        fprintf(File1, "%d ", ' ');
    }
    fclose(File1);
	
    for (int i = 0; i < length; ++i) {
        cout << array[i];
    }

    delete[] array;
    return 0;
}