#include <iostream>
#include <cstdlib>

using namespace std;

enum class Status 
{
    start,
    readNextSymbolStart,
    readNextSymbolPoint,
    readNextSymbolE,
    pointWas,
    eWas,
    signWas,
    fail
};

bool isRight(char ch) 
{
    return (isdigit(ch) || ch == '-' || ch == '+' || ch == '.' || ch == 'E');     
} 

int main(int argc, char** argv) {
    char str[100];
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
            {
                if (isdigit(str[i])) {
                    state = Status::readNextSymbolStart;
                    i++;
                }
                else {
                    state = Status::fail;
                }
                break; 
            }
                
            case Status::pointWas:
            {
                if (isdigit(str[i])) 
                {
                    state = Status::readNextSymbolPoint;
                    i++;
                }
                else 
                {
                    state = Status::fail;
                    i++;
                }
                break;
            }
            
            case Status::eWas:
            {
                if (str[i] == '+' || str[i] == '-') 
                {
                    state = Status::readNextSymbolE;
                    i++;
                }
                else 
                {
                    state = Status::fail;
                    i++;
                }    
                break;
            }
            
            case Status::signWas:
            {
                if (isdigit(str[i])) 
                {
                    state = Status::readNextSymbolE;
                    i++;
                }
                else 
                {
                    state = Status::fail;
                    i++;
                }    
                break;
            }
            
            case Status::readNextSymbolStart:
            {
                if (isRight(str[i])) 
                {
                    if (str[i] == '.')
                    {
                        state = Status::pointWas;
                        i++;
                    }
                    if (str[i] == 'E')
                    {
                        state = Status::eWas;
                        i++;
                    }
                    if (str[i] == '+' || str[i] == '-')
                    {
                        state = Status::signWas;
                        i++;
                    }
                    if (isdigit(str[i]))
                    {
                        state = Status::readNextSymbolStart;
                        i++;
                    }
                }
                break;
            }
            
            case Status::readNextSymbolPoint:
            {
                if (isRight(str[i])) 
                {
                    if (str[i] == '.')
                    {
                        state = Status::fail;
                        i++;
                    }
                    if (str[i] == 'E')
                    {
                        state = Status::eWas;
                        i++;
                    }
                    if (str[i] == '+' || str[i] == '-')
                    {
                        state = Status::signWas;
                        i++;
                    }
                    if (isdigit(str[i]))
                    {
                        state = Status::readNextSymbolPoint;
                        i++;
                    }
                }
                else {
                    state = Status::fail;
                }
                break;
            }
            
            case Status::readNextSymbolE:
            {
                if (isdigit(str[i]))
                {
                    state = Status::readNextSymbolE;
                    i++;
                }
                else {
                    state = Status::fail;
                }
                break;
            }
            
            case Status::fail:
            {
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
    
    if (state == Status::readNextSymbolStart || state == Status::readNextSymbolE || state == Status::readNextSymbolPoint) 
    {
        cout << "String is right" << endl;
    }
    else 
    {
        cout << "String is not right" << endl;
    }  
    
    return 0;
}
//digit+ (. digit+)? (E(+ | -)? digit+)?