#include "hashTable.h"
#include "list.h"
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    HashTable * hashTable = createHashTable();

    ifstream input("text.txt");
    while (!input.eof()) {
	string word;
	input >> word;
	addHashElement(hashTable, word);
    }
    input.close();

    printHashTable(hashTable);

    deleteHashTable(hashTable);
    
    return 0;
}

