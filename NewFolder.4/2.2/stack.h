#pragma once

struct Stack;

void push(Stack *stack, int value);

int pop(Stack *stack);

bool isEmpty(Stack *stack);

Stack *createStack();

void deleteStack(Stack *stack);

int topElement(Stack *stack);

