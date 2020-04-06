#include <stdio.h>

int main() {

    int input = 0;

    do {
    printf("Input a positive integer: ");
    scanf("%d", &input);
    } while (input <=0); //ask user repeatedly for input until valid data is received
    
    int flag = 0; //flag to deal with leading zeroes
    
    while (input) { //input is modified each iteration of the for loop until input is reduced to zero
        
        if (input%10 != 0 || flag) { //avoid printing zeroes until a non-zero number is iterated over
            flag = 1;//after first non-zero number, set flag
            printf("%d",input%10);
        }
        
        input /= 10;//drop digit each time so that each digit is only printed once
    }
    
    return 0;
}