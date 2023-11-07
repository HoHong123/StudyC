/* 전화번호 부
다음 기능을 포함한 전화번호부를 만드시오
전화번호부의 사이즈는 8로 고정합니다.
"add"를 입력하면 전화번호를 입력하는 창이 나오는데 "이름", "전화번호", "기타" 정보를 입력할 수 있습니다.
"search"를 입력하고 전화번호부의 index를 입력하면 해당 인덱스에 담겨있는 정보가 출력됩니다.
"exit"를 입력하면 종료됩니다.
*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//매크로 지정
#define MAX_CONTACTS 10
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 50

//입력될 정보를 struct에 담는다.
struct PhoneBook
{
	unsigned char name[MAX_NAME_LENGTH]; // 이름
	unsigned char number[MAX_NUMBER_LENGTH]; // 번호
	unsigned char email[MAX_EMAIL_LENGTH]; //email
};

// 전화번호 저장
struct PhoneBook books[MAX_CONTACTS];

// 전화번호 저장된 연락처 수
int contactCount = 0;

//파일 경로
char* filename = "D:\\c\\chungsik\\Project_Tasks\\PhoneBook.txt";

// passwd
const char* password = "chungsik";

void LoadPhoneBook();// Phone Info
void SavePhoneBook(); // phoneSave
int check_Passwd(); // checkPasswd
void AddNumber(); // AddPhoneNumberINFO
void PrintNumber(int index); // 특정 연락처 정보 출력
void ResetPhoneBook(); //전화번호부 리셋

int main()
{
	LoadPhoneBook(); //파일에서 연락처 정보 불러오기

	int choice;

	while (1)
	{
		printf("\n전화번호부 프로그램\n");
		printf("1. 연락처 추가\n");
		printf("2. 연락처 검색\n");
		printf("3. 전화번호부 리셋\n");
		printf("4. 저장 및 종료\n");
		printf("메뉴를 선택하시오! : ");
		scanf_s("%d", &choice);


		//Outputs the selected number to the switch statement
		switch (choice)
		{
		case 1:
			if (check_Passwd()) {
				while (1) {
					AddNumber();
					printf("계속 연락처 추가하려면 'n'을 입력하세요: ");
					char input = _getch();
					printf("\n");
					if (input != 'n') {
						break;
					}
				}
				SavePhoneBook(); // 연락처 추가 후 저장
			}
			else {
				printf("비밀번호가 틀렸습니다. 연락처 추가 X\n");
			}
			break;

		case 2:
			if (contactCount == 0) {
				printf("아무 내용 없음!\n");
			}
			else {
				for (int i = 0; i < contactCount; i++) {
					PrintNumber(i);
				}
			}
			break;

			/*printf("검색할 연락처 번호를 입력해라 (1부터 %d까지) : ", contactCount - 1);
			int index;
			scanf_s("%d", &index);

			if (index >= 0 && index < contactCount) {
				PrintNumber(index);
			}
			else
			{
				printf("잘못된 번호!\n");
			}*/
			//break;

		case 3:
			ResetPhoneBook();
			break;

		case 4:
			SavePhoneBook(); // save number info in file
			printf("프로그램 종료\n");
			return 0;

		default:
			printf("잘못된 메뉴선택 \n");
			break;
		}
	}

	return 0;
}



///<functions>////////////
// functions
// 1. Phone Info
// 2. phoneSave
// 3. checkPasswd
// 4. AddPhoneNumberINFO
// 5. 특정 연락처 정보 출력
///////////////////////////

void LoadPhoneBook()
{
	FILE* file = fopen(filename, "r"); //Open for reading only
	if (file == NULL)
	{
		return; // if nothing file
	}

	while (contactCount < MAX_CONTACTS &&
		fscanf(file, "%49s %19s %49s", books[contactCount].name, books[contactCount].number, books[contactCount].email) == 3) {
		contactCount++;
	}

	fclose(file);
}

void SavePhoneBook()
{
	FILE* file = fopen(filename, "a+b"); // Open for append (추가) 모드로 열기
	if (file == NULL)
	{
		printf("Can't open file\n");
		return;
	}

	for (int i = 0; i < contactCount; i++) {
		fprintf(file, "%s %s %s\n", books[i].name, books[i].number, books[i].email);
	}

	fclose(file);
}

int check_Passwd()
{
	char input[50];
	int i = 0;
	printf("비밀번호 입력 : ");
	while (1)
	{
		char c = _getch();

		if (c == 13) { // 대기 ASCII 13 ENTER
			input[i] = '\0';
			break;
		}
		else if (c == 8) { // Backspace ASCII8
			if (i > 0) {
				i--;
				printf("\b \b"); // 백스페이스로 삭제
			}
		}
		else {
			printf("*");
			input[i] = c;
			i++;
		}
	}

	if (strcmp(input, password) == 0) {
		printf("\n");
		return 1; // 올바른 비밀번호
	}
	else {
		printf("\n");
		return 0; // 비밀번호 불일치
	}
}


void AddNumber()
{
	if (contactCount >= MAX_CONTACTS) {
		printf("연락처 추가 불가!\n");
		return;
	}

	printf("이름 입력 : ");
	scanf_s("%49s", books[contactCount].name, MAX_NAME_LENGTH); //배열 원소갯수 리턴
	printf("번호 입력 : ");
	scanf_s("%19s", books[contactCount].number, MAX_NUMBER_LENGTH);
	printf("이메일 입력 : ");
	scanf_s("%49s", books[contactCount].email, MAX_EMAIL_LENGTH);


	contactCount++;
	printf("연락처 추가!\n");
}



void PrintNumber(int index)
{
	printf(" | 이름 : %s   | ", books[index].name);
	printf(" | 번호 : %s   | ", books[index].number);
	printf(" | 이메일 : %s | \n", books[index].email);
}

void ResetPhoneBook() {
	// 모든 연락처 정보 초기화
	for (int i = 0; i < contactCount; i++) {
		memset(books[i].name, 0, MAX_NAME_LENGTH);
		memset(books[i].number, 0, MAX_NUMBER_LENGTH);
		memset(books[i].email, 0, MAX_EMAIL_LENGTH);
	}
	contactCount = 0;
	printf("전화번호부가 리셋되었습니다.\n");

	// 파일을 다시 생성
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}
	fclose(file);
}