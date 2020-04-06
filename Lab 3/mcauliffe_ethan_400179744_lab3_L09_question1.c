//Question 1
//Ethan McAuliffe
//Lab 3 - 2019-10-28
//Working

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

char *my_strcat( const char * const str1, const char * const str2);

int main() {
    char* input1 = NULL;
    char* input2 = NULL;

    printf("Please input your first string: ");
    char input = '\0';
    int i = 0;
    input1 = malloc(sizeof(char));

    while ((input = getchar()) != '\n') {//dynamically assign memory for input strings for infinite string input length
        input1 = realloc(input1, sizeof(char)*(i+1));
        *(input1+i) = input;
        i++;
    }
    *(input1+i) = 0;

    printf("Please input your second string: ");
    input = '\0';
    i = 0;
    input2 = malloc(sizeof(char));

    while ((input = getchar()) != '\n') {
        input2 = realloc(input2, sizeof(char)*(i+1));
        *(input2+i) = input;
        i++;
    }
    *(input2+i) = 0;

    char *stringPointer = my_strcat(input1, input2);

    printf("\nYour combined string is: %s", stringPointer);

    free(input1);
    free(input2);
    free(stringPointer);

    return 0;
}

char* my_strcat( const char * const str1, const char * const str2) {

    char *stringPointer = NULL;
    stringPointer = malloc((sizeof(*str1)+sizeof(*str2))*sizeof(char));

    int i = 0;
    while (str1[i]) {
        *(stringPointer + i) = str1[i];
        i++;
    }

    int j = 0;
    while (str2[j]) {
        *(stringPointer + i + j) = str2[j];
        j++;
    }

    *(stringPointer + i + j) = 0;//append with null character

    return stringPointer;
}
