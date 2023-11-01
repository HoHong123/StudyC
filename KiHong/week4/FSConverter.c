#include "FSConverter.h"

// 현재 fopen 오류 발생
void CheckForFile() {
    // Check the file and create new one if it doesn't exist
    FILE *afs = fopen("PhoneBookLog.txt", "a");
    fclose(afs);
}

void FSIncoding (char* input) {
    // Open the file to write
    // Create new one if there's no file
    FILE *fs = fopen("PhoneBookLog.txt", "w");

    if (fs == NULL)
    {
        perror(ERROR_FS_OPEN);
        fclose(fs);
        return;
    }
    
    // Calcualte length of the text
    fprintf(fs, "%s", input);

    // close the file
    fclose(fs);
}

char *FSDecoding () {
    CheckForFile();

    // Open the file to read
    FILE *fs = fopen("PhoneBookLog.txt", "r");

    if (fs == NULL)
    {
        perror(ERROR_FS_OPEN);
        fclose(fs);
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
