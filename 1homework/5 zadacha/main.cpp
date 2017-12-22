/* 
 * File:   main.cpp
 * Author: polinapicchio
 *
 * Created on 10 сентября 2017 г., 15:54
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    char s[n];
    for (int i = 0; i < n; i++) {
        scanf("%c", &s[i]);
    }
    bool balance = true;
    int count = 0;
    for (int i = 0; s[i]!= '\0'; ++i) {
        if (count >= 0) {
            if (s[i] == '(') {
                count++;
            }
            if (s[i] == ')') {
                count--;
            }
        }
        else { 
        balance = false;
        break;
        }
    }
    if (balance == true) {
        printf("Баланс соблюден");
    }
    else { 
        printf("Баланс не соблюден");
    }
    return 0;
}