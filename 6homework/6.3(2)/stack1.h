#pragma once

struct Stack;

// функция, которая кладет элемент в стек
void push (Stack *stack, int value);

// функция, которая забирает последней элемент из стека
int pop (Stack *stack);

//получение значения верхнего элемента без его удаления
int top (Stack *stack);

// функция, которая проверяет, пуст ли стек
bool isEmpty(Stack *stack);

// создание стека
Stack *createStack();

// удаление стека
void deleteStack(Stack *stack);

