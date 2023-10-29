#include <stdio.h>

char *fn_strcpy(char *target, const char *original);

int main(void) {
    char original[] = "Copy this!";
    char target[20];
    char *target2 = fn_strcpy(target, original);
    
    printf("%s1\n", original);
    printf("%s2\n", target2);
    printf("%s3\n", target);
    
    return 0;
}

// <summary> string copy function
// <parameter=target> destination to have copied values
// <parameter=original> original char array values
// <return> Modified char array
char *fn_strcpy(char *target, const char *original) {
    char *returnValue = target;
    
    int k = 0;
    // Loop untill printout \0 = 0x00 = 0 = false
    while (*original) {
        *returnValue = *original;
        returnValue++;
        original++;
        k++;
    }
    
    // Add end line char
    *returnValue = '\0';
    // Set returnValues pointer to start of the char array
    returnValue -= k;
    
    return returnValue;
}