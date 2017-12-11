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
    return(isalpha(ch) || ch == '-' || ch == '+' || ch == '.' || ch == 'E');     
} 

int main(int argc, char** argv) {
    char str[100] = "18.3E-2";
    int i = 0;
    bool pointWas = false;
    bool eWas = false;
    bool signWas = false;
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
                    if (str[i] == '.') {
                        pointWas = true;
                    }
                    if (str[i] == 'E') {
                        eWas = true;
                    }
                    if (str[i] == '+' || str[i] == '-') {
                        signWas = true;
                    }
                    if ((str[i] == 'E' && pointWas == false) || ((str[i] == '+') || str[i] == '-') && eWas == false) {
                        state = Status::fail;
                        continue;
                    }
                    if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0') {
                        state = Status::fail;
                        continue;
                    }
                    i++;
                }
                else {
                    state = Status::fail;
                }
                break;
                
            case Status::readNextSymbol:
                if(!isRight(str[i])) {
                    state = Status::fail;
                }
                i++;
                break;
                
            default:
                break; 
                
            if (state == Status::fail) {
                break;
            }
        }
        if (state == Status::fail) {
            cout << "String is not rigth \n" << endl;
            break;
        }
        else {
            cout << "String is rigth \n" << endl;
        }
    }
    return 0;
}
//digit+ (. digit+)? (E(+ | -)? digit+)?