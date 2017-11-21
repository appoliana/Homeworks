#include <stdio.h>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
    FILE *out = fopen("HelloWorld.txt", "r"); // out -  указатель на файл // w - на запись r - на ввод
    if (out == NULL) { 
        printf("File not opened");
        return 1;
    }
    
    char *data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = NULL;
    }
    
    int readLines = 0; //  переменная которая считает количество прочитанных строк
    
    while (!feof(out)) {  // feof -- конец файла 
        char *buffer = new char[1000];
        int bytesRead = fscanf(out, "%s", buffer);
        if (bytesRead < 0) {
            break;
        }
        data[readLines] = buffer;
        ++readLines; 
    }
    
    fclose(out);
    
    for (int i = 0; i < readLines; i++) {
        printf("%s\n", data[i]);
    }
   
    for (int i = 0; i < readLines; i++) {
        delete[] data[i];
    }
    
    return 0;
}

//feof