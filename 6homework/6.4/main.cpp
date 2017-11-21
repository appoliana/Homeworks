#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void fileFile () {
    FILE *in = fopen("file.txt", "wr");
    fclose(in);
}

int main(int argc, char** argv) {
    List* list = createList();
    fileFile;
    FILE *out = fopen("file.txt", "r");
    /*if (out == NULL) { 
        printf("File not opened");
        return 1;
    }
    /*for (ListElement *i = first(list); !isEnd(i); i = next(i)) { 
        char *data[100];
        for (int i = 0; i < 100; i++) {
            data[i] = NULL;
        }
        int readLines = 0;
        while (!feof(out)) {  // feof -- конец файла 
            char *buffer = new char[1000];
            int bytesRead = fscanf(out, "%s", buffer);
                if (bytesRead < 0) {
                break;
            }
            data[readLines] = buffer;
            insert(next(first(list)), buffer);
            ++readLines; 
    }
    fclose(out);
    }
    
    
    //сортировка
    /*int chose = 0;
    cout << "Введите 1, если хотите отсортировать записи по номерам, 2 - если хотите отсортировать записи по имени" << endl;
    cin >> choose;
    switch (choose) {
        case 1: 
        {
            
        }
        case 2:
        {
            
        }
    }
    */
    return 0;
}

