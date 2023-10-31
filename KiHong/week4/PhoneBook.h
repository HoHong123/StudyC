#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FSConverter.h"
#include "../week2/FnStrcpy.h"
#include "../week3/FnStrcat.h"
#include "../week3/FnStrcmp.h"


#define MAX_NAME_SIZE 31
#define MAX_ETC_SIZE 31
#define MAX_NUMBER_SIZE 5
#define MAX_SIZE 1000

#define DIVIDER_LINE "==============================\n"
#define DIVIDER_LINE_THIN "-----------------------\n"

#define ERROR_UNKNOWN "ERROR::Unknown error.\n"
#define ERROR_INPUT "ERROR::Incorrect input detected!\n"
#define ERROR_DATA_EMPTY "ERROR::Profile data is empty!\n"
#define ERROR_DUPLICANT "ERROR::Profile exist!\n"
#define ERROR_PROFILE_EMPTY "ERROR::Profile is empty.\n"
#define ERROR_PROFILE_MISSING "ERROR::Profile doesn't exist.\n"
#define ERROR_OUT_OF_STACK "ERROR::Cannot add more profile. Reached Maximum length.\n"
#define ERROR_MEMORY_ALLOCATION "ERROR::Memory allocation fail\n"


typedef enum _ERROR {
    TaskComplete = 0,
    ErrorWrongInput,
    ErrorDataMissing,
    ErrorDuplicant,
    ErrorTargetEmpty,
    ErrorTargetMissing,
    ErrorOutOfStack,
    ErrorMemoryAllocationFail,
} ERROR;


typedef struct PhoneBook
{
    char name[MAX_NAME_SIZE];
    char etc[MAX_ETC_SIZE];
    unsigned int number;
} Profile;

// 해시 테이블 구조체
typedef struct HashTable {
    // 해시라고 해놓고 해시가 아닌 해시 같은 너
    // TO DO : 
    // 1. 해시 기능 구현
    // 2. 해시 관련 기능 구현 (find, add, search.. etc)
    Profile* table[MAX_SIZE];
} Book;


void Initialize();

Profile *CreateNewProfile(char* name, unsigned int number, char* etc);

int Add(char* name, unsigned int number, char* etc);
int AddWithProfile(Profile *profile);

int Delete(char* profile);

int Replace(char* targetName, unsigned int newNumber, char* newEtc);
int ReplaceWithProfile(Profile *profile);

Profile* Search(const char* key);

void PrintAllProfiles();
void PrintProfile(Profile *profile);

void SaveProfileData();

void MemoryFree();