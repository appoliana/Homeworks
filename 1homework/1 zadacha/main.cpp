/* 
 * File:   main.cpp
 * Author: polinapicchio
 *
 * Created on 9 сентября 2017 г., 12:15
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int x = 0;
    int dop = 0;
    scanf ("%d", &x);
    dop = x*x;
    x = x*(dop + x) + dop + x + 1;
    printf("x^4 + x^3 + x^2 + x + 1 = %d", x);
    return 0;
}

