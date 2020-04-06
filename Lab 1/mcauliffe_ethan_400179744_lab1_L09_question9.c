#include <stdio.h>
#include <stdlib.h>

void compress(char infile[], char outfile[]);
void decompress(char infile[], char outfile[]);

int main()
{
    compress("inputfile1.txt", "outputfile.txt");

    decompress("inputfile2.txt", "outputfile2.txt");

    return 0;
}

void compress(char infile[], char outfile[]){

    FILE *input_file = fopen(infile, "r"); //open input file
    FILE *output_file = fopen(outfile, "w"); //open output file

    int totalLength = 0; //initialize length variable as fscanf needs a pointer instead of returning a value

    fscanf(input_file, "%d", &totalLength);

    int zeroes = 0; //initialize the number of 1s and 0s present (as zero because nothing has been done yet)
    int ones = 0;
    int newVal = 2; //setting new val as 2 because this number should never appear in any binary sequence
    int previousVal = 0; //program starts by counting number of zeros in a row, then number of ones

    for (int i = 0; i < totalLength; i++) {
        fscanf(input_file, "%d", &newVal);

        if (newVal == previousVal) {

            if (newVal == 0) { //simply increment the counter of sequential values if the previous digit is the same as the last
                zeroes++;
            } else {
                ones++;
            }

        } else { //if digit is different from the previous...
            if (newVal == 0) {
                printf("%d", ones);// prints number of sequential times zero was iterated over to console (optional)
                fprintf(output_file, "%d ", ones); //stores value in the output file
                previousVal = 0; //recognizes that the number to count occurences of has changed
                zeroes = 1; //set to one because the program has now iterated over one zero
                ones = 0; //set to zero because the program is no longer counting ones
            } else {
                printf("%d", zeroes);
                fprintf(output_file, "%d ", zeroes);
                previousVal = 1; //counting ones now
                ones = 1; //counted one "1" already
                zeroes = 0; //stop counting zeroes
            }
        }

        if (i == totalLength-1) { //edge case catch so that final sequential count is printed
            if (zeroes == 0) {
                printf("%d", ones);
                fprintf(output_file, "%d", ones); //if the program was counting zeroes, print the current count of sequential zeros
            } else {
                printf("%d", zeroes);

                fprintf(output_file, "%d", zeroes); //if it was counting ones, print count of sequential ones
            }
        }
    }

    fclose(input_file); //close both files
    fclose(output_file);
}

void decompress(char infile[], char outfile[]) {
    FILE *input_file = fopen(infile, "r"); //opens both files
    FILE *output_file = fopen(outfile, "w");

    int totalLength = 0;

    fscanf(input_file, "%d", &totalLength);

    int newVal = 0; //initializes program by counting number of zeroes
    int printValue = 0;
    for (int i = 0; i < totalLength; i++) { //iterates over each integer in the file
        fscanf(input_file, "%d", &newVal);

        for (int j = 0; j < newVal; j++) { //prints/writes the number currently selected for the given number of times
            printf("%d ", printValue);
            fprintf(output_file, "%d ", printValue);
        }

        if (printValue == 0) { //switches number being printed each time
            printValue = 1;
        } else {
            printValue = 0;
        }

    }
    fclose(input_file); //closes files
    fclose(output_file);
}