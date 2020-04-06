#include <stdio.h>

double approximatePi(int n); //function prototype

int main() {
    
    int n = 0;
    
    do {
        printf("Please enter a positive integer: ");
        scanf("%d", &n);
    } while (n <= 0);
    
    double piApproximation = approximatePi(n); //value returned from function stored as a variable

    printf("Pi approximation = %lf", piApproximation); //print value returned to the command line
    
    return 0;
}

double approximatePi(int n) {
    
    double sum = 0;
    
    for (int i = 0; i < n; i++){
        if (i%2) { //even iterations will subtract and odd iterations will add
            sum -= 4.00/(i*2+1); 
        } else {
            sum += 4.00/(i*2+1);
        }
    }
    
    return sum;
}