#include <stdio.h>

int main() {

    int m = 0;
    
    do {
        printf("Please enter a positive integer: ");
        scanf("%d", &m);
    } while ( m <= 0);//user is asked for input until that input is correct
    
    for (int i = 1; i <= m; i++) {
        
        int sum = 0;
        
        for (int j = 1; j < i; j++) {
            if (i%j == 0) {
				//if the nested for loop iterators are evenly divisible (if the inner iterator is a factor of the outer), 
				//increase the sum of factors by that number
                sum += j; 
            } 
        }
        
        if (sum == i) {
            printf("%d\n", i); //print any numbers where the sum of factors is the same as the number
        }
           
    }
    
    return 0;
}