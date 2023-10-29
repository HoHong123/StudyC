#include "PhoneBook.h"


Book book;

void Initialize() {
    for (int k = 0; k < MAX_SIZE; k++) {
        book.table[k] = NULL;
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
        return 1;
    }

    if (profile->name[0] == '\0' || (profile->number > 99999999 || profile->number < 10000000)) {
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
        return 1;
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