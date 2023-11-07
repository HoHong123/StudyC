/*
3. (bonus 어려워용) 매개변수로 들어온 c로 문자열을 나눈뒤 2차원 배열에 새로 할당하는 함수인 fn_split을 만들어라
char **fn_split(char const *s, char c);
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sizeFirstDimention = 0;
int sizeSecondDimention = 0;

void PrintOut(char *characters);
char **fn_split(char* string, char delimiter);
char **fn_splitString(char* string, char* delimiter);

int main(void) {
    char *test1 = "Split,thist,stringt,please";
    //char **test2 = fn_split(test1, ',');
    char **test3 = fn_splitString(test1, "t,");
    
    printf("%d : %s\n", -1, test1);

    for (int k = 0; k < sizeFirstDimention + 1; k++) {
        printf("%d : %s\n", k, test3[k]);
    }

    return 0;
}

char **fn_split(char* string, char delimiter) {
    char **result = (char**)malloc(sizeof(char**));
    
    while (*string != '\0' && string != NULL && *string != EOF) {
        char current = *string;
        string++;

        if (current == delimiter) {
            // Return to first element
            sizeFirstDimention++;

            // Reallocate result memory, Expand size
            char **temp = (char**)realloc(result, (sizeFirstDimention + 1) * sizeof(char**));
            if (temp == NULL) {
                printf("ERROR :: DELIMITER Reallocation Fail\n");
                return NULL;
            }

            result = temp;
        }
        else {
            // Create new string, if the string memory is empty
            if (result[sizeFirstDimention] == NULL) {
                result[sizeFirstDimention] = (char*)calloc(0, 1);
            }

            // Concat char, size 1 to remove furder trim
            strncat(result[sizeFirstDimention], &current, 1);
        }
    }
    
    return result;
}
char **fn_splitString(char* string, char* delimiter) {
    int delimiterSize = strlen(delimiter);

    char **result = (char**)malloc(sizeof(char**));
    char *pivot = string;
    char *start = NULL;
    
    while(1) {
        start = strstr(pivot, delimiter);

        // If its the last character
        if (start == NULL && pivot != NULL) {
            result[sizeFirstDimention] = pivot;
            return result;
        }

        // If searching string is empty, return current process
        if (pivot == NULL || *pivot == '\0' || *pivot == '\n') {
            return result;
        }

        // Reallocate result memory, Expand size
        char **temp = (char**)realloc(result, (sizeFirstDimention + 1) * sizeof(char**));
        if (temp == NULL) {
            printf("ERROR :: DELIMITER Reallocation Fail\n");
            return NULL;
        }

        result = temp;

        // Loop if both char pointer is different
        while (pivot != start) {
            // Create new string, if the string memory is empty
            if (result[sizeFirstDimention] == NULL) {
                result[sizeFirstDimention] = (char*)calloc(0, 1);
            }

            // Concat char, size 1 to remove furder trim
            strncat(result[sizeFirstDimention], pivot, 1);
            pivot++;
        }
        
        printf("Result : %s\n", result[sizeFirstDimention]);

        // Remove found delimiter
        for (int k = 0; k < delimiterSize; k++) {
            pivot++;
        }

        // Return to first element
        sizeFirstDimention++;
    }
    
    return result;
}

void PrintOut(char *characters) {
    while (*characters != '\0' && characters != NULL && *characters != EOF) {
        printf("%c", *characters);
        characters++;
    }
    printf("\n");
}