#include <stdio.h>
#include <string.h>

void* fn_memcpy(void* dest, const void* source, size_t num)
{
    char* destination = (char*) dest;
    const char* origin = (const char*) source;

    for (int i = 0; i < num; i++)
    {
        *(destination + i) = *(origin + i);
    }

    return dest;
}

int main()
{
    int int_origin[] = { 1, 2, 3, 4 };
    int int_target[40];

    fn_memcpy(int_target, int_origin, sizeof(int_origin));

    // 정수 배열 출력
    for (int i = 0; i < sizeof(int_origin) / 4; i++)
    {
        printf("%d\n", *(int_target + i));
    }

    char char_origin[] = "test!!!";
    char char_target[2];

    fn_memcpy(char_target, char_origin, sizeof(char_origin));

    printf("%s\n", char_target);
}