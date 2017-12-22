#include "stack.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>

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
    while (!isEmpty(stack)) { 
        StackElement *temp = stack->head;
        stack->head = stack->head->next;
        delete temp;
    }
    delete stack;
}

bool isEmpty (Stack *stack) {
    return !stack->head;
}

void push(Stack *stack, int value) {
    StackElement* newElement = new StackElement;
    newElement->value = value;
    newElement->next = stack->head;
    stack->head = newElement;
}

int pop(Stack *stack) {
    StackElement* newHead = stack->head->next;
    int val = stack->head->value;
    delete stack->head;
    stack->head = newHead;
    return val;
}