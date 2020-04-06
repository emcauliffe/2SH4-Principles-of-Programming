//Ethan McAuliffe
//COMPENG 2SH4 Lab #2
//2019-10-11
//Question 3

#include <stdio.h>
#include <math.h>

#define N 4

void printDiagScan(int mat[][N]);

int main() {
    
    int matrix[][N] = {
        {1,12,13,49},
        {5,16,17,81},
        {9,10,11,20},
        {2,45,19,14},
    };
    
    printDiagScan(matrix);

    return 0;
}

void printDiagScan(int mat[][N]) {
    
    printf("The diagonal scan of your matrix is: ");
    
    int subtractTerm = 1;
    for (int i = 0; i < N*N-1; i++) {//up to N^2-1 because the array is zero indexed but N is mathematical dimension
        if (i < N) { //increasing number of printouts until it reaches the main diagonal
            for (int j = i; j >= 0; j--){
                printf("%d ", mat[j][i-j]);
            }
        } else { //decreasing number of printouts after the main diagonal
            for (int j = 1; j <= i-subtractTerm; j++){
                printf("%d ", mat[N-j][i-(N-j)]);
            }
            subtractTerm += 2;//must increase by 2 each time to account for the increase in i
        }
    }
}