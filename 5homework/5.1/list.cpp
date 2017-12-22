#include "list.h"
#include <iostream>

using namespace std;

void deleteList(List *list) 
{
    ListElement *element = list->head;
    while (element->next != nullptr) { 
        ListElement *temp = element->next->next;
        delete element->next;
        element->next = temp;
    }
    delete list->head;
}

void insert(List *list, int value) 
{
    ListElement *element = list->head;
    if (list->head == nullptr) {
        ListElement *newElement = new ListElement;
        newElement->next = nullptr;
        newElement->value = value;
        list->head = newElement;
    }
    else {
        while (element->next != nullptr) {
            if (value  < element->value && value > element->next->value) {
                ListElement *temp = element->next;
                ListElement *newElement = new ListElement;
                newElement->next = nullptr;
                newElement->value = value;
                element->next = newElement;
                newElement->next = temp;
            }
            else {
                element = element->next;
            }
        }
    }
}

void print(List *list) {
    ListElement *element = list->head;
    while (element->next != nullptr) {
        cout << element->value;
        element = element->next;
    }
}

int deleteElement(List *list, int value) 
{
    ListElement *element = list->head;
    if(list->head->value == value) {
        ListElement *temp = list->head; 
        list->head = list->head->next; 
        delete temp;
        return 0;
    }
    while (element->next != nullptr) {
        if (element->next->value == value) {
            ListElement *temp = element->next->next;
            delete element->next;
            element->next = temp;
            return 0;
        }
        else {
            element = element->next; 
        }
    }
    cout << "В списке нет такого элемента";
}