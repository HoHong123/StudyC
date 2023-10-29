#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *fn_strcapitalize(char *str);

int main(void) {
    char *letters = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    char *getter = fn_strcapitalize(letters);

    printf("%s\n", getter);

    return 0;
}

// <summary> Set first char of the word to uppercase and rest to lowercase
// <parameter=*str> Target string
// <return> Modified string
char *fn_strcapitalize(char *str) {
    char *returnValue = (char*)malloc(strlen(str));

    int k = 0;
    while (*str) {
        char currentChar = *str;
        char previousChar;
        
        if (isalpha(*str)) {
            previousChar = *(str - 1);
            
            // If the alphabet a lowcase and has a space infront of the char
            if (islower(currentChar) && !isalnum(previousChar)) {
                currentChar = toupper(currentChar);
            }
            // If the alphabet is uppercase and doesn't have a space infront of the char
            else if (isupper(currentChar) && isalpha(previousChar)) {
                currentChar = tolower(currentChar);
            }
        }

        *returnValue = currentChar;

        returnValue++;
        str++;
        k++;
    }
    
    *returnValue = '\0';
    returnValue -= k;

    return returnValue;
}