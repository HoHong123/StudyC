#include <stdio.h>

// 사용자 정의 memcpy 함수 정의
void my_memcpy(void *dest, const void *src, size_t size) {
    // 포인터 타입을 char 포인터로 변환하여 바이트 단위로 데이터 복사
    char *d = (char *)dest;             // 대상 메모리 영역의 포인터
    const char *s = (const char *)src;   // 소스 메모리 영역의 포인터
    
    // 데이터 크기(size)만큼 루프 실행하여 데이터를 복사
    for (size_t i = 0; i < size; i++) {
        d[i] = s[i]; // 소스 메모리의 바이트를 대상 메모리로 복사
    }
}

int main() {
    int source[5] = {1, 2, 3, 4, 5};
    int destination[5];

    size_t num_elements = sizeof(source) / sizeof(source[0]);

    // 사용자 정의 memcpy 함수로 데이터 복사
    my_memcpy(destination, source, num_elements * sizeof(int));

    // 복사된 데이터 확인
    for (size_t i = 0; i < num_elements; i++) {
        printf("%d ", destination[i]);
    }

    return 0;
}