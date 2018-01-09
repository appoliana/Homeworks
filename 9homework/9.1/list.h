#pragma once
#include <string>

struct List;

struct ListElement;

// cоздание списка
List * createList();

// cоздание массива списков
List **createArrayOfList(int capacity);

// количество элементов в одном списке (с коллизиями)
int numberOfElementsInList(List *list);

// указатель на первый элемент в списке
ListElement *pointerOnFirstElement(List *list);

// добавление элемента в список
void addElement(List *list, std::string value);

// удаление элемента из списка
void deleteElement(List *list);

// значение элемента в голове
std::string headValue(List *list);

// удаление списка
void deleteList(List *list);