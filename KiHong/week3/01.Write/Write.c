#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int fd = open("Test.txt", O_RDWR);

    char buffer[1024];

    if (fd > 0) {
        // '\n'문자가 나올때까지 모든 문자 입력 (띄어쓰기, 탭 등 기타 문자도 입력)
        scanf("%[^\n]s", buffer);
        printf("%s", buffer);
        write(fd, &buffer, strlen(buffer));
    }

    close(fd);

    return 0;
}