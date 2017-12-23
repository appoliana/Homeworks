#include <iostream>
#include <locale.h>
#include "cyclelist.h"

using namespace std;

int main(int argc, char** argv) {
    int n = 0;
    int m = 0;
    cout << "Введите количество воинов: ";
    cin >> n;
    cout << "Введите периодичность(убивают по кругу каждого m-го): ";
    cin >> m;

    cycleList *first = createList();

    createCircle(first, n);

    cout << "Если воин встанет на " << stayAlive(last(first), n, m) << "позицию, то останется последним";

    return 0;
}