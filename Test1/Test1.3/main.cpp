#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    FILE *out = fopen("HelloWorld.txt", "r"); 
    if (out == NULL) { 
        printf("File not opened");
        return 1;
    }
    char *data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = NULL;
    }
    int readLines = 0; 
    while (!feof(out)) {  
        char *buffer = new char[1000];
        int bytesRead = fscanf(out, "%s", buffer);
        if (bytesRead < 0) {
            break;
        }
        data[readLines] = buffer;
        ++readLines; 
    }
    fclose(out);
    
    cout << "Максимум строка может быть 1000 символов!" << endl;
    for (int i = 0; i < readLines; i++) {
        char string[1001];
        strcpy(string, data[i]);
        for (int i = 0; i < strlen(string); i++) {
            if (string[i] == string[i + 1]) {
                continue;
         }
        cout << string[i];
        }
        cout << endl;
    }
 
    for (int i = 0; i < readLines; i++) {
        delete[] data[i];
    }
    return 0;
}

// ahhhdg