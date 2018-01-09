#include <fstream>
#include <string>
#include <iostream>

#include "hashTable.h"

using namespace std;

int main(int argc, char** argv) {
    HashTable *hashTable = createHashTable();
    ifstream input("text.txt");
    string word;
    while (!input.eof()) {
	input >> word;
	addHashElement(hashTable, word);
    }
    input.close();

    printHashTable(hashTable);

    deleteHashTable(hashTable);
    
    return 0;
}
