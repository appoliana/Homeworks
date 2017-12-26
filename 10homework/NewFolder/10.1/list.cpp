#include "list.h"

struct ListElement
{
    int town = 0;
    ListElement * next = nullptr;
};

struct List
{
    int numberOfElements = 0;
    ListElement * head = nullptr;
};

List * createList()
{
    List * result = new List;
    return result;
}

List ** createArrayOfList(int size)
{
    List ** result = new List*[size];
    return result;
}

int numberOfElementsInList(List * list)
{
    return list->numberOfElements;
}

ListElement * pointerOnHead(List * list)
{
    return list->head;
}

ListElement * pointerOnNextElement(ListElement * listElement)
{
    return listElement->next;
}

int valueElement(ListElement * listElement)
{
    return listElement->town;
}

void addElementInList(List * list, int town)
{
    ListElement * listElement = new ListElement;
    listElement->town = town;
    listElement->next = list->head;
    list->head = listElement;
    ++list->numberOfElements;
}

int deleteElementFromList(List * list)
{
    int tempValue = list->head->town;
    ListElement * temp = list->head;
    list->head = list->head->next;
    --list->numberOfElements;
    delete temp;
    return tempValue;
}

List * reverseList(List * list)
{
    List * tempList = new List;
    while (list->head != nullptr) {
	addElementInList(tempList, deleteElementFromList(list));
    }
    delete list;
    return tempList;
}

void deleteList(List * list)
{
    if (list->head != nullptr) {
        int temp = deleteElementFromList(list);
    }

    delete list;
}

void deleteArrayOfList(List ** arrayOfList, int size)
{
    for (int i = 0; i != size; ++i) {
	deleteList(arrayOfList[i]);
    }

    delete[] arrayOfList;
}