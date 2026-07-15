#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;
    printf("n번째 피보나치 수를 구합니다. n=");
    scanf("%d", &n);
    if (n < 1 || n > 92) {
        printf("범위를 벗어났습니다.\n");
        return 0;
    }
    
    long long a = 1, b = 0, c = 0; 

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            c = b;
        }
        else {
            c = a + b;
            a = b;
            b = c;
        }
    }
    printf("%d번째 피보나치 수는 %lld입니다.\n", n, c);
    return 0;
}