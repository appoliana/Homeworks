#include <stdio.h>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
    int n = 0;
    int dop = 0;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
             scanf("%d", &A[i]);
        }
    for (int i = 0; i < n; i++){
        if(A[i] > 0){
        printf("%d ", A[i]);
        dop = A[i];
        for(int j = i+1; j < n; j++){
            if(A[j] > dop && A[j] > 0){
                printf("%d ", A[j]);
                dop = A[j];
                A[j] = -1;
            }}
        }
            printf("\n");
    }
    return 0;
}

