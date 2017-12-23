#include "hashTable.h"
#include "list.h"
#include <string>
#include <iostream>

using namespace std;

const int capacity = 2;
const int sizeOfArrays = 100;

struct HashTable 
{
    List ** hashTable = createArrayOfList(capacity);
};

HashTable * createHashTable()
{
    HashTable * result = new HashTable;
    return result;
};

const int capacityOfHashTable(HashTable * hashTable)
{
    return capacity;
}

int hashFunction(HashTable * hashTable, string value)
{
    int result = 0;
    for (int i = 0; i != value.size(); ++i) {
        result += (i + 1) * static_cast<int>(value[i]);
    }
    return result % capacity;
}

void addHashElement(HashTable * hashTable, string value)
{
    int number = hashFunction(hashTable, value);
    addElement(hashTable->hashTable[number], value);
}

void printHashTable(HashTable * hashTable)
{
    for (int i = 0; i != capacity; ++i) {
        if (pointerOnFirstElement(hashTable->hashTable[i]) != nullptr) {
            string words[sizeOfArrays];
            int numberOfEachWord[sizeOfArrays] = { 0 };
            int numberOfElements = numberOfElementsInList(hashTable->hashTable[i]);
            int currentSizeOfArrays = 0;
            for (int j = 0; j != numberOfElements; ++j) {
                string word = headValue(hashTable->hashTable[i]);
                int k = 0;
                while (true) {
                    if (words[k] == word) {
                        ++numberOfEachWord[k];
                        break;
                    }
                    if (words[k] == "") {
                        words[k] = word;
                        ++numberOfEachWord[k];
                        ++currentSizeOfArrays;
                        break;
                    }
                    ++k;
                }
                deleteElement(hashTable->hashTable[i]);
            }
            for (int l = 0; l != currentSizeOfArrays; ++l) {
                cout << "Слово " << words[l];
                cout << " Встречается " << numberOfEachWord[l] << " раз";
                cout << endl;
            }
        }
    }
}

void deleteHashTable(HashTable * hashTable)
{
    for (int i = 0; i != capacity; ++i) {
        deleteList(hashTable->hashTable[i]);
    }
    delete[] hashTable->hashTable;
    delete hashTable;
}
