#include <stdio.h>
#include <string.h>

int get_length(char* string)
{
	int index = 0;
	while (*(string + index) != '\0')
	{
		index++;
	}

	return index + 1;
}

char* fn_strcpy(char* target, char* origin)
{
	int length = get_length(origin);

	for (int i = 0; i < length; i++)
	{
		*(target + i) = *(origin + i);
	}

	return target;
}

int main()
{
	char c[] = "asdf";
	char buffer[5];

	// 공간이 충분한 경우에만 복사
	if (sizeof(buffer) >= get_length(c))
	{
		fn_strcpy(buffer, c);
		printf("%s\n", buffer);
	}
	else {
		printf("복사하려는 공간이 복사할 문자열보다 작습니다.");
	}

	return 0;
}