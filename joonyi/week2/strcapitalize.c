#include <stdio.h>

/*
- input) `salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un`
- output) `Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un`
- `char *strcapitalize(char *str)`
*/

/*
* 각 단어의 첫 글자를 대문자로 바꾸는 함수
* 인풋 값과 아웃풋 값을 비교했을 때
* 아마도 ASCII 값에서 알파벳이 아닌 애들을 단어 구분 기호로 삼는것 같아 보임
* +나 -와 같은 기호가 등장해도 다음 영문자를 대문자로 바꿔주는 것을 볼 수 있음.
*/

/*
* 문자열의 길이를 구하는 함수
*/
int get_length(char* str)
{
	int length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}

	return length + 1; // null 문자까지 길이로 셈
}

/*
* strcapitalize()
* 알파벳이 아닌 모든 기호를 단어 구분 기호로 하여 단어의 첫 글자를 모두 대문자로 바꿔주는 함수
* Abcd 를 ABcd 로 안 바꾸도록 주의.
*/
char* strcapitalize(char* str)
{
	int length = get_length(str); // 순회할 문자열의 길이
	int is_new_word = 1; // 새 단어인지 확인
	for (int i = 0; i < length; i++)
	{
		// 문자열의 각 문자
		char character = *(str + i);

		// 대문자, 소문자 판단
		int is_undercase_alph = ('a' <= character && character <= 'z');
		int is_uppercase_alph = ('A' <= character && character <= 'Z');
		int is_alphabet = is_undercase_alph || is_uppercase_alph;

		// 알파벳이고, 새 단어일 경우에만 대문자로 변경
		if (is_alphabet)
		{
			if (is_undercase_alph && is_new_word)
			{
				*(str + i) = 'A' + (character - 'a');
			}
			is_new_word = 0;
		}
		// 알파벳이 아닌 경우 단어 구분기호이므로, 새 단어가 나온다고 명시한다.
		else {
			is_new_word = 1;
		}
	}

	return str;
}

int main()
{
	char input[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
//	char input[] = "asdf"; // 테스트용 인풋

	strcapitalize(input);

	printf("%s", strcapitalize(input)); // 여러번 함수를 적용해도 똑같은 결과를 낼 수 있도록! Asdf를 함수 적용해도 Asdf가 된다.
}