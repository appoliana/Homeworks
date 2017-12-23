#pragma once
#include <string>

struct HashTable;

// Создание хэш таблицы
HashTable * createHashTable();

// Ключ
const int capacityOfHashTable(HashTable * hashTable);

// Добавление элемента 
void addHashElement(HashTable * hashTable, std::string value);

// Печать хэш таблицы 
void printHashTable(HashTable * hashTable);

// Удаление элемента
void deleteHashTable(HashTable * hashTable);