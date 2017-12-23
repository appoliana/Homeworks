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
    FILE *outG = fopen("g.txt", "r"); 
    if (outG == nullptr) { 
        printf("File not opened");
        return 1;
    }

    char *data[1] = {0};
    while (!feof(outF)) {  
        char *buffer = new char[1];
        int bytesRead = fscanf(outF, "%s", buffer);
        if (bytesRead < 0) {
            delete[] buffer;
            break;
        }
        data[0] = buffer; 
    }
    fclose(outF);
    cout << "Числа из первого файла: " << data[0] << endl;

    char *data1[1] = {0};
    while (!feof(outG)) {  
        char *buffer1 = new char[1];
        int bytesRead2 = fscanf(outG, "%s", buffer1);
        if (bytesRead2 < 0) {
            delete[] buffer1;
            break;
        }
        data1[0] = buffer1;
    }
    fclose(outG);
    cout << "Второе число: " << data1[0] << endl;
    
    ofstream output("h.txt", ios_base::trunc);
    output << "Числа, большие заданного: ";
    for (int i = 0; data[0][i] != '\0'; ++i) {
        if (putchar(data[0][i]) > putchar(data1[0][0])) {
            output << data[0][i];        
        }  
    } 
    output.close();
     
    delete[] data[0];
    delete[] data1[0];
    
    return 0;
}
