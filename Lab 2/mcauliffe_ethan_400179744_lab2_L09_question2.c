//Ethan McAuliffe
//COMPENG 2SH4 Lab #2
//2019-10-11
//Question 2

#include <stdio.h>
#include <math.h>

#define N 3

int is_diag_dom(int mat[][N]);

int main() {
    
    int diagDomMatrix[][N] = {
        {4,2,1},
        {2,6,3},
        {5,-3,10},
    };
    
    int nonDiagDomMatrix[][N] = {
        {0,3,-29},
        {1,2,3},
        {4,5,6},
    };
    
    int edgeCase[][N] = {
        {3,-2,-1},
        {2,3,1},
        {1,2,-3},
    };
    
    printf("Diagonal Dominant: %d\n", is_diag_dom(diagDomMatrix));
    printf("Non-Diagonal Dominant: %d\n", is_diag_dom(nonDiagDomMatrix));
    printf("Non-Diagonal Dominant (with edge cases): %d", is_diag_dom(edgeCase));
   

    return 0;
}

int is_diag_dom(int mat[][N]) {
    
    int flag = 1;//matrix is diag_dom until proven otherwise
    
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += fabs(mat[i][j]); //adds absolute value of all elements in a row together
        }
        rowSum -= fabs(mat[i][i]); //subtracts diagonal element
        if (rowSum >= fabs(mat[i][i])) { //if all elements except diagonal are same or larger, end loop and return 0
            flag = 0;
            break;
        }
    }
    
    return flag;
}