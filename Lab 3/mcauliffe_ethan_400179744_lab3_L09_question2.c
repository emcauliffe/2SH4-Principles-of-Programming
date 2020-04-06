//Question 2
//Ethan McAuliffe
//Lab 3 - 2019-10-28
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idNumber;
    char firstName[15];
    char lastName[15];
    int projOneGrade;
    int projTwoGrade;
    float finalGrade;
} student;

student **create_class_list( char *filename, int *sizePtr );
int find( int idNo, student **list, int size );
void input_grades( char *filename, student **list, int size );
void compute_final_course_grades(student **list, int size);
void output_final_course_grades(char *filename, student **list, int size);
void print_list( student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);

int main() {

    int n;//number of students
    char studentsFile[] = "student_list.txt";
    char gradesFile[] = "grade_list.txt";
    char exportFile[] = "grade_report.txt";

    student** classList = create_class_list(studentsFile, &n);

    printf("Initial\n");
    print_list(classList, n);
    printf("-- -- --\n");
    printf("Grades inputted\n");
    input_grades(gradesFile, classList, n);
    print_list(classList, n);
    printf("-- -- --\n");
    printf("Final grades calculated and stored in %s\n", exportFile);
    compute_final_course_grades(classList, n);
    output_final_course_grades(exportFile, classList, n);
    print_list(classList, n);
    printf("-- -- --\n");
    printf("Withdraw student 90000 (does not exist)\n");
    withdraw(90000, classList, &n);
    print_list(classList, n);
    printf("-- -- --\n");
    printf("Withdraw student 4580\n");
    withdraw(4580, classList, &n);
    print_list(classList, n);
    printf("-- -- --\n");
    printf("Withdraw student 1200\n");
    withdraw(1200, classList, &n);
    print_list(classList, n);
    printf("-- -- --\n");
    printf("Destroy list\n");
    destroy_list(classList, &n);
    print_list(classList, n);
    printf("-- -- --\n");

    return 0;
}

student **create_class_list( char *filename, int *sizePtr ){
    FILE *input_file = fopen(filename, "r");//open file

    fscanf(input_file, "%d", sizePtr);//read integer dictating number of students

    student** classPtr = calloc(*sizePtr, sizeof(student));//calloc to initialize to zero
    for (int i = 0; i < *sizePtr; i++){
        classPtr[i] = malloc(sizeof(student));
        fscanf(input_file, "%d%s%s", &(classPtr[i]->idNumber), classPtr[i]->firstName, classPtr[i]->lastName);
    }

    //bubble sort in case the input file is not in increasing order of ID numbers
    /*
    for (int i = 0; i < *sizePtr-1; i++) { //bubble sort algorithm to order array so smallest number is first
        for (int j = 0; j < *sizePtr-1-i; j++){
            if (classPtr[j]->idNumber > classPtr[j+1]->idNumber) { // if one element is less than the next then swap the places
                student* temp = classPtr[j];
                classPtr [j] = classPtr[j+1];
                classPtr[j+1] = temp;
            }
        }
    }
    */

    fclose(input_file);//always close the files
    return classPtr;
}

int find( int idNo, student **list, int size ){
    int start = 0;

    if (idNo > list[size-1]->idNumber) { //immediate abort if the number isn't within the bounds
        return -1;
    }

    while(start <= size) { //binary search to determine location of student most efficiently
        int loc = start + (size-start)/2;

        if (list[loc]->idNumber == idNo) {
            return loc;
        }

        if (list[loc]->idNumber < idNo) {//discard values less than desired
            start = loc + 1;
        } else {
            size = loc - 1;
        }
    }
    return -1;
}

void input_grades( char *filename, student **list, int size ){
    FILE *input_file = fopen(filename, "r");

    for (int i = 0; i < size; i++){
        int studentId;
        int gradeOne;
        int gradeTwo;

        fscanf(input_file, "%d%d%d", &studentId, &gradeOne, &gradeTwo);

        int pos = find(studentId, list, size);

        if (pos == -1) {//program halts if you attempt to input a grade for a non-existent student
            printf("ERROR: Student not found. Program aborted.");
            exit(-1);
        }

        list[pos] -> projOneGrade = gradeOne;
        list[pos] -> projTwoGrade = gradeTwo;
    }

    fclose(input_file);
}

void compute_final_course_grades(student **list, int size){
    for (int i = 0; i < size; i++) {
        list[i] -> finalGrade = (float)(list[i] -> projOneGrade + list[i] -> projTwoGrade)/2; //cast to float to get decimal accuracy
    }
}

void output_final_course_grades(char *filename, student **list, int size) {

    compute_final_course_grades(list, size); //optional if the function has already been called

    FILE *output_file = fopen(filename, "w");

    fprintf(output_file, "%d", size);

    for (int i = 0; i<size; i++) {
        fprintf(output_file, "\n%d %f", list[i] -> idNumber, list[i] -> finalGrade);
    }

    fclose(output_file);
}

void print_list( student **list, int size){

    // compute_final_course_grades(list, size); //optional if the function has already been called

    for (int i = 0; i < size; i++){
        printf("ID: %d, name: %s %s, project 1 grade: %d, project 2 grade: %d, finalGrade: %f\n", list[i]->idNumber, list[i]->firstName,
            list[i]->lastName, list[i]->projOneGrade, list[i]->projTwoGrade, list[i]->finalGrade);
    }
}

void withdraw(int idNo, student **list, int *sizePtr){
    int pos = find(idNo, list, *sizePtr);

    if (pos == -1) {
        printf("ERROR: Student not in list. Withdrawl unsuccessful.\n");
    } else {
        for (int i = pos; i < *sizePtr; i++) {
            list[i] = list[i+1];
        }
        *sizePtr -= 1;
        list = realloc(list, *sizePtr);
    }
}

void destroy_list(student **list, int *sizePtr){

    for (int i = 0; i < *sizePtr; i++) { //frees individual student structs first...
        free(list[i]);
    }

    free(list);//...then the whole array of structs
    *sizePtr = 0;
}