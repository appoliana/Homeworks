/* 
 * File:   main.cpp
 * Author: polinapicchio
 *
 * Created on 11 сентября 2017 г., 19:08
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
    int A[n];
    int count = 0;
    for(int i = 0; i < n; i++){
        A[i] = rand() % 10;
        printf("%d", A[i]);
        if (A[i] == 0){
        count ++;
        }
    }
    printf("\n");
    printf("count = %d", count);
    return 0;
}