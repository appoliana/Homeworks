#pragma once

struct ListElement {
    int value;
    ListElement *next;
};

struct List {
    ListElement *head = nullptr;
};

//печать всех элементов списка
void print(List *list);

//добавление элемента в отсортированный список
void insert(List *list, int value);

//удаление всего списка
void deleteList(List *list);

//удаление конкретного элемента из списка
int deleteElement(List *list, int value);