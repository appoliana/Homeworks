#pragma once

using namespace std;

struct List;
struct ListElement;

// функция создания списка
List* createList();

// функция добавления значения в список
void insert(ListElement *previous, int value, ListElement *parent);

// удаление списка
void deleteList(List *list);

ListElement *first(List *list);

ListElement *sentinel(List *list);

// функция проверки на крнец списка
bool isEnd(ListElement *temp);

// обращение к следующему 
ListElement *next(ListElement *temp);

// родитель
ListElement *parent(ListElemet *temp);

// значение
int value(ListElement *temp);

// удаление элемента
void deleteElement(ListElement *previous);

// разворот списка
void reverse(struct List ** sentinel);

// номер элемента в списке
void printElement(List* list, int number);

// печать списка с первго элемента
void printList(List* list);

// печать списка с последнего элемента
void printListChange(List* list);



