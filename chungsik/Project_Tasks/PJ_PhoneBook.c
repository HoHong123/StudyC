/* ��ȭ��ȣ ��
���� ����� ������ ��ȭ��ȣ�θ� ����ÿ�
��ȭ��ȣ���� ������� 8�� �����մϴ�.
"add"�� �Է��ϸ� ��ȭ��ȣ�� �Է��ϴ� â�� �����µ� "�̸�", "��ȭ��ȣ", "��Ÿ" ������ �Է��� �� �ֽ��ϴ�.
"search"�� �Է��ϰ� ��ȭ��ȣ���� index�� �Է��ϸ� �ش� �ε����� ����ִ� ������ ��µ˴ϴ�.
"exit"�� �Է��ϸ� ����˴ϴ�.
*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//��ũ�� ����
#define MAX_CONTACTS 10
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 50

//�Էµ� ������ struct�� ��´�.
struct PhoneBook
{
	unsigned char name[MAX_NAME_LENGTH]; // �̸�
	unsigned char number[MAX_NUMBER_LENGTH]; // ��ȣ
	unsigned char email[MAX_EMAIL_LENGTH]; //email
};

// ��ȭ��ȣ ����
struct PhoneBook books[MAX_CONTACTS];

// ��ȭ��ȣ ����� ����ó ��
int contactCount = 0;

//���� ���
char* filename = "D:\\c\\chungsik\\Project_Tasks\\PhoneBook.txt";

// passwd
const char* password = "chungsik";

void LoadPhoneBook();// Phone Info
void SavePhoneBook(); // phoneSave
int check_Passwd(); // checkPasswd
void AddNumber(); // AddPhoneNumberINFO
void PrintNumber(int index); // Ư�� ����ó ���� ���
void ResetPhoneBook(); //��ȭ��ȣ�� ����

int main()
{
	LoadPhoneBook(); //���Ͽ��� ����ó ���� �ҷ�����

	int choice;

	while (1)
	{
		printf("\n��ȭ��ȣ�� ���α׷�\n");
		printf("1. ����ó �߰�\n");
		printf("2. ����ó �˻�\n");
		printf("3. ��ȭ��ȣ�� ����\n");
		printf("4. ���� �� ����\n");
		printf("�޴��� �����Ͻÿ�! : ");
		scanf_s("%d", &choice);


		//Outputs the selected number to the switch statement
		switch (choice)
		{
		case 1:
			if (check_Passwd()) {
				while (1) {
					AddNumber();
					printf("��� ����ó �߰��Ϸ��� 'n'�� �Է��ϼ���: ");
					char input = _getch();
					printf("\n");
					if (input != 'n') {
						break;
					}
				}
				SavePhoneBook(); // ����ó �߰� �� ����
			}
			else {
				printf("��й�ȣ�� Ʋ�Ƚ��ϴ�. ����ó �߰� X\n");
			}
			break;

		case 2:
			if (contactCount == 0) {
				printf("�ƹ� ���� ����!\n");
			}
			else {
				for (int i = 0; i < contactCount; i++) {
					PrintNumber(i);
				}
			}
			break;

			/*printf("�˻��� ����ó ��ȣ�� �Է��ض� (1���� %d����) : ", contactCount - 1);
			int index;
			scanf_s("%d", &index);

			if (index >= 0 && index < contactCount) {
				PrintNumber(index);
			}
			else
			{
				printf("�߸��� ��ȣ!\n");
			}*/
			//break;

		case 3:
			ResetPhoneBook();
			break;

		case 4:
			SavePhoneBook(); // save number info in file
			printf("���α׷� ����\n");
			return 0;

		default:
			printf("�߸��� �޴����� \n");
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
// 5. Ư�� ����ó ���� ���
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
	FILE* file = fopen(filename, "a+b"); // Open for append (�߰�) ���� ����
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
	printf("��й�ȣ �Է� : ");
	while (1)
	{
		char c = _getch();

		if (c == 13) { // ��� ASCII 13 ENTER
			input[i] = '\0';
			break;
		}
		else if (c == 8) { // Backspace ASCII8
			if (i > 0) {
				i--;
				printf("\b \b"); // �齺���̽��� ����
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
		return 1; // �ùٸ� ��й�ȣ
	}
	else {
		printf("\n");
		return 0; // ��й�ȣ ����ġ
	}
}


void AddNumber()
{
	if (contactCount >= MAX_CONTACTS) {
		printf("����ó �߰� �Ұ�!\n");
		return;
	}

	printf("�̸� �Է� : ");
	scanf_s("%49s", books[contactCount].name, MAX_NAME_LENGTH); //�迭 ���Ұ��� ����
	printf("��ȣ �Է� : ");
	scanf_s("%19s", books[contactCount].number, MAX_NUMBER_LENGTH);
	printf("�̸��� �Է� : ");
	scanf_s("%49s", books[contactCount].email, MAX_EMAIL_LENGTH);


	contactCount++;
	printf("����ó �߰�!\n");
}



void PrintNumber(int index)
{
	printf(" | �̸� : %s   | ", books[index].name);
	printf(" | ��ȣ : %s   | ", books[index].number);
	printf(" | �̸��� : %s | \n", books[index].email);
}

void ResetPhoneBook() {
	// ��� ����ó ���� �ʱ�ȭ
	for (int i = 0; i < contactCount; i++) {
		memset(books[i].name, 0, MAX_NAME_LENGTH);
		memset(books[i].number, 0, MAX_NUMBER_LENGTH);
		memset(books[i].email, 0, MAX_EMAIL_LENGTH);
	}
	contactCount = 0;
	printf("��ȭ��ȣ�ΰ� ���µǾ����ϴ�.\n");

	// ������ �ٽ� ����
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return;
	}
	fclose(file);
}