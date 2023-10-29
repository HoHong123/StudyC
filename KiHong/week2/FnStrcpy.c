#include "FnStrcpy.h"

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
        original++;
        returnValue++;
        k++;
    }
    
    // Set returnValues pointer to start of the char array
    *returnValue = '\0';
    returnValue -= k;
    
    return returnValue;
}

// int main(void) {
//     char original[] = "Copy this!";
//     char target[20];
//     char *target2 = fn_strcpy(target, original);
    
//     printf("%so\n", original);
//     printf("%s1\n", target);
//     printf("%s2\n", target2);

//     target2[1] = 'O';
    
//     printf("\n");

//     printf("%so\n", original);
//     printf("%s1\n", target);
//     printf("%s2\n", target2);

//     printf("\n");

//     printf("%po\n", original);
//     printf("%p1\n", target);
//     printf("%p2\n", target2);

//     return 0;
// }
