#include <stdio.h>

int main() {
    
    int sum = 0;
    
    int max = 400;

    for (int i = 1; i <= max; i++) {
        for (int j = 1; j <= max; j++) {
            for (int k = 1; k <= max; k++){
                if ( i*i + j*j == k*k && i<=j) {
					//brute force nested for loop checks all combinations where whole numbers equal another whole number
                    printf("side1:%d  side2:%d  side3:%d  \n", i, j, k);
                    sum++;
                }
            }
        }
    }
    
    printf("Total of %d Pythagorean Triples",sum);
    
    return 0;
}