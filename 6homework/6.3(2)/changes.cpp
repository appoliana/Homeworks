#include "changes.h"

using namespace std;

int priorityOperations(char symbol);

string changes(const string expression, Stack *stack)
{
	string result = "";
	string notSingleValuedNumber = "";

	int i = 0;
	while (i <= expression.length()) {
		if (isdigit(expression[i])) {
			notSingleValuedNumber += expression[i];
		} else if ((!isdigit(expression[i])) && notSingleValuedNumber.length() > 0) {
			result += notSingleValuedNumber + " ";
			notSingleValuedNumber = "";
			continue;
		} else if (expression[i] == '(') {
			push(stack, expression[i]);
		} else if (expression[i] == ')') {
			while (top(stack) != '(') {
				string symbol(1, pop(stack));
				result += symbol + " ";
			}
			pop(stack);
		} else if (isEmpty(stack) && expression[i] != ' ') {
			push(stack, expression[i]);
		} else if (expression[i] != ' ') {
			while ((!isEmpty(stack)) && priorityOperations(expression[i]) <= priorityOperations(top(stack))) {
				string symbol(1, pop(stack));
				result += symbol + " ";
			}
			push(stack, expression[i]);
		}
		i++;
	}

	while (!isEmpty(stack)) {
		string symbol(1, pop(stack));
		result += symbol + " ";
	}

	return result;
}

int priorityOperations(char symbol)
{
	switch (symbol) {
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	}
}