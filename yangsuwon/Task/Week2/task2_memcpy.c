#include <stdio.h>
#include <string.h>
void memcpy_fn(char* s1,char* s2, size_t count){
        while (count--)
        {
            *s1++ = *s2++;
        }
        
}
void main(){
        char src[32] = "hello";
        char dest[32] = "word";
 

        /* src 메모리를 sizeof(src) 만큼 (32byte) dest 로 복사합니다. */
        memcpy_fn( src, dest, sizeof(src));
        printf( "%s\n", dest);
        
}