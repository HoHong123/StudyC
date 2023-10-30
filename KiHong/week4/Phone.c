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
// gcc -Wall -Wextra -g3 ../week2/FnStrcpy.c ../week2/FnMemcpy.c ../week3/FnStrcmp.c Phone.c FSConverter.c Phonebook.c -o Phone.out
// gcc -Wall -Wextra -g3 ../week2/FnStrcpy.c ../week2/FnMemcpy.c ../week3/FnStrcmp.c ../week3/FnStrcat.c Phone.c FSConverter.c Phonebook.c -o Phone.out

#include <string.h>
#include "PhoneBook.h"


#define QUIT "q"
#define OUTPUT_ENTER_NAME "Name (Max 15) : "
#define OUTPUT_ENTER_NUMBER "Phone Number : "
#define OUTPUT_ENTER_ETC "ETC (Max 30) : "



// <summary> Clean up scanf iniput buffer
void CleanBuffer() { while(getchar() != '\n'); }

void InputNumeric(char* guidText, unsigned int *number);
char* InputString(char* guidText, char* target, size_t size);
Profile* InputDefaultInformations(char *name, unsigned int *number, char *etc);

int main(void) {
    Initialize();
    
    while (1) {
        printf(DIVIDER_LINE);
        printf("1. Add new profile\n");
        printf("2. Search profile\n");
        printf("3. Delete Profile\n");
        printf("4. Print all profiles\n");
        printf("5. Modify profile\n");
        printf("6. Update profile list\n");
        printf("0. Exit\n");

        // Initialize default data
        char name[MAX_NAME_SIZE] = "\0";
        char etc[MAX_ETC_SIZE] = "\0";
        unsigned int number = 0;

        // input action
        unsigned int input = 0;
        InputNumeric("Enter your action : ", &input);

        switch (input) {
            case 1: {   // Add
                InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);
                if (Search(name)) goto AddDuplicantError; 

                InputNumeric(OUTPUT_ENTER_NUMBER, &number);
                InputString(OUTPUT_ENTER_ETC, etc, MAX_ETC_SIZE);

                Profile *newLog = InputDefaultInformations(name, &number, etc);
                if (newLog == NULL) {
                    printf("1: ");
                    printf(ERROR_INPUT);
                    break;
                }

                switch(AddWithProfile(newLog)) {
                    case 0 :    // Success
                        printf("Add new profile succesfully\n");
                    break;
                    case 1 :    // input fail
                        printf("2: ");
                        printf(ERROR_INPUT);
                    break;
                    case 2 :    // duplicant fail
                    AddDuplicantError:
                    {
                        char *replace = malloc(2);
                        InputString("Do you wish to override profile? [y/n] : ", replace, 2);

                        if (fn_strcmp(replace, "y") == 0) {
                            free(replace);
                            printf(DIVIDER_LINE_THIN);
                            goto Replace;
                        }

                        free(replace);
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
                InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);

                Profile *search = Search(name);
                if (search == NULL) {
                    printf(ERROR_PROFILE_MISSING);
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

                InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);
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
            case 5: {   // Replace
            Replace:
                if (name == NULL || name[0] == '\0') {
                    InputString("Target Profile Name (Max 15) : ", name, MAX_NAME_SIZE);
                }

                if (Search(name) == NULL) goto ReplaceProfileMissing;

                number = 0;
                fn_strcpy(etc, "\0");

                Profile *newLog = InputDefaultInformations(name, &number, etc);
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
                    case 2 :    // input fail
                    ReplaceProfileMissing:
                        printf(ERROR_PROFILE_MISSING);
                    break;
                    default :
                        printf("ERROR::Unknown error.\n");
                    break;
                }
            }
            break;
            case 6: {
                SaveProfileData();
            }
            break;
            case 0: {   // Exit
                SaveProfileData();
                printf("System Shutdown\n");
            }
            return EXIT_SUCCESS;
            default:
                printf(ERROR_INPUT);
            break;
        }
        
        printf("\nPress Enter key to continue...\n");
        CleanBuffer();
    }

    return EXIT_FAILURE;
}

char* InputString(char* guidText, char* target, size_t size) {
    printf("%s", guidText);

    // Clean up fgets buffer
    fflush(stdin); 

    // Input string
    fgets(target, size, stdin);
    
    size_t len = strlen(target);
    if (len > 0 && target[len - 1] == '\n') {
        target[len - 1] = '\0';
    }

    return target;
}

void InputNumeric(char* guidText, unsigned int *number) {
    printf("%s", guidText);

    // Number input region
    scanf("%8u", number);
    // Clean up scanf buffer
    CleanBuffer();
}

Profile* InputDefaultInformations(char *name, unsigned int *number, char *etc) {
    printf(DIVIDER_LINE);
    printf("Enter New Information (\'q\' to cancel)\n");

    // Name input region
    if (name == NULL || name[0] == '\0') {
        InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);
    } else {
        printf(OUTPUT_ENTER_NAME);
        printf("%s\n", name);
    }
    if (fn_strcmp(name, QUIT) == 0) return NULL;

    // Number input region
    if (*number > 99999999 || *number < 10000000) {
        InputNumeric(OUTPUT_ENTER_NUMBER, number);
    } else {
        printf(OUTPUT_ENTER_NUMBER);
        printf("%d\n", *number);
    }
    
    // Etc input region
    if (etc == NULL || etc[0] == '\0') {
        InputString(OUTPUT_ENTER_ETC, etc, MAX_ETC_SIZE);
    }  else {
        printf(OUTPUT_ENTER_ETC);
        printf("%s\n", etc);
    }
    if (fn_strcmp(etc, QUIT) == 0) return NULL;

    return CreateNewProfile(name, *number, etc);
}
