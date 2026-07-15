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

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            for (int j = 0; j < n - 1 - i; j++)
                printf(" ");
                printf("*");
            if (i > 0) {
                for (int j = 0; j < 2 * i - 1; j++) 
                printf(" ");
                printf("*");
            }
            printf("\n");
        }
        else {
            for (int j = 0; j < 2 * n - 1; j++) printf("*");
            printf("\n");
        }
    }

    return 0;
}