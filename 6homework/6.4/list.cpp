#include "list.h"

List* createList () 
{
    return new List{new ListElement{0, nullptr}};
}

void deleteList(List *list) 
{
    while (list->sentinel) { //переносим ссылку на следующий элемент
        ListElement *temp = list->sentinel;
        list->sentinel = list->sentinel->next;
        delete temp;
    }
    delete list;
}

void insert(ListElement *previous, int value) 
{
    ListElement* newElement = new ListElement{value, previous->next};
    previous->next = newElement;
}

ListElement* first(List *list)
{
    return list->sentinel->next;
}

ListElement *sentinel(List *list)
{
    return list->sentinel;
}

ListElement* next(ListElement* element)
{
    return element->next;
}

bool isEnd(ListElement* element)
{
    return element == nullptr;
}

int value(ListElement* element)
{
    return element->value;
}

void deleteElement(ListElement *previous) 
{
    ListElement *temp = previous->next;
    previous->next = previous->next->next;
    delete temp;
}


