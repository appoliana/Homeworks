#include "stack.h"
#include <iostream>

using namespace std;

struct StackElement {
    int value;
    StackElement *next;
};

struct Stack {
    StackElement *head; 
};

Stack *createStack() {
    return new Stack{};
}

void deleteStack(Stack *stack) {
    while (!isEmpty(stack)) { //переносим ссылку на следующий элемент
        StackElement *temp = stack->head;
        stack->head = stack->head->next;
        delete temp;
    }
    delete stack;
}

bool isEmpty(Stack *stack) {
    return !stack->head;
}

void push(Stack *stack, int value) {
    StackElement* newElement = new StackElement{value, stack->head}; 
    stack->head = newElement;
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) 
    {
        StackElement* newHead = stack->head->next;
        int value = stack->head->value;
        delete stack->head;
        stack->head = newHead;
        return value;
    }
    else 
    {
        cout << "Нельзя удалить элемент из пустого стека =(" << endl;
        return 0;
    }
}

int topElement(Stack *stack) {
    StackElement* newHead = stack->head->next;
    int value = stack->head->value;
    stack->head = newHead;
    return value;
}
