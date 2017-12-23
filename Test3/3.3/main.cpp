#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void BFS(bool *visited, int unit, int countsOfTop, int **matrix)
{
    int *queue = new int[countsOfTop];
    int count = 0;
    int head = 0;
    for (int i = 0; i < countsOfTop; i++) {
        queue[i] = 0;
    }
    queue[count++] = unit;
    visited[unit] = true;
    while (head < count)
    {
        unit = queue[head++];
        cout << unit + 1 << " ";
        for (int i = 0; i < countsOfTop; i++) {
            if (matrix[unit][i] == 1 && visited[i] == false)
            {
                queue[count++] = i;
                visited[i] = true;
            }
        }
    }
    delete[] queue;
}

int main(int argc, char** argv) {
    ifstream input("s.txt");
    int countsOfTop = 0;
    input >> countsOfTop;
    int start = 0;
    cout << "Стартовая вершина >> "; 
    cin >> start;
    
    bool *visited = new bool[countsOfTop];
    int **matrix = new int *[countsOfTop];
    for (int i = 0; i < countsOfTop; ++i) 
    {
        visited[i] = false;
        matrix[i] = new int[countsOfTop];
    }
    
    cout << "Матрица смежности: " << endl;
    for (int i = 0; i < countsOfTop; ++i) 
    {
        for (int j = 0; j < countsOfTop; ++j)
        {
            input >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    input.close();

    cout << "Порядок обхода: ";
    BFS(visited, start - 1, countsOfTop, matrix);
    
    delete []visited;
    for (int i = 0; i < countsOfTop; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

