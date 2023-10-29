#include <unistd.h>
#include <stdio.h>

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void fn_sort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            int *left = (arr + j);
            int *right = (arr + j + 1);

            if (*right < *left)
            {
                swap(left, right);
            }
        }
    }
}

int main()
{
    int array[] = {5, 10, 7, 2, 4};
    int length = sizeof(array) / sizeof(int);
    fn_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}