#include <stdio.h>
#include <string.h>

// symbolic constants
#define SUCCESS 0
#define FAILURE 1

int countDigitInFile(char* fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL) return -1; // Return -1 to indicate failure (better than 0, which could be a valid count)

    int digitCount = 0;
    char c;

    // Read character by character until EOF
    while ((c = fgetc(pFile)) != EOF) {
        if (c >= '0' && c <= '9') { // Check if character is a digit
            digitCount++;
        }
    }

    fclose(pFile);
    return digitCount;
}

int countCharactersInFile(char* fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL) return -1; // Return -1 to indicate failure

    int charCount = 0;
    char c;

    // Read character by character until EOF
    while ((c = fgetc(pFile)) != EOF) {
        charCount++;
    }

    fclose(pFile);
    return charCount;
}
