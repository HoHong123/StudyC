// memcpy를 만들어보고 strcpy와 memcpy의 차이를 서술하시오

//memcpy 예제 (char*타입)
#include<string.h>
#include<stdio.h>
 
int main(void)
{
    char src[] = "BlockDMask";
    char dest1[] = "abcdefghijklmnop";
    char dest2[] = "abcdefghijklmnop";
 
    // 메모리 복사1 : src 길이만큼만 복사
    memcpy(dest1, src, sizeof(char) * 10);
 
    // 메모리 복사2 : src 길이 + 1 만큼 복사
    memcpy(dest2, src, sizeof(char) * 10 + 1);
 
    // source
    printf("src  : %s\n", src);
    
    // destination
    printf("dest1 : %s\n", dest1);
    printf("dest2 : %s\n", dest2);
 
    return 0;
}
/*차이점: 
strncpy는 정해진 길이 또는 Null을 만날 때 까지 복사한다.
memcpy는 Null과 상관없이 정해진 길이만큼 복사한다.*/

