//Ethan McAuliffe
//COMPENG 2SH4 Lab #2
//2019-10-11
//Question 4

#include <stdio.h>
#include <math.h>

void letter_freq(const char word[], int freq[]);
void print_freq(int freq[]);

int main() {
    
    const char input[] = {'h', 'e', 'l', 'L', 'o', 'W', 'o', 'r', 'l', 'd', '\0'};//input string
    int output[26] = {0};
    
    letter_freq(input, output);
    print_freq(output);

    return 0;
}

void letter_freq(const char word[], int freq[]) {
    int i = 0;
    while (word[i]) {//when the null character is reached, loop ends
        freq[(word[i] & 0xDF) - 65]++; //bitwise '&' to normalize all characters to uppercase
        i++;
    }
}

void print_freq(int freq[]) {
    for (int i = 0; i < 26; i++) {
        printf("The count of '%c' and '%c' is: %d\n", i+65, i+97, freq[i]); //add 65 and 97 respectively to change int to upper and lowercase letters
    }
}
