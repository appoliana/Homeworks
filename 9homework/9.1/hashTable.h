#pragma once
#include <string>

struct HashTable;

// создание хэш таблицы
HashTable *createHashTable();

// вместимость
int capacityOfHashTable(HashTable *hashTable);

// добавление элемента в хэш таблицу
void addHashElement(HashTable *hashTable, std::string value);

// печать хэш таблицы 
void printHashTable(HashTable *hashTable);

// удаление элемента из хэш таблицы
void deleteHashTable(HashTable *hashTable);