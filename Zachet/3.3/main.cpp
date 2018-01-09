#include <iostream>
#include <cstdlib>

using namespace std;

enum class Status {
    start,
    readNextSymbol,
    fail
};

bool isRight(char ch) {
    return(isalpha(ch) || isdigit(ch) || ch == '_' );     
} 

int main(int argc, char** argv) 
{
    char str[1000];
    cout << "Enter the string you want to check: " << endl;
    cin >> str;
    cout << endl;
    int i = 0;
    Status state = Status::start;
    while (str[i] != '\0') 
    {
        switch (state)
        {
            case Status::start:
                if (isalpha(str[i])) 
                {
                    state = Status::readNextSymbol;
                    i++;
                }
                else 
                {
                    state = Status::fail;
                }
                break; 
                
            case Status::readNextSymbol:
            {
                if (!isRight(str[i])) 
                {
                    state = Status::fail;
                    break;
                }
                else 
                {
                    state = Status::readNextSymbol;
                    i++;
                }
                break;
            }
            
            default:
            {
                state = Status::fail;
                break; 
            }
        }
        if (state == Status::fail) 
        {
            break;
        }
    }
    
    if (state != Status::readNextSymbol)
    {
        cout << "String is not rigth \n" << endl;
    }
    else 
    {
        cout << "String is rigth \n" << endl;
    }  
    
    return 0;
}