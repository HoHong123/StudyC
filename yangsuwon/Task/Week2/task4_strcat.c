#include <stdio.h>

/**
 * strcat 함수는 두개의 문자열 인자를 매개변수를 받아 첫번째
 * 문자열에 두번째 문자열을 더해 리턴하는 함수 입니다. 
 * 
 * 참고 문서: 
 * https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/strcat-wcscat-mbscat?view=msvc-170
*/
char* strcat_fn(char*dest, char*sour){

    while(*dest){ 
        dest++;
    }


    while (*sour)
    {
        *dest = *sour;
        sour++;
        dest++;
    }
    *dest = '\0';
    printf("%p\n", dest);
    return dest;
    
}
int main(void){
    char string[100] ="";
printf("%s \n",
   strcat_fn( string, "Hello world from " ) );
   strcat_fn( string, "strcpy " );           
   strcat_fn( string, "and " );              
   strcat_fn( string, "strcat!" );           
//    printf( "String = %p\n", string );
}