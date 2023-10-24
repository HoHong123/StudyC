#include <stdio.h>

void is_negaive(int n){
    if(n >0){
        printf("%s","P" );
    }else if (n<0)
    {
        printf("%s", "N");
    }else{
        printf("%s", "0");
    }
    
}

void main(){
    int n;
    scanf("%d", &n);

    is_negaive(n);
}