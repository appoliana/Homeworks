#include "list.h"

#include <string>

using namespace std;

struct ListElement
{
    string value;
    ListElement * next = nullptr;
};

struct List
{
    int numberOfElements = 0;
    ListElement * head = nullptr;
};

List * createList()
{
    List * list = new List;
    return list;
}

List ** createArrayOfList(const int capacity)
{
    List ** result = new List*[capacity];
    for (int i = 0; i != capacity; ++i) {
        result[i] = new List;
    }
    return result;
}

int numberOfElementsInList(List * list)
{
    return list->numberOfElements;
}

ListElement * pointerOnFirstElement(List * list)
{
    return list->head;
}

void addElement(List * list, string value)
{
    ListElement * listElement = new ListElement;
    listElement->value = value;
    listElement->next = list->head;
    list->head = listElement;
    ++list->numberOfElements;
}

void deleteElement(List * list)
{
    ListElement *temp = list->head;
    list->head = list->head->next;
    --list->numberOfElements;
    delete temp;
}

string headValue(List* list)
{
    return list->head->value;
}

void deleteList(List * list)
{
    while (list->head != nullptr) {
	deleteElement(list);
    }
    delete list;
}