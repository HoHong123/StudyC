#include "FSConverter.h"

#define TEXTFILE "PhoneBookLog.txt";

// 현재 fopen 오류 발생
void CheckForFile() {
    printf("outc1\n");
    // Check the file and create new one if it doesn't exist
    FILE *afs = fopen("PhoneBookLog.txt", "a");
    printf("outc2\n");
    fclose(afs);
    printf("outc3\n");
}

int FSIncoding (char* input) {
    CheckForFile();

    printf("out1\n%s\n", input);
    // Open the file to write
    // Create new one if there's no file
    FILE *fs = fopen("PhoneBookLog.txt", "w");
    printf("out2\n");

    if (fs == NULL)
    {
        perror(ERROR_FS_OPEN);
        return 1;
    }
    printf("out3\n");
    
    // Calcualte length of the text
    fprintf(fs, "%s", input);
    printf("out4\n");

    // close the file
    fclose(fs);
    printf("out5\n");

    return 0;
}

char *FSDecoding () {
    CheckForFile();

    // Open the file to read
    FILE *fs = fopen("PhoneBookLog.txt", "r");

    if (fs == NULL)
    {
        perror(ERROR_FS_OPEN);
        return NULL;
    }
    
    // 파일 끝으로 이동하여 파일 크기 확인
    // Move to end of the file to Check size of the file
    fseek(fs, 0, SEEK_END); 
    long fileSize = ftell(fs);
    // 파일 읽기 위치를 다시 파일의 시작으로 되돌림
    // Reset read position to start of the file
    rewind(fs); 

    // Buffer
    char *buffer = (char*)malloc(fileSize + 1);

    if (buffer == NULL) {
        printf("ERROR::Memorry allocation fail\n");
        fclose(fs);
        return NULL;
    }

    // 파일 내용을 버퍼로 읽음
    // Read all file
    size_t bytesRead = fread(buffer, 1, fileSize, fs); 
    // 문자열 종료 문자 추가
    buffer[bytesRead] = '\0'; 

    // close the file
    fclose(fs);

    return buffer;
}
