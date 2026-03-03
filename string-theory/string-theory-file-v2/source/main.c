#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

int countOnlyCharactersInFile(char* fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return FAILURE;
    }

    int allCharacterCount = 0;
    int c;

    // Read file character by character
    while ((c = fgetc(pFile)) != EOF) {
        if (isalpha(c)) { // Check if character is alphabetic
            allCharacterCount++;
        }
    }

    fclose(pFile); // Close the file
    return allCharacterCount;
}

int main()
{
    int count = countOnlyCharactersInFile("alexFile.txt");
    if (count != FAILURE) {
        printf("FILE1 Total Number of Only Characters: %d\n", count);
    }

    return SUCCESS;
}