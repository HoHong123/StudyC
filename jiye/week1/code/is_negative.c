#include <stdio.h>
#include <string.h>
#include <unistd.h>

void is_negative(int n);

int main(){
    int n;
    printf("정수를 입력하세요 : ");
    scanf("%d", &n);

    is_negative(n);


}

void is_negative(int n){
    char output[2];
    
    if (n>0) 
        output[0] = 'P';
    else if (n<0)
        output[0] = 'N';
    else
        output[0] = '0';

    output[1] = '~';

    write(1, output, strlen(output));
    write(1, '\n', 1);

}

