//n이 0보다 크면 ‘P’를 출력하고 0보다 작으면 ‘N’을 출력하고 0이면 ‘0’을 출력합니다
//함수 프로토 타입 void is_negative(int n);

#include <stdio.h>
int main() {
  int n;

  printf("숫자를 입력해 보세요 : ");
  scanf("%d", &n);
if (!n) {
    printf("0");
  } else if (n > 0) {
    printf("p");
  } else {
    printf("N");
  }
  return 0;
}