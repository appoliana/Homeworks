#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	int element = 0;
	Node* next = nullptr;
};

struct List
{
	Node* start = nullptr;
};

Node* newNode(int element, Node *next = nullptr)
{
	Node* result = new Node();
	result->element = element;
	result->next = next;
	return result;
}

Node* last(List& list, int element)
{
	if (list.start == nullptr)
	{
		return nullptr;
	}

	Node* node = list.start;
	while (node->next != nullptr)
	{
		node = node->next;
	}

	return node;
}

void addElement(List& list, int element)
{
	Node* previousNode = last(list, element);
	if (previousNode != nullptr)
	{
		previousNode->next = newNode(element, previousNode->next);
	}
	else
	{
		list.start = newNode(element, list.start);
	}
}

bool isEnd(List* element)
{
    return element == nullptr;
}

void printList(List& list)
{
	Node* node = list.start;

	if (node != nullptr)
	{
		while (node != nullptr)
		{
			cout << node->element << " ";
			node = node->next;
		}
	}
}

void deleteList(List& list)
{
	while (list.start != nullptr)
	{

		Node* node = list.start;
		list.start = list.start->next;
		delete node;
	}
}

//1 4 2 3 5 6 8 3 2 4 

void initionList(List &listA, List &listAB, List &listB, int a ,int b)
{
	int element = 0;
	FILE* file = fopen("s.txt", "r");
        while (!feof(file)) {
                fscanf(file, "%d", &element);
                if (element < a) 
                {
                    addElement(listA, element);
                }
                if (element >= a && element <= b) 
                {
                    addElement(listAB, element);
                }
                if (element > b) 
                {
                 addElement(listB, element);
                }
        }
	fclose(file);
}

int main(int argc, char** argv) 
{
        int a = 0;
        int b = 0;
        cout << "Введите отрезок [a,b]: " << endl;
        cin >> a >> b;
	List listA;
        List listAB;
        List listB;
        
	initionList(listA, listAB, listB, a, b);
        printList(listA);
        printList(listAB);
        printList(listB);

	deleteList(listB);
	deleteList(listA);
        deleteList(listAB);
                
	return 0;
}


