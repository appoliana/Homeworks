#include <iostream>
#include <fstream>

#include "list.h"

using namespace std;

struct Graf {
    Graf() {
	outNotes = new int[1];
	sized = 0;
	weight_ = new int[1];
    }

    Graf add(int element, int weight) {
	int * help = new int[sized + 1];
	int * helpWeight = new int[sized + 1];
	for (int i = 0; i != sized; ++i) {
            help[i] = outNotes[i];
            helpWeight[i] = weight_[i];
        }
	help[sized] = element;
	helpWeight[sized] = weight;
	delete[] outNotes;
	delete[] weight_;
	outNotes = new int[sized + 1];
	weight_ = new int[sized + 1];
	for (int i = 0; i != sized + 1; ++i) {
            outNotes[i] = help[i];
            weight_[i] = helpWeight[i];
	}
        sized = sized + 1;
	delete[] help;
	delete[] helpWeight;
	return *this;
    }

    int * outNotes;
    int sized;
    int * weight_;
};

int main() {
    const int maxNumberOfTowns = 1000;
    Graf ** graf = new Graf*[maxNumberOfTowns];

    ifstream input("text.txt");
    int numberOfTowns = 0;
    int numberOfRoads = 0;
    input >> numberOfTowns >> numberOfRoads;

    for (int i = 0; i != numberOfTowns; ++i) {
	graf[i] = new Graf();
    }

    for (int i = 0; i != numberOfRoads; ++i) {
	int inNote = 0;
	int outNote = 0;
	int weight = 0;
	input >> inNote >> outNote >> weight;
	graf[inNote]->add(outNote, weight);
	graf[outNote]->add(inNote, weight);
    }

    const int maxNumberOfCapitals = 1000;
    List ** countries = createArrayOfList(maxNumberOfCapitals);
    bool townInCountry[maxNumberOfCapitals] { false };

    int numberOfCapitals = 0;
    input >> numberOfCapitals;

    for (int i = 0; i != numberOfCapitals; ++i) {
	countries[i] = createList();
	int capital = 0;
	input >> capital;
	addElementInList(countries[i], capital);
	townInCountry[capital] = true;
    }
    input.close();

    bool somethingIsChanged = true;
    const int maxWeight = 1000;
    while (somethingIsChanged) {
	somethingIsChanged = false;
	for (int i = 0; i != numberOfCapitals; ++i) {
            int tempMinWeight = maxWeight;
            int tempTown = -1;
            ListElement * tempElement = pointerOnHead(countries[i]);
            while (tempElement != nullptr) {
		for (int k = 0; k != graf[valueElement(tempElement)]->sized; ++k) {
                    if (!townInCountry[graf[valueElement(tempElement)]->outNotes[k]] && graf[valueElement(tempElement)]->weight_[k] < tempMinWeight) {
			tempMinWeight = graf[valueElement(tempElement)]->weight_[k];
			tempTown = graf[valueElement(tempElement)]->outNotes[k];
                    }
		}
		tempElement = pointerOnNextElement(tempElement);
            }
            if (tempTown != -1) {
		addElementInList(countries[i], tempTown);
		townInCountry[tempTown] = true;
		somethingIsChanged = true;
            }
        }
    }

    cout << "������ ���������� �� ������� �������: ";
    for (int i = 0; i != numberOfCapitals; ++i) {
	countries[i] = reverseList(countries[i]);
	cout << endl;
	cout << "������� �����������: " << deleteElementFromList(countries[i]) << endl;
	cout << "������ � �����������: ";
	int numberOfRestTowns = numberOfElementsInList(countries[i]);
	for (int j = 0; j != numberOfRestTowns; ++j) {
            cout << deleteElementFromList(countries[i]) << " ";
	}
    }

    for (int i = 0; i != numberOfTowns; ++i) {
	delete graf[i];
    }

    delete[] graf;

    deleteArrayOfList(countries, numberOfCapitals);
}