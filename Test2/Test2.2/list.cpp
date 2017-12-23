#include "list.h"

using namespace std;

struct List {
    ListElement *sentinel;
};

struct ListElement {
    int value;
    ListElement *next;
    ListElement *parent;
};

List* createList () 
{
    return new List{new ListElement{0, nullptr, nullptr}};
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

void insert(ListElement *previous, int value, ListElement *parent) 
{
    ListElement* newElement = new ListElement{value, previous->next, previous->parent};
    previous->next = newElement;
    previous->parent = previous;
    
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

ListElement* parent(ListElement *element) 
{
    return element->parent;
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

/* из интернета фигня какая-то
void reverse(struct List ** sentinel)
{
    if (*sentinel == nullptr) return;
    struct List * current, *next, *previous = nullptr;
    current = *sentinel;
    while(current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *sentinel = previous;
}
 */

/* 
void printElement(List* list, int number) {
    if (number = 1) {
        cout << list->sentinel->next->value;
    }
    int i = 2;
    if (!isEnd) {
        while (i < number) {
            i++;
            list->sentinel->next->next;
        }
    }
}
 */

void printList(List* list) {
    while (!isEnd) {
        int dop = list->sentinel->next->value;
        cout << dop;
    }
}

void printListChange(List* list) { //печать списка начиная с последнего элемента
    //получаем ссылку на последний элемент (как? сложно)
    while (!isEnd) {
        cout << list->//последний 
                ->parent->value;
    }
}


