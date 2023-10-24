#include <stdio.h>

void fn_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 10, b = 20;

    fn_swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}


/*#include <stdio.h>

void fn_swap(int *a, int *b)
{
	int temp = int *a;
	 int *a =  int *b;
	 int *b =  int temp;
}

int main(void){

	int a = 10, b = 20;

	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	
}*/
/*
#include <stdio.h>



int main(void)
{


fn_swap(&num, &p, &pp, &ppp)


	return 0;
}

void multiple_pointer_handle(int****nbr);
{
	int temp = 0;


}*/
