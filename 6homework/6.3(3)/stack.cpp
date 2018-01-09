#include "stack.h"

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

bool isEmpty (Stack *stack) {
    return !stack->head;
}

void push(Stack *stack, int value) {
    StackElement* newElement = new StackElement{value, stack->head}; 
    stack->head = newElement;
}

int pop(Stack *stack) {
    StackElement* newHead = stack->head->next;
    int val = stack->head->value;
    delete stack->head;
    stack->head = newHead;
    return val;
}

int top(Stack *stack) {
    int value = stack->head->value;
    return value;
}

int countOfElements(Stack *stack) {
    int count = 0;
    while (!isEmpty(stack)) {
        count++;
    }
    return count;
}
