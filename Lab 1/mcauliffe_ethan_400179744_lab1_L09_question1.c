#include <stdio.h>

int sumForLoop();
int sumWhileLoop();
int sumDoWhileLoop();

int main() {
    int sum = sumForLoop();
    printf("for loop: %d\n", sum);

    sum = sumWhileLoop();
    printf("while loop: %d\n", sum);

    sum = sumDoWhileLoop();
    printf("do-while loop: %d\n", sum);

    return 0;
}

int sumForLoop() {
    int sum = 0; //declare sum outside loop so it does not reset

    for (int i = 30; i < 1000; i++) { //start at 30 as per question
        if (i%4 == 0) { //check remainder of iterator/4 (if zero it is divisible)
            sum += i;
        }
    }

    return sum;
}

int sumWhileLoop() {
    int sum = 0;
    int i = 30;

    while (i<1000) { //while loop runs until case is not met
        if (i%4 == 0) {
            sum += i;
        }
        i++;
    }

    return sum;
}

int sumDoWhileLoop(){
    int sum = 0;
    int i = 30;

    do { //do while loop will always run at least once
        if (i%4 == 0) {
            sum += i;
        }
        i++;
    } while (i<1000);

    return sum;
}
