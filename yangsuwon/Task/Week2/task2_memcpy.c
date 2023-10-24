#include <stdio.h>
#include <string.h>
void memcpy_fn(char* s1,char* s2, size_t count){
        while (count--)
        {
            *s1++ = *s2++;
        }
        
}
/**
 * stcpy와 memcpy의 차이는 어디까지 복사할 것인가의 차이가 있습니다.
 * stcpy의 경우 '\n' 을 만나기 전까지 복사를 하고
 * memcpy의 경우 매개변수로 주어진 숫자만큼 복사합니다. 
*/

void main(){
        char src[32] = "hello";
        char dest[32] = "word";
 
        memcpy_fn( src, dest, sizeof(src));
        printf( "%s\n", dest);
        
}