#pragma once

#include <string>

struct List;

struct ListElement;

// создание списка
List * createList();

// создание массива списка
List ** createArrayOfList(int capacity);

// номер элемента в списке
int numberOfElementsInList(List * list);

// указатель на элемент
ListElement * pointerOnFirstElement(List * list);

// добавление элемента
void addElement(List * list, std::string value);

// удаление элемента списка
void deleteElement(List * list);

std::string headValue(List * list);

// удаление списка
void deleteList(List * list);