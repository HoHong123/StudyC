#include <stdio.h>
#include <string.h>

// 널문자를 세지 않고 문자열의 길이를 구하는 함수
int get_length(const char* string)
{
	int length = 0;
	while (*(string + length) != '\0')
	{
		length++;
	}

	return length;
}

// 절대값 구하기
int abs(int number)
{
	return number >= 0 ? number : -1 * number;
}


// 문자열 비교하기 (ASCII 값을 비교해서 비교 결과 리턴)
/*
* 
* -1 : string1 이 string2 보다 작음
* 0 : string1 이 string2 과 같음
* 1 : string1 이 string2 보다 큼
*/
int fn_strcmp(const char* string1, const char* string2)
{
	int length1 = get_length(string1);
	int length2 = get_length(string2);

	int min_length = length1 < length2 ? length1 : length2;
	
	int diff = 0;
	for (int i = 0; i < min_length; i++)
	{
		char char1 = *(string1 + i);
		char char2 = *(string2 + i);

		diff = char1 - char2;

		if (diff != 0) {
			return diff / abs(diff);
		}
	}

	if (length1 != length2)
		diff = (length1 - length2) / (abs(length1 - length2));

	return diff;
}

int main()
{
	
	char string1[] = "aaz";
	char string2[] = "aaz";
	char string3[] = "baz";
	char string4[] = "bazz";
	char string5[] = "";
	char string6[] = "";

	printf("result 1 : %d\n", fn_strcmp(string1, string2)); // 0
	printf("result 2 : %d\n", fn_strcmp(string2, string3)); // -1
	printf("result 3 : %d\n", fn_strcmp(string3, string4)); // -1
	printf("result 4 : %d\n", fn_strcmp(string4, string5)); // 1
	printf("result 5 : %d\n", fn_strcmp(string5, string6)); // 0
}