#include <stdio.h>


void fn_strcpy(char* destination, const char* source);

int main()
{
	char source[20] = "";
	scanf("%[^\n]s", source);
	char destination[20];

	fn_strcpy(destination, source);

	printf("복사전 : %s\n", source);
	printf("복사후 : %s\n", destination);

	return 0;
}


void fn_strcpy(char* destination, const char* source) //string -> strcpy 함수 정의된 파라미터 참고
{
	// destination으로부터 source로 문자열을 복사
	while (*source)
	{
		*destination = *source;
		source++;
		destination++;
	}
	//문자열 끝을 나타내는 null문자 
	*destination = '\0';
}