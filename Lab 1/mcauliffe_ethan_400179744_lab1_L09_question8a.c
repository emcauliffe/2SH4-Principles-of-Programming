#include <stdio.h>

int power(int base, int exponent);

int main() {

    int input = 0;

    do {
    printf("Input a positive, 7 digit integer: ");
    scanf("%d", &input);
    } while (input <=0); //user repeatedly asked for unput until it is valid
    
    int flag = 0; //flag determines if zeros should be ignored or printed (to avoid leading zeros or missing zeroes in the number itself)
    
    for (int i=0; i < 7; i++) {
        if ((input / power(10, i))%10 != 0 || flag) {
            flag = 1; //after the first non-zero number, leading zeros do not need to be caught anymore
            printf("%d",(input / power(10, i))%10); //print the leftover digit after dividing by powers of 10 (to get individual digits)
        }
    }
    
    return 0;
}

int power(int base, int exponent) { //power function works for positive exponents
    int product = 1; //product initialized at 1 to avoid multiplication by zero
    for (int i=1; i <= exponent; i++) {
        product *= base;
    }
    return product;
}