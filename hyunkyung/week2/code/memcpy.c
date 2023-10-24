

 #include <stdio.h>
 #include <string.h>

 int main()
 {
    int src[] = {1,2,3};
    int dest[3];

//메모리 복사
    memcpy(dest, src, sizeof(int) * 3);

//복사한 배열
    for(int i = 0; i<3; ++i) 
{
    printf("%d ", src[i]);
}
    printf("\n");

    //복사된 배열
    for(int i = 0; i<3; ++i) 
{
    printf("%d ", dest[i]);
}
    printf("\n");


    return 0;
 }