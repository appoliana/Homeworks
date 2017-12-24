#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

#include "tree.h"

using namespace std;

int main(int argc, char** argv)
{
    Tree *tree = createTree();

    ifstream input("text.txt");
    while (!input.eof()) {
	string operatorOrOperand;
	input >> operatorOrOperand;
	if (operatorOrOperand != "(" && operatorOrOperand != ")")
	{
            addElement(tree, operatorOrOperand);
	}
    }
    input.close();

    cout << "Дерево: " << printTree(tree) << endl;
    cout << "Результат вычисления: " << countExpression(tree) << endl;

    deleteTree(tree);
        
    return 0;
}