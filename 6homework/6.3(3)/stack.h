#pragma once

struct StackElement;

struct Stack;

void push(Stack *stack, int value);

int pop(Stack *stack);

bool isEmpty(Stack *stack);

Stack *createStack();

void deleteStack(Stack *stack);

int top(Stack *stack);

int countOfElements(Stack *stack);

