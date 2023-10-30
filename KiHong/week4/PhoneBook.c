#include "PhoneBook.h"


Book book;


void Initialize() {
    // Initialize table
    for (int k = 0; k < MAX_SIZE; k++) {
        book.table[k] = NULL;
    }

    char * token = strtok(FSDecoding(), ",");
    char *input[3];
    int k = 0;

    while (token != NULL) {
        input[k++] = token;
        if (k > 2) {
            AddWithProfile(CreateNewProfile(input[0], atoi(input[1]), input[2]));
            k = 0;
        }

        token = strtok(NULL, ",");
    }
}

int Hash(const char* key) {
    int hash = 0;

    while (*key) {
        hash += *key;
        key++;
    }

    return hash % MAX_SIZE;
}

Profile *CreateNewProfile(char* name, unsigned int number, char* etc){
    Profile *newLog = (Profile*)malloc(sizeof(Profile));

    if (newLog == NULL) {
        printf(ERROR_MEMORY_ALLOCATION);
        return NULL;
    }
    
    fn_strcpy(newLog->name, name);
    fn_strcpy(newLog->etc, etc);
    newLog->number = number;

    return newLog;
}

int Add(char* name, unsigned int number, char* etc) {
    if (name[0] == '\0' || (number > 99999999 || number < 10000000)) {
        printf(ERROR_INPUT);
        return 1;
    }

    if (Search(name) != NULL) {
        printf(ERROR_DUPLICANT);
        return 2;
    }

    Profile *newLog = CreateNewProfile(name, number, etc);
    if(newLog == NULL) {
        return 3;
    }
    
    book.table[Hash(name)] = newLog;

    return 0;
}
int AddWithProfile(Profile *profile) {
    if (profile == NULL) {
        printf("ERROR::Profile is Empty\n");
        return 1;
    }

    if (profile->name[0] == '\0' || (profile->number > 99999999 || profile->number < 10000000)) {

        printf("ERROR::Profile data is Empty\n");
        return 1;
    }

    if (Search(profile->name) != NULL) {
        return 2;
    }

    book.table[Hash(profile->name)] = profile;

    return 0;
}

int Delete(char* profile) {
    if (Search(profile) == NULL)
        return 1;

    book.table[Hash(profile)] = NULL;

    return 0;
}

int Replace(char* targetName, unsigned int newNumber, char* newEtc) {
    Profile *replacer = Search(targetName);
    if (replacer == NULL)
        return 1;
    
    replacer->number = newNumber;
    *replacer->etc = *newEtc;

    return 0;
}
int ReplaceWithProfile(Profile *profile) {
    if (profile == NULL) {
        return 1;
    }

    Profile *replacer = Search(profile->name);
    if (replacer == NULL){
        return 2;
    }
    
    replacer->number = profile->number;
    *replacer->etc = *profile->etc;

    return 0;
}

Profile* Search(const char* key) {
    if(book.table[Hash(key)] == NULL) {
        return NULL;
    }

    Profile* current = book.table[Hash(key)];
    if (fn_strcmp(current->name, key) == 0) {
        return current;
    }

    return current;
}

void PrintAllProfiles() {
    int count = 0;
    for (int k = 0; k < MAX_SIZE; k++) {
        if (book.table[k] != NULL) {
            count++;
            printf(DIVIDER_LINE_THIN);
            PrintProfile(book.table[k]);
        }
    }

    printf(DIVIDER_LINE_THIN);
    printf("Totall : %d\n", count);
}

void PrintProfile(Profile *profile) {
    printf("Name : %s\n", profile->name);
    printf("Number : %u\n", profile->number);
    printf("ETC : %s\n", profile->etc);
}

void SaveProfileData() {
    char *saveData = (char*)malloc(1);
    saveData[0] = '\0';

    for (int k = 0; k < MAX_SIZE; k++) {
        if (book.table[k] != NULL) {
            int nameSize = strlen(book.table[k]->name);
            int etcSize = strlen(book.table[k]->etc);
            char* info = (char*)malloc(nameSize + etcSize + MAX_NUMBER_SIZE + 6);

            // Copy name
            fn_strcpy(info, book.table[k]->name);
            fn_strcat(info, ",");
            // Cat number
            // Need sprintf to convert int to char*
            char num[sizeof(long long)];
            sprintf(num, "%u", book.table[k]->number);
            fn_strcat(info, num);
            fn_strcat(info, ",");
            // Cat etc
            // If etc is empty, add space
            // If not strtok will think it's the end of the string
            if (etcSize == 0)
                fn_strcat(info, "\x20");
            else
                fn_strcat(info, book.table[k]->etc);
            fn_strcat(info, ",");

            // Save the process
            fn_strcat(saveData, info);
        }
    }
    
    fn_strcat(saveData, "\0");

    FSIncoding(saveData);
}