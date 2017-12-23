#include <iostream>
#include <cstdlib>

using namespace std;

int definer(char symbol) 
{
    if (isalpha(symbol)) 
    {
        return 0;
    }
    else 
    {
        if (isdigit(symbol) || symbol == '_') 
        {
            return 1;
        }
        else 
        {
            return 2;
        }
    }
}

int main(int argc, char** argv) 
{
    int matrix[3][3] = {{1, -1, -1}, 
                        {2,  2, -1}, 
                        {3,  2, -1}}; // 2 - неопознанный символ 
    
    string str = "abc1_23";
    int state = 0;
    int i = 0;
    while (true) 
    {
        if (matrix[state][definer(str[i])] == -1) 
        {
            break;
        }
        else 
        {
            if (matrix[state][definer(str[i])] == 1)
            {
                i++;
                state = 1;
            }
            else 
            {
                i++;
                state = 2; 
            }
        }
    }
    if (state != 2) 
    {
        cout << "String is rigth \n" << endl;
    }
    else 
    {
        cout << "String is not rigth \n" << endl;
    }
    return 0;
}
