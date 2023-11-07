## strcpy 와 memcpy 사용 시 주의사항

해당 함수들은 **메모리에 할당된 값들에 직접 접근해서 변경**하는 함수들이다. 따라서 사용시 몇가지 `주의사항`이 있다.

##### 복사할 공간의 크기가 충분해야 한다.

복사할 공간의 크기가 중요하다. 만약 복사할 크기의 공간이 부족하다면, `memcpy()` 함수 동작시 **예상치 못한 문제**가 발생할 수 있다. 아래 코드를 보자.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char origin[] = "asdf";
    char target[2];

    printf("복사 전 origin 값 : %s\n", origin);
    printf("복사 전 origin 주소 : %p\n", origin);
    printf("복사 전 target 주소 : %p\n", target);

    memcpy(target, origin, sizeof(origin)); // 복사!

    printf("복사 후 origin 값 : %s\n", origin);
    printf("복사 후 target 값: %s\n", target);
    printf("복사 길이 : %ld\n", sizeof(origin));
    printf("복사후 origin 주소 : %p\n", origin);
    printf("복사후 target 주소 : %p\n", target);
}
```

위와 같이 `memcpy()` 함수를 실행하기 전과 후로 나누어 결과를 확인해보는 코드를 짰다.

![Alt text](<img/Pasted image 20231024135601.png>)

결과는 위와 같은데, 중요한 부분은 **밑줄 친 부분이다.** `memcpy()` 함수를 실행하고 나니 갑자기 **원본 데이터의 값이 바뀌었다!** 이는 결론만 말하자면 `target` 배열의 크기가 작기 때문이다.
주소 값을 확인해보면, `origin` 과 `target` 의 메모리 주소는 각각 `...83`, `...81` 이다. 여기서 `target` 에 `origin` 의 길이인 `5` 만큼 복사를 시도했고, `origin` 의 값인 `{a, s, d, f, \0}` 이 `target` 의 메모리 주소인 `...81` 부터 1바이트씩 차례로 들어가게 될 것이다.

| 배열                                               | 주소 | 값  |
| -------------------------------------------------- | ---- | --- |
| target                                             | 1    | a   |
| ..(target의 크기는 고작 `2` 이므로 여기서 끝난다.) | 2    | s   |
| origin                                             | 3    | d   |
| ..                                                 | 4    | f   |
| ..                                                 | 5    | \0    |

위 표를 확인해보자. 주소 `1-2` 까지는 `target` 배열이고, `3-5` 부터는 `origin` 배열이 딱 붙어있다. 이 상황에서 `memcpy()` 함수는 `target` 의 주소인 `주소 1` 부터 `origin = {a, s, d, f, \0}` 의 값을 복사하므로 `origin` 의 주소를 침범하는 문제가 발생한다!
따라서 `origin` 의 값이 `{d, f, \0}` 으로 오염되는 결과가 발생하고 만다.

##### `\0(널 문자)` 처리를 잘 해주어야 한다.

[[C언어]]의 [[문자열(C언어)]]은 마지막에 문자열의 종료를 뜻하는 `\0(널 문자)` 가 포함된다. `memcpy()` 로 문자열을 복사할 때 만약 복사할 `origin` 문자열의 크기보다 적은 개수의 문자를 복사한다면 꼭 복사할 공간에 `\0(널 문자)` 를 지정해주는 것이 필요하다.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char origin[] = "asdf";
    char target[2];

    printf("복사 전 origin 값 : %s\n", origin);
    printf("복사 전 origin 주소 : %p\n", origin);
    printf("복사 전 target 주소 : %p\n", target);

    memcpy(target, origin, 2); // 복사!

    printf("복사 후 origin 값 : %s\n", origin);
    printf("복사 후 target 값: %s\n", target);
    printf("복사 길이 : %ld\n", sizeof(origin));
    printf("복사후 origin 주소 : %p\n", origin);
    printf("복사후 target 주소 : %p\n", target);
}
```

위 코드는 `target` 의 크기인 `2` 만큼 `origin` 을 복사하는 코드인데, 예상 값은 `target` 값으로 `"as"` 가 출력되는 것이다. 위 코드의 결과는 아래와 같다.

![Alt text](<img/Pasted image 20231024140740.png>)

잘 보면 복사하고 난 후 `target` 의 값이 예상과 다르게 `"asasdf"` 로 출력되는 것을 볼 수 있다. 이는 `\0(널 문자)` 의 부재로 인해 발생한 결과이다. 현재 메모리는 아래 표와 같다고 말할 수 있다.

| 배열                  | 주소 | 값  |
| --------------------- | ---- | --- |
| target                | 1    | a   |
| ..(위와 같음)                   | 2    | s   |
| target & origin(혼재) | 3    | a   |
| ..(위와 같음)           | 4    | s   |
| ..(위와 같음)          | 5    | d   |
| ..(위와 같음)          | 6    | f   |
| ..(위와 같음)          | 7    | \0  |

표에서 `주소 3` 이후 `target` 과 `origin` 이 혼재된다. 즉 `3` 주소부턴 `origin` 도 가리키고, `target` 도 가리키는 영역이 된다. 그 후에 `\0(널 문자)` 를 만나면 문자열이 끝나게 된다.
이런 상황이 발생한 이유는 `target` 에 `\0(널 문자)` 를 복사해주지 않았기 때문이다. 여기서는 `origin` 의 맨 처음 `2 글자` 만 `target` 에 복사하였으므로, 널 문자를 포함하지 않은 `'as'` 값만 복사해줬기 때문에 문자열이 `'as'` 에서 끝난 줄 모르고 계속 문자열의 끝인 `널 문자` 를 탐색하게 되어 널문자를 만나는 곳인 `7번 주소` 에서 끝이 나는 것이다.
