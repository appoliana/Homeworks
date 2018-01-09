#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int status(char symbol) {
    if (symbol == '/')
        return 0;
    if (symbol == '*')
        return 1;
    return 2;
}

int main(int argc, char** argv) {
    int n = 0;
    int m = 0;
    string str;
    ifstream input("text.txt");
    input >> n >> m;
    int **tableOfStates = new int *[n];
    while (!input.eof()) {
        for (int i = 0; i < n ; ++i) {
            tableOfStates[i] = new int[m];
            for (int j = 0; j < m ; ++j) {
                input >> tableOfStates[i][j];
                cout << tableOfStates[i][j];
            }
            cout << endl;
        }
        while (!input.eof()) {
            input >> str;
            cout << str;
        }
    }
    cout << endl;
    input.close();
    
    int i = 0;
    int dop = status(str[i]);
    //cout << dop;
    int dop1 = 0;
    for (i = 1; i < str.length(); ++i) 
    {
        dop1 = status(str[i]);
        if (tableOfStates[dop][dop1] == 1) 
        {
            cout << str[i - 1];
            while (tableOfStates[dop][dop1] != 2) 
            {
                cout << str[i];
                dop = status(str[i]);
                i++;
                dop1 = status(str[i]);
            }
            cout << str[i];
        }
        dop = status(str[i]);
    }
    return 0;
}