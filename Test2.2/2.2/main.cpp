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

void mergeList(Node* tempNode1, Node* tempNode2, List &list1, List &list2, List &listResult)
{
	int element = 0;
        int length1 = 0;
        int length2 = 0;
	FILE* file = fopen("s.txt", "r");
        fscanf(file, "%d", &length1);
        while (!feof(file)) {
            for (int i = 0; i < length1; i++) {
                fscanf(file, "%d", &element);
                addElement(list1, element);
            }
            fscanf(file, "%d", &length2);
            for (int i = 0; i < length2; i++) {
                fscanf(file, "%d", &element);
                addElement(list2, element);
            }   
        }
        int count = 0;
        tempNode1 = list1.start;
        tempNode2 = list2.start;
        while (count <= length1 + length2 - 1) {
            if (tempNode1->element < tempNode2->element) {
                addElement(listResult, tempNode1->element);
                tempNode1 = tempNode1->next;
            }
            else {
                addElement(listResult, tempNode2->element);
                tempNode2 = tempNode2->next;
            }
            count++;
        }
	fclose(file);
}

int main(int argc, char** argv) 
{
	List list1;
        List list2;
        List listResult;
        
        Node* tempNode1;
        Node* tempNode2;
	mergeList(tempNode1, tempNode2, list1, list2, listResult);
        cout << "Слитый список: ";
        printList(listResult);

	deleteList(list1);
	deleteList(list2);
        deleteList(listResult);
                
	return 0;
}

