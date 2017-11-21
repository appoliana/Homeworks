#pragma once

struct ListElement {
    int value;
    ListElement *next;
};


struct List {
    ListElement *sentinel;
};

List* createList();

void insert(ListElement *previous, int value);

void deleteList(List *list);

int move(List *list, int number);

ListElement *first(List *list);

ListElement *sentinel(List *list);

bool isEnd(ListElement *temp);

ListElement *next(ListElement *temp);

int value(ListElement *temp);

void deleteElement(ListElement *previous);

