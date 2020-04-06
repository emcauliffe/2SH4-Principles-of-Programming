//Ethan McAuliffe
//COMPENG 2SH4 Lab #2
//2019-10-11
//Question 6

#include <stdio.h>
#include <math.h>

void efficient(const int source[], int val[], int pos[], int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);
void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2);

int main() {
    
    int v1[] = {0, 0, 23, 0, -7, 0, 0, 48};
    
    int v1Val[3] = {0};
    int v1Pos[3] = {0};
    
    efficient(v1, v1Val, v1Pos, 8);
    
    printf("The compacted form of your vector is as follows:\n");
    printf("Val vector: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", v1Val[i]);
    }
    printf("\n");
    
    printf("Pos vector: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", v1Pos[i]);
    }
    printf("\n");
    
    printf("The expanded form of your vector is as follows:\n");
    int v2[8] = {0};
    reconstruct(v2, 8, v1Val, v1Pos, 3);
    for (int i = 0; i < 8; i++) {
        printf("%d ", v2[i]);
    }

    return 0;
}

void efficient(const int source[], int val[], int pos[], int size) {
    int nonZero = 0; //counts occurences of non-zero values so that they can be stored in the correct index of the val/pos arrays
    for (int i = 0; i < size; i++) {
        if (source[i]) { //trips when value is not a zero
            val[nonZero] = source[i];
            pos[nonZero] = i;
            nonZero++; //increases index so that value is not overwritten with the next non-zero value 
        }
    }
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n) {
    int nonZero = 0;
    for (int i = 0; i < m; i++) { //output will have length of m
        if (pos[nonZero] == i) {
            source[i] = val[nonZero];
            nonZero++;
        } else {
            source[i] = 0;//useful if the reconstructed vector array is not initialized to all zeros
        }
    }
}