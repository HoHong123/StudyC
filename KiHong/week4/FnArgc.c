/*
인수를 받으면 그대로 출력하는 함수를 만드시오 (hint : argc, argv)
       ex) 하단 사진
       > test1 test2 test3 | cat -e
       > test1$
       > test2$
       > test3$
*/

#include <stdio.h>

// 실행파일 뒤에 필요한 문자들을 보낸다.
int main(int argc, char* argv[])
{
	for (int k = 0; k < argc; k++) {
		printf("%s\n", argv[k]);
	}
	return 0;
}
