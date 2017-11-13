#pragma once

//структура стека
struct Stack;

//функция, которая кладет элемент в стек
void push(Stack *stack, int value);

//функция, которая удаляет последний элемент из стека
int pop(Stack *stack);

//функция, которая проверяет, пустой ли стек
bool isEmpty(Stack *stack);

//функция, которая создает стек
Stack *createStack();

//функция удаления стека
void deleteStack(Stack *stack);


