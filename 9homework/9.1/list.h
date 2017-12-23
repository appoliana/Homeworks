#pragma once
#include <string>

struct List;

struct ListElement;

// Создание списка
List * createList();

// Создание массива
List ** createArrayOfList(int capacity);

// ×èñëî ýëåìåíòîâ â ñïèñêå.
size_t numberOfElementsInList(List * list);

// Óêàçàòåëü íà ïåðâûé ýëåìåíò ñïèñêà.
ListElement * pointerOnFirstElement(List * list);

// Добавление элемента в список
void addElement(List * list, std::string value);

// Удаление элемента из списка
void deleteElement(List * list);

// Ïåðâûé ýëåìåíò â ñïèñêå.
std::string headValue(List * list);

// Удаление списка
void deleteList(List * list);