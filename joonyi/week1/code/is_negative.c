#include <stdio.h>
#include <unistd.h>

void is_negative(int n)
{
    char result[] = "0\n";
    if (n > 0)
    {
        result[0] = 'P';
    }
    else if (n < 0)
    {
        result[0] = 'N';
    }

    write(1, &result, sizeof(result));

}

int main()
{
    is_negative(3);
    is_negative(0);
    is_negative(-3);

    return 0;
}