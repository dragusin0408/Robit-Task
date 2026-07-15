#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    printf("a과 b을 입력하세요: ");
    scanf("%d %d", &a, &b);

    if (a < 1 || b < 0 || a < b) {
        printf("범위를 벗어남\n");
        return 0;
    }

    long long 팩토리얼 = 1;
    for (int i = a; i >= 1; i--) {
        팩토리얼 *= i;
    }

    long long 팩토리얼1 = 1;
    for (int i = (a - b); i >= 1; i--) {
        팩토리얼1 *= i;
    }

    long long 팩토리얼2 = 1;
    for (int i = b; i >= 1; i--) {
        팩토리얼2 *= i;
    }

    long long 결과 = 팩토리얼 / 팩토리얼1;
    printf("순열: %lld\n", 결과);

    long long 결과2 = 1;
    for (int i = b; i > 0; i--) {
        결과2 *= a;
    }
    printf("중복순열: %lld\n", 결과2);

    long long 결과3 = 팩토리얼 / (팩토리얼1 * 팩토리얼2);
    printf("조합: %lld\n", 결과3);

    int 중복조합 = a + b - 1;
    long long 팩토리얼4 = 1;
    for (int i = 중복조합; i >= 1; i--) {
        팩토리얼4 *= i;
    }
    long long 팩토리얼5 = 1;
    for (int i = (중복조합 - b); i >= 1; i--) {
        팩토리얼5 *= i;
    }
    long long 결과4 = 팩토리얼4 / (팩토리얼5 * 팩토리얼2);
    printf("중복조합: %lld\n", 결과4);

    return 0;
}