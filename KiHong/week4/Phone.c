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

// Eof, exit에 구조체 할당 free

// <summary> Clean up scanf iniput buffer
void CleanBuffer() { while(getchar() != '\n'); }
void PrintMenu() {
        printf(DIVIDER_LINE);
        printf("1. Add new profile\n");     // Add
        printf("2. Search profile\n");      // Search
        printf("3. Delete Profile\n");      // Delete
        printf("4. Print all profiles\n");  // Print
        printf("5. Modify profile\n");      // Change
        printf("6. Update profile list\n"); // Save
        printf("0. Exit\n");                // Exit
}

void Execute();
void InputNumeric(char* guidText, unsigned int *number);
char* InputString(char* guidText, char* target, size_t size);
Profile* InputDefaultInformations(char *name, unsigned int *number, char *etc);

int main(void) {
    Initialize();

    unsigned int input = 999999;
    
    while (1) {
        PrintMenu();

        // Initialize default data
        char name[MAX_NAME_SIZE] = "\0";
        char etc[MAX_ETC_SIZE] = "\0";
        unsigned int number = 0;

        // input action
        if (input == 999999) {
            InputNumeric("Enter your action : ", &input);
        } 

        switch (input) {
            case 1: {   // Add
                // Create new profile
                Profile *newLog = InputDefaultInformations(name, &number, etc);
                if (newLog == NULL) {
                    if (name[0] != 'q' && etc[0] != 'q' && number == 0) {
                        printf("1: ");
                        printf(ERROR_INPUT);
                    }
                    break;
                }

                switch(AddWithProfile(newLog)) {
                    case TaskComplete :    // Success
                        printf("Add new profile succesfully\n");
                    break;
                    case ErrorWrongInput :    // input fail
                        printf("2: ");
                        printf(ERROR_INPUT);
                    break;
                    case ErrorDuplicant :    // duplicant fail
                    {
                        printf(ERROR_DUPLICANT);
                        
                        char *replace = malloc(2);
                        InputString("Do you wish to override profile? [y/n] : ", replace, 2);

                        if (fn_strcmp(replace, "y") == 0) {
                            free(replace);
                            input = 5;
                            continue;
                        }

                        free(replace);
                    }
                    break;
                    case ErrorTargetEmpty :    // memory allocation fail
                        printf(ERROR_PROFILE_EMPTY);
                    break;
                    default :
                        printf(ERROR_UNKNOWN);
                    break;
                }
            }
            break;
            case 2: {   // Search
                // Input name
                InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);

                // Search profile
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

                // Input name
                InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);
                // Break, if name equals exit char
                if (fn_strcmp(name, QUIT) == 0) break;

                switch(Delete(name)) {
                    case TaskComplete :    // Success
                        printf("Delete succesfully\n");
                    break;
                    case ErrorDataMissing :    // input fail
                        printf(ERROR_PROFILE_MISSING);
                    break;
                    default :
                        printf(ERROR_UNKNOWN);
                    break;
                }
            }
            break;
            case 4: {   // Print
                PrintAllProfiles();
            }
            break;
            case 5: {   // Replace
                // Input name string if the name string is empty
                if (name == NULL || name[0] == '\0') {
                    InputString("Target Profile Name (Max 15) : ", name, MAX_NAME_SIZE);
                }

                // If the name string is still empty, go to exception
                if (Search(name) != NULL) {
                    printf(ERROR_PROFILE_MISSING);
                    break;
                }

                // Create new profile
                Profile *newLog = InputDefaultInformations(name, &number, etc);
                if (newLog == NULL) {
                    if (name[0] != 'q' && etc[0] != 'q' && number == 0) {
                        printf("1: ");
                        printf(ERROR_INPUT);
                    }
                    break;
                }

                // Replace profile
                switch(ReplaceWithProfile(newLog)) {
                    case TaskComplete :    // Success
                        printf("Repace succesfully\n");
                    break;
                    case ErrorTargetEmpty :
                        printf(ERROR_PROFILE_EMPTY);
                    break;
                    case ErrorTargetMissing :    // input fail
                        printf(ERROR_PROFILE_MISSING);
                    break;
                    default :
                        printf(ERROR_UNKNOWN);
                    break;
                }
            }
            break;
            case 6: {
                // Save current profile informations
                SaveProfileData();
                printf("Save Process Complete\n");
            }
            break;
            case 0: {   // Exit
                // Save current profile informations
                SaveProfileData();
                MemoryFree();
                printf("System Shutdown\n");
            }
            // Exit the process
            return EXIT_SUCCESS;
            default:
                printf(ERROR_INPUT);
            break;
        }
        
        input = 999999;
        printf("\nPress Enter key to continue...\n");
        CleanBuffer();
    }

    return EXIT_FAILURE;
} 

// <summary> Input string from std input
// <parameter=*guidText> Init string to show or guide what to write
// <parameter=*target> Input taraget string
// <parameter=size> Input size
// <return> Return input target address
char* InputString(char* guidText, char* target, size_t size) {
    printf("%s", guidText);

    // Clean up fgets buffer
    fflush(stdin); 

    // Input string
    fgets(target, size, stdin);
    
    // Clean up the end of the target string
    size_t len = strlen(target);
    if (len > 0 && target[len - 1] == '\n') {
        target[len - 1] = '\0';
    }

    return target;
}

// <summary> Input unsigned int from std input
// <parameter=*guidText> Init string to show or guide what to write
// <parameter=*number> Input taraget unsigned int
void InputNumeric(char* guidText, unsigned int *number) {
    printf("%s", guidText);

    // Number input region
    scanf("%8u", number);
    // Clean up scanf buffer
    CleanBuffer();
}

// <summary> Create new profile based on the information that given
// <parameter=*name> name string
// <parameter=*number> number int pointer
// <parameter=*etc> etc string
// <return=NULL> Return NULL pointer on fail to make new profile
// <return=Profile> Return Profile object on successfully finish the task
Profile* InputDefaultInformations(char *name, unsigned int *number, char *etc) {
    printf(DIVIDER_LINE);
    printf("Enter New Information (\'q\' to cancel)\n");

    // Name input region
    // Get new name string if name is NULL
    if (name == NULL) {
        char temp[MAX_NAME_SIZE];
        name = InputString(OUTPUT_ENTER_NAME, temp, MAX_NAME_SIZE);
    }
    // Get new name string if the name is empty
    else if (name[0] == '\0' || name[0] == '\n') { 
        InputString(OUTPUT_ENTER_NAME, name, MAX_NAME_SIZE);
    }
    // Print out current name
    else {  
        printf(OUTPUT_ENTER_NAME);
        printf("%s\n", name);
    }
    if (fn_strcmp(name, QUIT) == 0) return NULL;

    // Number input region
    // Print out number, if it's valid
    if (*number > 99999999 && *number < 10000000) { 
        printf(OUTPUT_ENTER_NUMBER);
        printf("%d\n", *number);
    } 
    // Enter new number
    else { 
        InputNumeric(OUTPUT_ENTER_NUMBER, number);
        if (*number > 99999999 || *number < 10000000) *number = 0;
        if (*number == 0) return NULL;
    }
    
    // Etc input region
    // Get new etc string if etc is NULL
    if (etc == NULL) {
        char temp[MAX_ETC_SIZE];
        etc = InputString(OUTPUT_ENTER_ETC, temp, MAX_ETC_SIZE);
    } 
    // Get new etc string if the etc is empty
    else if (etc[0] == '\0' || etc[0] == '\n') { 
        InputString(OUTPUT_ENTER_ETC, etc, MAX_ETC_SIZE);
    }
    // Print out current etc
    else {
        printf(OUTPUT_ENTER_ETC);
        printf("%s\n", etc);
    }
    if (fn_strcmp(etc, QUIT) == 0) return NULL;

    return CreateNewProfile(name, *number, etc);
}
