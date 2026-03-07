#include <stdio.h>
#include <string.h>

// symbolic constants
#define SUCCESS 0
#define FAILURE 1

int main() 
{
    for (int i = 0; i < 5; i++) {
        printf("Hello, World\n");
    }

    createFile("alexFile.txt");
    int myInt = 1;
    createFileInt(&myInt);
    copyFile("alexFile.txt", "alexFileCopy.txt");

    printf("FILE1: \n");
    showFile("alexFile.txt");
    printf("FILE2: \n");
    showFile("alexFileCopy.txt");

    // Add these to test the new functions
    printf("Number of digits in FILE1: %d\n", countDigitInFile("alexFile.txt"));
    printf("Total characters in FILE1: %d\n", countCharactersInFile("alexFile.txt"));

    return 0;
}