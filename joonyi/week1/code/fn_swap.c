#include <unistd.h>

/*
ChatGPT 가 짜준 write() 함수로 포인터 출력하는 함수
*/
void print_address(void *ptr) {
    unsigned long addr = (unsigned long) ptr;
    char buffer[20];
    char *bufptr = &buffer[19];
    *bufptr = '\0'; // Null terminate

    do {
        --bufptr;
        *bufptr = "0123456789abcdef"[addr % 16];
        addr /= 16;
    } while (addr > 0);

    --bufptr;
    *bufptr = 'x';
    --bufptr;
    *bufptr = '0';

    write(1, bufptr, &buffer[19] - bufptr);
    write(1, "\n", 1);
}

char *charValue(int a)
{
    char buffer[12];
    char *ptr = &buffer[11];
    *ptr = '\0';

    if (a == 0)
    {
        --ptr;
        *ptr = '0';
    }
    else 
    {
        int is_negative = a < 0;
        if (is_negative)
        {
            a = -a;
        }

        while (a)
        {
            --ptr;
            *ptr = '0' + (a % 10);
            a /= 10;
        }

        if (is_negative)
        {
            --ptr;
            *ptr = '-';
        }
    }

    return ptr;
}

int getLength(int a)
{
    int length = 0;
    if (a == 0)
    {
        length = 1;
    }
    while (a)
    {
        length += 1;
        a /= 10;
    }

    return length;
}


/*
내가 짠 값 바꾸는 함수 
C는 call by value 이다.
*/
void fn_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int a = 10;
    int b = 20;

    int c = 100;
    write(1, &c, sizeof(c));
    write(1, "\n", 1);

    fn_swap(&a, &b);

    write(1, charValue(a), getLength(a));
    write(1, "\n", 1);
    write(1, charValue(b), getLength(b));
    write(1, "\n", 1);
}