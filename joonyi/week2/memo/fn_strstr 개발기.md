## 3. (bonus) strstr과 똑같이 동작하는 fn_strstr을 만들어라

### strstr

`strstr()` 함수는 문자열 내에 특정 문자열이 존재하는지 찾는 함수다. 함수 원형은 아래와 같다.

```c
#include <string.h>
char *strstr(const char *string1, const char *string2);
```

`string1` 에서 `string2` 가 시작하는 지점의 주소를 반환한다. `문자열` 을 찾을 때 `string2` 의 `널 문자(\0)` 은 무시하고 찾는다. 만약 `string2` 가 길이가 `0` 인 문자열을 가리킨다면, `string1` 을 리턴한다.

`string2` 가 `string1` 에 나타나지 않는다면 `NULL` 을 리턴한다고 `IBM` 에서 말하는데, 실제로 `strstr()` 동작을 확인해보면 `string1` 주소를 리턴한다. 따라서 여기선 `string1` 의 주소를 리턴하도록 할 것이다.

추가) `strstr()` 동작을 다시 확인해보니 `string2` 를 `string1` 에서 찾을 수 없다면 정말 `NULL` 을 리턴했다. 내가 잘못 확인한 것 같다.

### 구현

```c hl:6-8,38
#include <string.h>
#include <stdio.h>

char* fn_strstr(const char* string1, const char* string2)
{
	if (string1 == NULL || string2 == NULL) {
		return NULL; // If either of the strings is NULL, return NULL
	} // 나중에 보완을 위해 추가한(수정한) 부분

	int first_index = 0;
	int found_index = 0;
	char* found_ptr = (char*)string1;
	while (*(string1 + first_index) != '\0')
	{
		int second_index = 0;
		int is_found = 1;
		while (*(string2 + second_index) != '\0')
		{
			char first_character = *(string1 + first_index + second_index);
			char second_character = *(string2 + second_index);
			if (first_character != second_character) {
				is_found = 0;
				break;
			}

			second_index++;
		}

		if (is_found)
		{
			found_ptr = (char*)(string1 + first_index);

			return found_ptr;
		}
		first_index++;
	}

	return NULL; // 나중에 보완을 위해 추가한(수정한) 부분

}

int main(void)
{
	//char string1[] = "needle in a haystack";
	//char string2[] = "haystack";

	//char string1[] = "test";
	//char string2[] = "";

	//char string1[] = "1234";
	//char string2[] = "23";

	char string1[] = "needle in a haystack asdf";
	char string2[] = "haystack";


	printf("original pointers (string1, string2)--------------\n");
	printf("string1 : %p\n", string1);
	printf("string2 : %p\n", string2);
	printf("fn_strstr --------------\n");
	char* result;
	result = fn_strstr(string1, string2);

	/* Result = a pointer to "haystack" */
	printf("fn_strstr value : %s\n", result);
	printf("fn_strstr pointer : %p\n", result);

	printf("strstr -------------\n");

	char* result2;

	result2 = strstr(string1, string2);
	printf("strstr value : %s\n", result2);
	printf("strstr pointer : %p\n", result2);
}
```

문자열 검색에 있어서 `보이어 무어(Boyer - Moore)` 알고리즘이 있다고 하는데, 일단 과제는 보이어 무어 알고리즘 구현이 아니라 `strstr()` 구현이기 때문에 여기선 무식하게 $O(N^2)$ `시간복잡도` 로 구현했다.

#### 보완할 점

1. 동작이 올바르지 않았다. 내가 착각했는지 `strstr()` 함수에서 문자열을 못 찾았을 경우 원래 `NULL` 을 반환하는데, 나는 `string1` 을 반환하고 있었다. 따라서 문자열을 못 찾았을 경우 `NULL` 을 반환하도록 수정했다.
2. 함수의 인자로 `NULL` 이 왔을 때는 어떻게 처리할 것인가? 보완해야 한다. 따라서 `6-8` 번 줄에서 `NULL` 이 올 경우 `NULL` 을 반환하도록 했다.