#pragma once

struct ListElement {
    Directory contact;
    ListElement *next;
};

struct List {
    ListElement *first;
    ListElement *last;
};

struct Directory {
    char name[20];
    char phone[20];
};

List* createList();

void insert(ListElement *previous, int value);

void deleteList(List *list);

ListElement *first(List *list);

ListElement *sentinel(List *list);

bool isEnd(ListElement *temp);

ListElement *next(ListElement *temp);

int value(ListElement *temp);

void deleteElement(ListElement *previous);

