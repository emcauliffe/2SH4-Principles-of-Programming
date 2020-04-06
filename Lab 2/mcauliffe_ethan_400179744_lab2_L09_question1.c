//Ethan McAuliffe
//COMPENG 2SH4 Lab #2
//2019-10-11
//Question 1

#include <stdio.h>
#include <math.h>

void print_vector(double array[], int size);
void add_vectors(double vector1[], double vector2[], double vector3[], int n);
double scalar_prod(double vector1[], double vector2[], int size);
double norm2(double vector[], int size);

int main() {
    
    double v1[] = {1, 2, 3, 4, 5};
    double v2[] = {1, 2, 3, 4, 5};
    
    double v3[5];
    
    print_vector(v1, 5);
    print_vector(v2, 5);
    
    printf("Calculating sum vector:\n");
    add_vectors(v1, v2, v3, 5);
    print_vector(v3,5);
    
    printf("Scalar product of vectors: %lf\n", scalar_prod(v1, v2, 5));
    
    printf("Vector L2 norm: l%lf\n", norm2(v1, 5));
    
    // double v1[] = {2, 4, 6};
    // double v2[] = {0, 1, 2};
    
    // double v3[3];
    
    // add_vectors(v1, v2, v3, 3);
    // print_vector(v3, 3);
    
    // printf("%lf", scalar_prod(v1, v2, 3));

    return 0;
}

void print_vector(double array[], int size){
    printf("Your vector is: [");
    for (int i = 0; i < size; i++) {
        if (i == size-1) {
            printf("%lf]", array[i]); //avoids trailing comma and closes square bracket
        } else {
            printf("%lf, ", array[i]);
        }
    }
    printf("\n");
}

void add_vectors(double vector1[], double vector2[], double vector3[], int n){
    for (int i = 0; i < n; i++) {
        vector3[i] = vector1[i] + vector2[i]; //stores sum in vector3
    }
}

double scalar_prod(double vector1[], double vector2[], int size) {
    int result = 0;
    
    for (int i = 0; i < size; i++) {
        result += vector1[i] * vector2[i];
    }
    
    return result;
}

double norm2(double vector[], int size) {
    return sqrt(scalar_prod(vector, vector, size));//scalar_prod vector with itself then square root
}
