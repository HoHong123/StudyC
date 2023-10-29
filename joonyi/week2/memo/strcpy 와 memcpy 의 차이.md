## strcpy 와 memcpy 의 차이

`strcpy()` 함수와 `memcpy()` 함수의 차이에 대해서 알아보자.

### 함수 원형의 차이

일단 제일 먼저 확인할 수 있는 차이는 두 함수의 원형이다.

```c
#include <string.h> // c
#include <cstring.h> // c++

char* strcpy(char* dest, const char* origin)
void* memcpy(void* destination, const void* source, size_t num);
```

두 함수의 원형이 다른 것을 확인할 수 있다. 특히 `strcpy()` 함수 같은 경우 복사할 크기인 `size` 를 정해줄 수 없다는 한계가 있다.

### 동작 가능한 타입의 차이

함수 원형에서 받을 수 있는 매개변수의 타입이 다르기 때문에, `strcpy` 는 오로지 `문자` 배열만 복사할 수 있는 데에 반해, `memcpy` 는 다른 자료형의 배열도 복사할 수 있다.