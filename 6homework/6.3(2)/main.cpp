#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack1.h"

using namespace std;


int main() {
	Stack *stack = createStack();
	string expression = "";
	cout << "Введите выражение в инфиксной форме: ";
	getline(cin, expression);
	string result = shuntingYard(expression, stack);

	cout << "Выражение в постфиксной форме: " << result << endl;
	deleteStack(stack);

	return 0;
}
