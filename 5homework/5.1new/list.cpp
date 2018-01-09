#include "list.h"
#include <iostream>

using namespace std;

struct ListElement {
    int value;
    ListElement *next;
};

struct List {
    ListElement *head;
};

List* createList() 
{
    return new List{new ListElement{0, nullptr}};
}

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
    if (element->next == nullptr) {
        ListElement *newElement = new ListElement;
        newElement->next = nullptr;
        newElement->value = value;
        element->next = newElement;
    }
    else {
        element = element->next;
        if (value >= element->value && element->next == nullptr) {
            ListElement *newElement = new ListElement;
            newElement->value = value;
            element->next = newElement;
            newElement->next = nullptr;
        }
        else if (value < element->value ) {
            ListElement *newElement = new ListElement;
            newElement->value = value;
            newElement->next = element;
            list->head->next = newElement;
        } else {
            while (true) {
                if (element->next == nullptr) {
                    ListElement *newElement = new ListElement;
                    newElement->value = value;
                    newElement->next = nullptr;
                    element->next = newElement;
                    break;
                } else if (value > element->value && value <= element->next->value) {
                    ListElement *temp = element->next;
                    ListElement *newElement = new ListElement;
                    newElement->value = value;
                    element->next = newElement;
                    newElement->next = temp;
                    break;
                } else {
                    element = element->next;
                }
            }
        }
    }
}

void print(List *list) {
    cout << "Распечатанный список: " << endl;
    ListElement *element = list->head;
    while (element->next != nullptr) {
        cout << element->next->value;
        element = element->next;
    }
    cout << endl;
}

int deleteElement(List *list, int value) 
{
    ListElement *element = list->head;
    if (element->next->value == value) {
        ListElement *temp = element->next->next;
        delete element->next;
        list->head->next = temp; 
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