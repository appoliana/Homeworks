#include "cyclelist.h"
#include <iostream>

using namespace std;

struct cycleList {
    int number;
    cycleList *left;
    cycleList *right;
};

cycleList* createCycle() {
    return new cycleList{1, nullptr, nullptr};
}

void createCycle(cycleList* element, int amount) {
    for (int i = 2; i <= amount; ++i) {
	element->left = cycleList(i, element->left->left, element);
        if (i < amount - 1) {
            element->left->left = nullptr;
        }
        else {
            element->left->left = first;
        }
    }
}

int stayAlive(cycleList *last, int amount, int period){
    cycleList *temp = last;
    while (temp->left != temp) {
        for (int i = 1; i < period; ++i) {
            temp = temp->right;
        }
        cycleList *buffer = temp->right;
        temp->right = buffer->right;
        temp->right->left = temp;
        delete buffer;
    }
    int answer = temp->number;
    return answer;
}

cycleList* last(cycleList *first) {
    return first->left;
}