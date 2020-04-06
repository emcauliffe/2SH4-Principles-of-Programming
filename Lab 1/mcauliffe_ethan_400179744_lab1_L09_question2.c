#include <stdio.h>

int findSmallestNumber(int inputNumbers[], int size);

int main() {
    
    int n = 0;
    
    printf("Please input a positive number: ");
    scanf("%d", &n); //looks for an integer
    
    while (n <= 0) {
        printf("Invalid input. Enter a positive number: "); //if the integer is not positive it keeps requesting a valid input
        scanf("%d", &n);
    }
    
    int input[n];
    
    for (int i = 0; i < n; i++) {
        printf("Please enter number %d: ", i+1); //repeats input prompt for desired iterations as defined by n
        scanf("%d", &input[i]);
    }
    
    int smallestNumber = findSmallestNumber(input, n);
    
    printf("The smallest number was: %d", smallestNumber);
    
    return 0;
}

int findSmallestNumber(int inputNumbers[], int size) { //bubble sort algorithm to find the smallest number in a given array

    for (int i = 0; i < size-1; i++) { //bubble sort algorithm to order array so smallest number is first
        for (int j = 0; j < size-1-i; j++){
            if (inputNumbers[j] > inputNumbers[j+1]) { // if one element is less than the next then swap the places
                int temp = inputNumbers[j];
                inputNumbers [j] = inputNumbers[j+1];
                inputNumbers[j+1] = temp;
            }
        }
    }
    
    return inputNumbers[0]; //first element will be smallest
}