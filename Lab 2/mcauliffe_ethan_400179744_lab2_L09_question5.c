//Ethan McAuliffe
//COMPENG 2SH4 Lab #2
//2019-10-11
//Question 5

#include <stdio.h>
#include <math.h>

#define N 13

void string_copy(const char source[], char destination[], int n);

int main() {
    
    const char input[] = "Hello World!";
    char output[N] = {0};
    
    string_copy(input, output, N);
    
    printf("The string in your destination array is: ");
    for (int i=0; i < N; i++) {
        printf("%c", output[i]);//progressively prints each character in the string
    }

    return 0;
}

void string_copy(const char source[], char destination[], int n) {
    for (int i = 0; i < n-1; i++) {
        
        if (!source[i]) {
            destination[i] = '\0';
            break;
        }
        
        destination[i] = source[i];//adds source character to respective index of destination until only one bit in memory is left
    }
    destination[n-1] = '\0';//uses final memory bit for null character which is needed to consider the output a string
}