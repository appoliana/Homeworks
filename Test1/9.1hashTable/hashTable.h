#pragma once

#include <string>

struct HashTable;

// создание хэш-таблицы
HashTable * createHashTable();

// вместимость таблицы
const int capacityOfHashTable(HashTable * hashTable);

// добавление элемента
void addHashElement(HashTable * hashTable, std::string value);

// распечатать таблицу
void printHashTable(HashTable * hashTable);

// удаление таблицы
void deleteHashTable(HashTable * hashTable);