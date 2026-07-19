#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//제곱 ㄴㄴ수 판별 함수
int 제곱ㄴㄴ(int x) {
    int i;

    for (i = 2; i * i <= x; i++) {
        if (x % (i * i) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int min, max;
    int result[10000];
    int cnt = 0;
    int i;

    printf("min : ");
    scanf_s("%d", &min);
    printf("max : ");
    scanf_s("%d", &max);
	//제곱 ㄴㄴ수 판별
    for (i = min; i <= max; i++) {
        if (제곱ㄴㄴ(i) == 1) {
            result[cnt] = i;
            cnt++;
        }
    }
    //출력
    printf("제곱 ㄴㄴ수 : %d개\n", cnt);

    for (i = 0; i < cnt; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}