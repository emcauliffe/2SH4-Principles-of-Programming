#include <stdio.h>

int main() {
    
    while (1) {
        int inputNumber = 0;
        printf("Please input and integer (0 to end): ");
        scanf("%d", &inputNumber);
        
        if (inputNumber != 0) {
            if (inputNumber >= 10000 && inputNumber <= 99999) {//checks if input is in the ranges where numbers have 5 digits
                printf("Your input is a five-digit number: %d\n", inputNumber);
            } else if (inputNumber <= -10000 && inputNumber >= -99999) {
                printf("Your input is a five-digit number: %d\n", inputNumber);
            }
        } else { //if input is zero, program halts
            printf("Thank you for using my software. Bye!");
            break;
        }
    }
    
    return 0;
}