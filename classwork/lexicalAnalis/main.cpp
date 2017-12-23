#include <iostream>
#include <cstdlib>

using namespace std;


enum class Status {
    start,
    readLetter,
    readNextSymbol,
    fail
};

bool isRight(char ch) {
    return(isdigit(ch) || isalpha(ch) || ch == '_');     
}

// разбор детерминированного конечныого автомата
int main(int argc, char** argv) {
    char str[3] = "as";
    int i = 0;
    Status state = Status::start;
    while (str[i] != '\0') {
        switch (state)
        {
            case Status::start:
                if (isalpha(str[i])) {
                    state = Status::readLetter;
                    i++;
                }
                else {
                    state = Status::fail;
                }
                break; 
            case Status::readLetter:
                if (isRight(str[i])) {
                    state = Status::readNextSymbol;
                }
                else {
                    state = Status::fail;
                }
                i++;
                break;
            case Status::readNextSymbol:
                if(!isRight(str[i])) {
                    state = Status::fail;
                }
                i++;
                break;
            default:
                break;
        }
        if (state == Status::fail) {
             break;
        }
    }
    if (state != Status::readNextSymbol) {
        cout << "String is not rigth \n" << endl;
    }
    else {
        cout << "String is rigth \n" << endl;
    }
    
    return 0;
}
 /*

int definer(char symbol) {
    if (isalpha(symbol)) {
        return 0;
    }
    else {
        if (isdigit(symbol) || symbol == '_') {
            return 1;
        }
        else {
            return 2;
        }
    }
}

int main(int argc, char** argv) 
{
    int matrix[3][3] = {{1, -1, -1}, 
                        {2,  2, -1}, 
                        {3,  2, -1}};
    
    string str = "abc1_23";
    int state = 0;
    int i = 0;
    while (true) {
        if (matrix[state][definer(str[i])] == -1) {
            break;
        }
        else {
            if (matrix[state][definer(str[i])] == 1){
                i++;
                state = 1;
            }
            else {
                i++;
                state = 2; 
            }
        }
    }
    if (state != 2) {
        cout << "String is rigth \n" << endl;
    }
    else {
        cout << "String is not rigth \n" << endl;
    }
    
    return 0;
}
   */
