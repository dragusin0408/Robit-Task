#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;
    printf("값을 입력하세요. ");
    scanf("%d", &n);

    if (n < 1) {
        printf("범위를 벗어남\n");
        return 0;
    }
    printf("\n");
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            printf("*");
        }
        for (int k = 2 * (n - i); k > 0; k--) {
            printf(" ");
        }
        for (int j = i; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }

    for (int j = 0; j < n; j++) {
        printf("*");
    }
    for (int j = 0; j < n; j++) {
        printf("*");
    }
    printf("\n");
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        int space = 2 * (n - i);
        for (int k = 0; k < space; k++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}