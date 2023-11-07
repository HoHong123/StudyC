/*
1. 전화번호부의 사이즈는 8로 고정합니다.
2. "add"를 입력하면 전화번호를 입력하는 창이 나오는데 "이름", "전화번호", "기타" 정보를 입력할 수 있습니다.
3. "search"를 입력하고 전화번호부의 index를 입력하면 해당 인덱스에 담겨있는 정보가 출력됩니다.
4. "exit"를 입력하면 종료됩니다.
5. 그 외 기능은 편하신대로 추가해주세요.
*/

/*
1. validation  - 전화번호 등
2. 수정 기능
3. 삭제 기능
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
		unsigned char char1 = (unsigned char)(*(c1 + i));
		unsigned char char2 = (unsigned char)(*(c2 + i));

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


/**
* 접근 가능한 테이블의 인덱스를 찾는 함수.
* 접근 가능한 테이블이 없을 경우 -1 을 리턴한다.
*/
int get_first_existing(bool* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!*(table + i))
		{
			return i;
		}
	}

	return -1;
}

/** 
* bool 타입 배열 초기화 함수
*/
void fill_bool_array(bool* array, int size, bool value)
{
	for (int i = 0; i < size; i++)
	{
		*(array + i) = value;
	}
}

int main()
{
	const int size = 8;
	char command[1000];

	char names[size][100];
	char phones[size][100];
	char notes[size][1000];
	bool existings[size];

	fill_bool_array(existings, size, 0);
	printf("existings %d\n", get_first_existing(existings, size));

	int page_count = 0;
	while (1)
	{
		printf("********************************************************************************\n"); // * 80개
		printf("**                          전화번호부 - Phone Book                           **\n"); // 글자수 한글 5개 나머지 14개 = 24
		printf("**   현재 저장중인 연락처 : %d 개                                              **\n", page_count); // 공백 80개
		printf("**                                                                            **\n"); //
		printf("**                                                                            **\n"); //
		printf("**  ┌─────── Commands─────────────────┐                                       **\n"); //
		printf("**  │ add           연락처 추가       │                                       **\n"); //
		printf("**  │ search        연락처 검색       │                                       **\n"); //
		printf("**  │ put           연락처 전체 수정  │                                       **\n"); //
		printf("**  │ update        연락처 일부 수정  │                                       **\n"); //
		printf("**  │ delete        연락처 삭제       │                                       **\n"); //
		printf("**  │ exit          프로그램 종료     │                                       **\n"); //
		printf("**  └─────────────────────────────────┘                                       **\n"); //
		printf("**                                                                            **\n"); //
		printf("**                                                                            **\n"); //
		printf("**                                                                            **\n"); //
		printf("********************************************************************************\n"); //\

		scanf("%s", command);

		/**
		* 전화번호부 추가
		*/
		if (fn_strcmp(command, "add") == 0)
		{
			printf("add 를 입력했습니다.\n");
			printf("이름, 전화번호, 기타 순으로 입력해주세요.\n");

			char name[100];
			char phone[100];
			char note[1000];

			printf("100자 이내의 이름을 입력해주세요. : ");
			scanf("%s", name);
			printf("전화번호를 입력해주세요. : ");
			scanf("%s", phone);
			printf("기타(비고)를 입력해주세요. : ");
			scanf("%s", note);

			printf("[입력한 이름, 전화번호, 기타]\n이름 : %s\n전화번호 : %s\n기타 : %s\n", name, phone, note);
			printf("[입력한 이름, 전화번호, 기타 의 사이즈]\n이름 : %d\n 전화번호 : %d\n, 기타 : %d\n", get_length(name), get_length(phone), get_length(note));

			// 데이터를 저장할 인덱스 획득
			int index = get_first_existing(existings, size);

			/*
			* 값 저장 작업
			*/
			fn_strcpy(names[index], name);
			fn_strcpy(phones[index], phone);
			fn_strcpy(notes[index], note);

			/*
			* 사용된 인덱스 기록
			*/
			existings[index] = 1;

			page_count++;
		}
		/**
		* 전화번호부 조회
		*/
		else if (strcmp(command, "search") == 0)
		{
			int index = -1;
			printf("search 를 입력했습니다.\n");

			/*
			전화번호부가 비어있을 경우
			*/
			if (page_count == 0)
			{
				printf("저장된 전화번호부가 없습니다.\n");
				continue;
			}

			printf("조회할 수 있는 인덱스 : ");
			for (int i = 0; i < size; i++)
			{
				if (existings[i])
					printf("%d |", i);
			}
			printf("\n");
			printf("조회할 전화번호 인덱스를 입력해주세요. : ");
			scanf("%d", &index);

			if (existings[index])
			{
				printf("조회한 전화번호부는 다음과 같습니다.\n이름 : %s\n전화번호 : %s\n기타 : %s\n", names[index], phones[index], notes[index]);
			}
			else
			{
				printf("해당 인덱스에 전화번호부가 없습니다.\n");
			}
		}
		/**
		* 전화번호부 수정(put 방식, 전체 수정)
		*/
		else if (strcmp(command, "put") == 0)
		{
			int index = -1;
			printf("put 을 입력했습니다.\n");

			/*
			전화번호부가 비어있을 경우
			*/
			if (page_count == 0)
			{
				printf("수정할 전화번호부가 없습니다.\n");
				continue;
			}

			printf("수정할 수 있는 인덱스 : ");
			for (int i = 0; i < size; i++)
			{
				if (existings[i])
					printf("%d |", i);
			}
			printf("\n");
			printf("수정할 전화번호 인덱스를 입력해주세요. : ");
			scanf("%d", &index);

			char name[100];
			char phone[100];
			char note[1000];
			if (existings[index])
			{
				printf("100자 이내의 이름을 입력해주세요. : ");
				scanf("%s", name);
				printf("전화번호를 입력해주세요. : ");
				scanf("%s", phone);
				printf("기타(비고)를 입력해주세요. : ");
				scanf("%s", note);

				/*
				* 값 저장 작업
				*/
				fn_strcpy(names[index], name);
				fn_strcpy(phones[index], phone);
				fn_strcpy(notes[index], note);

				printf("전화번호부가 수정되었습니다.\n");
			}
			else
			{
				printf("해당 인덱스에 전화번호부가 없습니다.\n");
			}

		}
		/**
		* 전화번호부 수정(Patch 방식, 선택 항목 수정)
		*/
		else if (strcmp(command, "update") == 0)
		{
			int index = -1;
			printf("%s 을(를) 입력했습니다.\n", command);

			/*
			전화번호부가 비어있을 경우
			*/
			if (page_count == 0)
			{
				printf("수정할 전화번호부가 없습니다.\n");
				continue;
			}

			printf("수정할 수 있는 인덱스 : ");
			for (int i = 0; i < size; i++)
			{
				if (existings[i])
					printf("%d |", i);
			}
			printf("\n");
			printf("수정할 전화번호 인덱스를 입력해주세요. : ");
			scanf("%d", &index);
			if (existings[index])
			{
				printf("수정할 항목을 선택해주세요.\n1.이름\n2.전화번호\n3.기타(비고)\n");

				int choice = -1;
				scanf("%d", &choice);

				char name[100];
				char phone[100];
				char note[1000];
				switch (choice)
				{
				case 1:
					printf("100자 이내의 이름을 입력해주세요. : ");
					scanf("%s", name);
					fn_strcpy(names[index], name);
					break;
				case 2:
					printf("전화번호를 입력해주세요. : ");
					scanf("%s", phone);
					fn_strcpy(phones[index], phone);
					break;
				case 3:
					printf("기타(비고)를 입력해주세요. : ");
					scanf("%s", note);
					fn_strcpy(notes[index], note);
					break;
				default:
					printf("잘못된 값을 입력했습니다.");
					break;
				}

				printf("전화번호부가 수정되었습니다.\n");
			}
			else
			{
				printf("해당 인덱스에 전화번호부가 없습니다.\n");
			}
		}
		/**
		* 전화번호부 삭제
		*/
		else if (strcmp(command, "delete") == 0)
		{
			int index = -1;
			printf("delete 를 입력했습니다.\n");

			/*
			전화번호부가 비어있을 경우
			*/
			if (page_count == 0)
			{
				printf("삭제할 전화번호부가 없습니다.\n");
				continue;
			}

			printf("삭제할 수 있는 인덱스 : ");
			for (int i = 0; i < size; i++)
			{
				if (existings[i])
					printf("%d |", i);
			}
			printf("\n");
			printf("삭제할 전화번호 인덱스를 입력해주세요. : ");
			scanf("%d", &index);

			if (existings[index])
			{
				existings[index] = 0;
				page_count--;
			}
			else
			{
				printf("해당 인덱스에 전화번호부가 없습니다.\n");
			}

		}
		/**
		* 프로그램 종료
		*/
		else if (strcmp(command, "exit") == 0)
		{
			printf("exit 를 입력했습니다.\n");
			return 0;
		}
		/**
		* 잘못된 명령어
		*/
		else
		{
			printf("올바른 명령어를 입력하세요.\n");
		}
	}

}