#include <stdio.h>

int main() {
    
    double average = 0; // average stored as a double to increase accuracy
    
    printf("Please enter your average: ");
    scanf("%lf", &average);//scan looks for a double
    
    if (average > 100 || average < 0) { //if else ladder to progressively determine the range the input falls under
        printf("INVALID INPUT");
        //scanf("%f", &average);
    } else if (average >= 90) {
        printf("4");
    } else if (average >= 80) {
        printf("3");
    } else if (average >= 70) {
        printf("2");
    } else if (average >= 60) {
        printf("1");
    } else {
        printf("0");
    }
    
    return 0;
}