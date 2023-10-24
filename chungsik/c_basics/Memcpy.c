/*memcpy
void *memcpy (void *__restrict __dest, const void *__restrict __src, size_t __n) __THROW __nonnull ((1, 2));*/

#include<stdio.h> 
#include<stdlib.h> //malloc
#include<string.h>

void fn_Memcpy(void* destination, const void* source, size_t size)
{
    //source -> destination to copy
    unsigned char* dest = (unsigned char*) destination;
    const unsigned char* src = (const unsigned char*) source;

    for(size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int main()
{
    int size;

    printf("복사할 배열 크기 : ");
    scanf("%d", &size);

    int* arr1 = (int* )malloc(size * sizeof(int));
    int* arr2 = (int* )malloc(size * sizeof(int));
    
    printf("배열에 값 입력 : ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr1[i]);
    }

    //size_t 로 비트마다 다른 바이트 수를 가진다. 일관되게 작동함.
    size_t bytecopy = size * sizeof(int); 

    fn_Memcpy(arr2, arr1, bytecopy);
    printf("함수 memcpy 구현 : ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");


    memcpy(arr2, arr1, bytecopy);
    printf("memcpy함수 사용 : ");
     for(int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);

    return 0;
}



// #pragma memcpydynamicallocation

// void* fn_Memcpy(int *destination, int *src, int size)
// {
//     for(int i = 0; i < sizeof(src); i++) {
//         destination[i] = src[i];
//     }
// }


// int main()
// {
//     int size; 
//     printf("배열 크기 입력 : ");
//     scanf("%d", &size);
    
//     int *src = (int*) malloc(sizeof(int) * size); //원본 배열 
//     int *destination = (int*) malloc(sizeof(int) * size);

//     printf("정수 입력 : ");
//     for(int i = 0; i < size; i++) {
//         scanf("%d", &src[i]);
//     }

//     fn_Memcpy(destination, src, size);

//     //copy 
//     printf("copy memory : ");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", destination[i]);
//     }
//     printf("\n");

//     //mem delete
//     free(src);
//     free(destination);

//     return 0;
// }

// #pragma endregion