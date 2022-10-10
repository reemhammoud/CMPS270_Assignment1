#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//requires: 2D array and number of Strings
char** concat(char* input[][3], int stringsNumber) {
    char** result = malloc(sizeof(char*) * stringsNumber);
    for (int i = 0; i < stringsNumber; i++) {
        result[i] = malloc(sizeof(char) * 20);
        int pos = 0; int j = 0;
        while (j < 3) {
            strcpy(result[i] + pos, input[i][j]);      
            pos = strlen(result[i]);
            strcpy(result[i] + pos, " ");
            pos++;
            j++;
        }
        result[i][pos - 1] = '\0'; // end the string
    }
    return result;
}
int main()
{
    char* array[][3] = { {"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"} };
    char** result = concat(array, 2);
    printf("{%s,%s}\n", result[0], result[1]);
    free(result[1]); free(result[0]);  //free allocated space
    return 0;
}