/*
1. 전화번호부의 사이즈는 8로 고정합니다.
2. "add"를 입력하면 전화번호를 입력하는 창이 나오는데 "이름", "전화번호", "기타" 정보를 입력할 수 있습니다.
3. "search"를 입력하고 전화번호부의 index를 입력하면 해당 인덱스에 담겨있는 정보가 출력됩니다.
4. "exit"를 입력하면 종료됩니다.
5. 그 외 기능은 편하신대로 추가해주세요.
*/

/*
1. validation  - 전화번호 등
2. 


*/
#include <stdio.h>
#include <string.h>

int abs(int n) {
	if (n < 0)
	{
		return -1 * n;
	}
	return n;
}

int min(int* left, int* right)
{
	if (*left < *right)
	{
		return *left;
	}

	return *right;
}

int get_length(const char* c)
{
	int length = 0;
	while (*(c + length) != '\0')
	{
		length++;
	}

	return length;
}

int fn_strcmp(const char* c1, const char* c2)
{
	int length1 = get_length(c1);
	int length2 = get_length(c2);

	int min_length = min(&length1, &length2);

	int result = 0;
	for (int i = 0; i < min_length; i++)
	{
		unsigned char char1 = (unsigned char) (*(c1 + i));
		unsigned char char2 = (unsigned char) (*(c2 + i));

		int diff = char2 - char1;

		if (diff != 0)
		{
			result = diff / abs(diff);
			return result;
		}
	}

	result = length1 - length2;

	if (result != 0)
	{
		return (length1 - length2) / abs(length1 - length2);
	}

	return result;
}

char* fn_strcpy(char* target, char* origin)
{
	int length = get_length(origin);

	for (int i = 0; i < length; i++)
	{
		*(target + i) = *(origin + i);
	}

	*(target + length) = '\0';

	return target;
}



int main()
{
	char command[1000];

	char names[8][100];
	char phones[8][100];
	char notes[8][1000];

	char left[] = "zzzzasdf";
	char right[] = "zzzzasdf";

	fn_strcpy(names[0], left);

	int page_count = 0;
	while (1)
	{
		printf("********************************************************************************\n"); // * 80개
		printf("**                          전화번호부 - Phone Book                           **\n"); // 글자수 한글 5개 나머지 14개 = 24
		printf("**   현재 저장중인 연락처 : %d 개                                              **\n", page_count); // 공백 80개
		printf("**                                                                            **\n"); //
		printf("**  ┌─────── Commands──────────────┐                                          **\n"); //
		printf("**  │ add           연락처 추가    │                                          **\n"); //
		printf("**  │ search        연락처 검색    │                                          **\n"); //
		printf("**  │ exit          프로그램 종료  │                                          **\n"); //
		printf("**  └──────────────────────────────┘                                          **\n"); //
		printf("**                                                                            **\n"); //
		printf("**                                                                            **\n"); //
		printf("**                                                                            **\n"); //
		printf("********************************************************************************\n"); // 
		scanf("%s", command);

		if (fn_strcmp(command, "add") == 0)
		{
			printf("add 를 입력했습니다.\n");
			printf("이름, 전화번호, 기타 순으로 입력해주세요.\n");

			char name[10];
			char phone[10];
			char note[100];

			printf("100자 이내의 이름을 입력해주세요. : ");
			scanf("%s", name);
			printf("전화번호를 입력해주세요. : ");
			scanf("%s", phone);
			printf("기타(비고)를 입력해주세요. : ");
			scanf("%s", note);

			printf("[입력한 이름, 전화번호, 기타]\n이름 : %s\n전화번호 : %s\n기타 : %s\n", name, phone, note);
			printf("[입력한 이름, 전화번호, 기타 의 사이즈]\n이름 : %d\n 전화번호 : %d\n, 기타 : %d\n", get_length(name), get_length(phone), get_length(note));
			
			fn_strcpy(names[page_count], name);
			fn_strcpy(phones[page_count], phone);
			fn_strcpy(notes[page_count], note);
			page_count++;
		}
		else if (strcmp(command, "search") == 0)
		{
		    int index = 0;
			printf("search 를 입력했습니다.");
			printf("조회할 전화번호 인덱스를 입력해주세요. : ");
		    scanf("%d", &index);
		    
		    
			printf("조회한 전화번호부는 다음과 같습니다.\n이름 : %s\n전화번호 : %s\n기타 : %s\n", names[index], phones[index], notes[index]);
		}
		else if (strcmp(command, "exit") == 0)
		{
			printf("exit 를 입력했습니다.\n");
			return 0;
		}
		else
		{
			printf("올바른 명령어를 입력하세요.\n");
		}
	}

}