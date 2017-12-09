#include <iostream>
#include <fstream>

using namespace std;

const int maxNumbOfNodes = 20;

void algorithmOfPrim(int numbOfNodes, int graf[maxNumbOfNodes][maxNumbOfNodes], int spanningTree[maxNumbOfNodes][maxNumbOfNodes])
{
    const int infinity = 100000;
    bool visitedNodes[maxNumbOfNodes] { false };
    visitedNodes[0] = true;
    bool somethingIsChanged = true;
    while (somethingIsChanged) {
	somethingIsChanged = false;
	int tempOut = -1;
	int tempIn = -1;
	int tempMin = infinity;
	for (int i = 0; i != numbOfNodes; ++i) {
            if (visitedNodes[i]) {
		for (int j = 0; j != numbOfNodes; ++j) {
                    if (!visitedNodes[j] && tempMin > graf[i][j] && graf[i][j] != 0) {
			tempOut = i;
			tempIn = j;
			tempMin = graf[i][j];
			somethingIsChanged = true;
                    }
		}
            }
        }
	if (somethingIsChanged) {
            spanningTree[tempIn][tempOut] = tempMin;
            spanningTree[tempOut][tempIn] = tempMin;
            visitedNodes[tempIn] = true;
            visitedNodes[tempOut] = true;
	}
    }
}

// построенное остовное дерево
void printSpanningTree(int numbOfNodes, int spanningTree[maxNumbOfNodes][maxNumbOfNodes])
{
    for (int i = 0; i != numbOfNodes; ++i) {
	for (int j = 0; j != numbOfNodes; ++j) {
            cout << spanningTree[i][j] << " ";
	}
	cout << endl;
    }
}

int main(int argc, char** argv) {
    int graf[maxNumbOfNodes][maxNumbOfNodes];
    int spanningTree[maxNumbOfNodes][maxNumbOfNodes];

    fstream input("graf.txt");
    if (input.eof()) {
	cout << "Error" << endl;
        return 1;
    }

    int numbOfNodes = 0;
    input >> numbOfNodes;
    for (int i = 0; i != numbOfNodes; ++i) {
        for (int j = 0; j != numbOfNodes; ++j){
            graf[i][j] = 0;
            spanningTree[i][j] = 0;
        }
    }
    for (int i = 0; i != numbOfNodes; ++i) {
        for (int j = 0; j != numbOfNodes; ++j) {
            input >> graf[i][j];
        }
    }
    input.close();

    algorithmOfPrim(numbOfNodes, graf, spanningTree);
    cout << "Минимальное остовное дерево: " << endl;
    printSpanningTree(numbOfNodes, spanningTree);

    return 0;
}

