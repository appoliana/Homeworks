#pragma once

#include "list.h"

struct List;

struct ListElement;

List * createList();

List ** createArrayOfList(int size);

int numberOfElementsInList(List * list);

ListElement * pointerOnHead(List * list);

ListElement * pointerOnNextElement(ListElement * listElement);

int valueElement(ListElement * listElement);

void addElementInList(List * list, int town);

int deleteElementFromList(List * list);

List * reverseList(List * list);

void deleteList(List * list);

void deleteArrayOfList(List ** arrayOfList, int size);