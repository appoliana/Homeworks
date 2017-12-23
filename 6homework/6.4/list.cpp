#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	string element = "0";
	Node* next = nullptr;
};

struct List
{
	Node* start = nullptr;
        Node* last = nullptr;
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

void addElement(List& list, string element)
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

void mergeByPhone(Node* tempNode1, Node* tempNode2, List &list1, List &list2, int count) {
    tempNode1 = list1.start->next;
    tempNode2 = list2.start->next;
    int length = 0;
    while (length <= count) {
        if (tempNode1->element < tempNode2->element) {
            Node* tempNode3 = tempNode1->element->next;
            tempNode1->element->next = tempNode2;
            tempNode2->next = tempNode3;
        }
        else {
            tempNode1->element = tempNode->element->next->next;
            length++;
        }
    }
}

void mergeByName(Node* tempNode1, Node* tempNode2, List &list1, List &list2, int count) {
    tempNode1 = list1.start;
    tempNode2 = list2.start;
    int length = 0;
    while (length <= count) {
        if (tempNode1->element < tempNode2->element) {
            Node* tempNode3 = tempNode1->element->next;
            tempNode1->element->next = tempNode2;
            tempNode2->next = tempNode3;
        }
        else {
            tempNode1->element = tempNode->element->next->next;
            length++;
        }
    }
}

void initialisation(Node* tempNode1, Node* tempNode2, List &list1, List &list2, int choose)
{
	string element = "0";
        int count = 0;
	FILE* file = fopen("s.txt", "r");
        if (!feof(file)) {
            fscanf(file, "%d", &element);
            addElement(list2, element);
            fscanf(file, "%d", &element);
            addElement(list2, element);
            count++;
        }
        if (feof(file)) {
            fclose(file);
            return 2;
        }
        
        if (choose == 0) 
        {
            mergeName(tempNode1, tempNode2, list1, list2, count);
        }
        else 
        {
            mergePhone(tempNode1, tempNode2, list1, list2, count);
        }
        
        initialisation(tempNode1, tempNode2, list1, list2, choose);   
}



