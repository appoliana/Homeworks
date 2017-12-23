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
    while(!feof(outF)) {
        if (fscanf(outF, "%d", &value) != -1)
            length ++;
    }
    cout << length;
    return 0;
}

