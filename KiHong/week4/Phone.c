/*
다음 기능을 포함한 전화번호부를 만드시오
1. 전화번호부의 사이즈는 8로 고정합니다.
2. "add"를 입력하면 전화번호를 입력하는 창이 나오는데 "이름", "전화번호", "기타" 정보를 입력할 수 있습니다.
3. "search"를 입력하고 전화번호부의 index를 입력하면 해당 인덱스에 담겨있는 정보가 출력됩니다.
4. "exit"를 입력하면 종료됩니다.
5. 그 외 기능은 편하신대로 추가해주세요.
*/

// gcc ../week2/FnStrcpy.c ../week2/FnMemcpy.c ../week3/FnStrcmp.c Phone.c Phonebook.c -o Phone.out
// gcc -Wall -Wextra -g3 ../week2/FnStrcpy.c ../week2/FnMemcpy.c ../week3/FnStrcmp.c Phone.c Phonebook.c -o Phone.out

#include <string.h>
#include "PhoneBook.h"

#define QUIT "q"

void InputString(char* target, size_t size);
Profile* InputDefaultInformations();

int main(void) {
    Initialize();

    while (1) {
        Enterance:
        printf(DIVIDER_LINE);
        printf("1. Add new profile\n");
        printf("2. Search profile\n");
        printf("3. Delete Profile\n");
        printf("4. Print all profiles\n");
        printf("5. Modify profile\n");
        printf("0. Exit\n");


        int input;
        printf("Enter your action : ");
        scanf("%d", &input);
        // Reset input buffer after scanf
        while (getchar() != '\n');

        switch (input) {
            case 1: {   // Add
                Profile *newLog = InputDefaultInformations();
                if (newLog == NULL) {
                    printf("ADD ");
                    printf(ERROR_INPUT);
                    break;
                }

                switch(AddWithProfile(newLog)) {
                    case 0 :    // Success
                        printf("Add new profile succesfully\n");
                    break;
                    case 1 :    // input fail
                        printf(ERROR_INPUT);
                    break;
                    case 2 :    // duplicant fail
                    {
                        char *replace = malloc(1);
                        printf("Do you wish to override profile? [y/n] : ");
                        InputString(replace, 1);

                        if (replace[0] == 'y')
                            goto Replace;
                    }
                    break;
                    case 3 :    // memory allocation fail
                    break;
                    default :
                        printf("ERROR::Unknown error.\n");
                    break;
                }
            }
            break;
            case 2: {   // Search
                printf("Name (Max 15) : ");

                char name[MAX_NAME_SIZE];
                InputString(name, MAX_NAME_SIZE);

                Profile *search = Search(name);
                if (search == NULL) {
                    printf(ERROR_INPUT);
                }
                else {
                    printf(DIVIDER_LINE_THIN);
                    PrintProfile(search);
                }
            }
            break;
            case 3: {   // Delete
                printf(DIVIDER_LINE);
                printf("Enter New Information (\'quit\' to cancel)\n");

                printf("Name (Max 15) : ");
                char name[MAX_NAME_SIZE];   
                InputString(name, MAX_NAME_SIZE);
                if (fn_strcmp(name, QUIT) == 0) break;

                switch(Delete(name)) {
                    case 0 :    // Success
                        printf("Delete succesfully\n");
                    break;
                    case 1 :    // input fail
                        printf(ERROR_INPUT);
                    break;
                    default :
                        printf("ERROR::Unknown error.\n");
                    break;
                }
            }
            break;
            case 4: {   // Print
                PrintAllProfiles();
            }
            break;
            Replace:
            case 5: {   // Replace
                Profile *newLog = InputDefaultInformations();
                if (newLog == NULL) {
                    printf(ERROR_INPUT);
                    break;
                }

                switch(ReplaceWithProfile(newLog)) {
                    case 0 :    // Success
                        printf("Repace succesfully\n");
                    break;
                    case 1 :    // input fail
                        printf(ERROR_INPUT);
                    break;
                    default :
                        printf("ERROR::Unknown error.\n");
                    break;
                }
            }
            break;
            case 0: {   // Exit
                printf("System Shutdown\n");
            }
            return EXIT_SUCCESS;
            default:
                printf(ERROR_INPUT);
                goto Enterance;
            break;
        }
        
        printf("\nPress Enter key to continue...\n");
        while (getchar() != '\n');
    }

    return EXIT_FAILURE;
}

void InputString(char* target, size_t size) {
    fflush(stdin); // initialize input buffer
    fgets(target, size, stdin);
    
    size_t len = strlen(target);
    if (len > 0 && target[len - 1] == '\n') {
        target[len - 1] = '\0';
    }
}

Profile* InputDefaultInformations() {
    char name[MAX_NAME_SIZE];   
    char etc[MAX_ETC_SIZE];
    unsigned int number;

    printf(DIVIDER_LINE);
    printf("Enter New Information (\'q\' to cancel)\n");

    printf("Name (Max 15) : ");
    InputString(name, MAX_NAME_SIZE);
    if (fn_strcmp(name, QUIT) == 0) return NULL;

    printf("Phone Number : ");
    scanf("%u", &number);
    if (number > 99999999 || number < 10000000) {
        printf(ERROR_INPUT);
        while (getchar() != '\n');
        return NULL;
    }
    // Reset input buffer after scanf
    while (getchar() != '\n');

    printf("ETC (Max 30) : ");
    InputString(etc, MAX_ETC_SIZE);
    if (fn_strcmp(etc, QUIT) == 0) return NULL;

    return CreateNewProfile(name, number, etc);
}