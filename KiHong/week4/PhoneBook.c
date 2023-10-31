#include "PhoneBook.h"


Book book;


void Initialize() {
    // Initialize table
    for (int k = 0; k < MAX_SIZE; k++) {
        book.table[k] = NULL;
    }

    // Get all data from text file
    char * token = strtok(FSDecoding(), ",");
    char *input[3];
    int k = 0;
    // Splite text by "," delimiter
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

// <summary> Create new profile object
// <parameter=name> Profile name string
// <parameter=number> Profile number
// <parameter=etc> Profile etc string
// <return=Success> New Profile object
// <return=Fail> NULL
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

// <summary> Add new profile in phone book table
// <parameter=name> Profile name string
// <parameter=number> Profile number
// <parameter=etc> Profile etc string
// <return=0> Task Success
// <return=1> Invalid input value
// <return=2> Profile already exist
// <return=3> Fail to create new profile object
int Add(char* name, unsigned int number, char* etc) {
    if (name[0] == '\0' || (number > 99999999 || number < 10000000)) {
        return ErrorWrongInput;
    }

    if (Search(name) != NULL) {
        return ErrorDuplicant;
    }

    Profile *newLog = CreateNewProfile(name, number, etc);
    if(newLog == NULL) {
        return ErrorTargetMissing;
    }
    
    book.table[Hash(name)] = newLog;

    return TaskComplete;
}
// <summary> Add new profile in phone book table
// <parameter=profile> New Profile object
// <return=0> Task Success
// <return=1> Invalid input value
// <return=2> Profile already exist
// <return=3> Fail to create new profile object
int AddWithProfile(Profile *profile) {
    if (profile == NULL) {
        return ErrorTargetEmpty;
    }

    if (profile->name[0] == '\0' || (profile->number > 99999999 || profile->number < 10000000)) {
        return ErrorWrongInput;
    }

    if (Search(profile->name) != NULL) {
        return ErrorDuplicant;
    }

    book.table[Hash(profile->name)] = profile;

    return TaskComplete;
}

// <summary> Delete exist profile in phone book table
// <parameter=profile> New Profile object
// <return=0> TaskComplete
// <return=2> ErrorDataMissing
int Delete(char* profile) {
    if (Search(profile) == NULL)
        return ErrorDataMissing;
    
    
    Profile* temp = book.table[Hash(profile)];
    book.table[Hash(profile)] = NULL;
    free(temp);

    return TaskComplete;
}

// <summary> Replace exist profile in phone book table
// <parameter=*targetName> Target Profile name
// <parameter=*newNumber> Target Profile new number
// <parameter=*newEtc> Target Profile new etc
// <return=0> TaskComplete
// <return=5> ErrorTargetMissing
int Replace(char* targetName, unsigned int newNumber, char* newEtc) {
    Profile *replacer = Search(targetName);
    if (replacer == NULL)
        return ErrorTargetMissing;
    
    replacer->number = newNumber;
    *replacer->etc = *newEtc;

    return TaskComplete;
}
// <summary> Replace exist profile in phone book table
// <parameter=*profile> New Profile object
// <return=0> TaskComplete
// <return=4> ErrorTargetEmpty
// <return=5> ErrorTargetMissing
int ReplaceWithProfile(Profile *profile) {
    if (profile == NULL) {
        return ErrorTargetEmpty;
    }

    Profile *replacer = Search(profile->name);
    if (replacer == NULL){
        return ErrorTargetMissing;
    }
    

    replacer->number = profile->number;
    fn_strcpy(replacer->etc, profile->etc);

    free(profile);
    
    return TaskComplete;
}

// <summary> Search exist profile in phone book table
// <parameter=*key> Profile name
// <return=NULL> Return NULL on fail to find target
// <return=Profile> Return profile object
Profile* Search(const char* key) {
    if(book.table[Hash(key)] == NULL) {
        return NULL;
    }

    Profile* current = book.table[Hash(key)];
    if (fn_strcmp(current->name, key) != 0) {
        return NULL;
    }

    return current;
}

// <summary> Print out all profiles
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

// <summary> Print out profile properties
void PrintProfile(Profile *profile) {
    printf("Name : %s\n", profile->name);
    printf("Number : %u\n", profile->number);
    printf("ETC : %s\n", profile->etc);
}

// <summary> Save all profile informations into file system
void SaveProfileData() {
    char *saveData = (char*)malloc(1);
    saveData[0] = '\0';

    for (int k = 0; k < MAX_SIZE; k++) {
        if (book.table[k] != NULL) {
            int nameSize = strlen(book.table[k]->name);
            int etcSize = strlen(book.table[k]->etc);
            char info[(nameSize + etcSize + sizeof(long long) + 6)];

            // Copy name
            fn_strcpy(info, book.table[k]->name);
            //strcpy(info, book.table[k]->name);
            fn_strcat(info, ",");
            // Cat number
            // Need sprintf to convert int to char*
            char num[16];
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

void MemoryFree() {
    for (int k = 0; k < MAX_SIZE; k++) {
        free(book.table[k]);
    }
}