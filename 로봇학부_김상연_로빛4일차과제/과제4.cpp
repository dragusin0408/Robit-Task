#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int 중앙값_확인(int A[], int start, int end, int B) {
    int len = end - start + 1;
    int temp[100];
    int i, j;

    for (i = 0; i < len; i++) {
        temp[i] = A[start + i];
    }

    //버블 정렬
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    if (temp[len / 2] == B) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int N, B;
    int A[100];
    int i, start, end;
    int count = 0;

    printf("N : ");
    scanf_s("%d", &N);
    printf("B : ");
    scanf_s("%d", &B);

    for (i = 0; i < N; i++) {
        scanf_s("%d", &A[i]);
    }

    //모든 부분수열 확인
    for (start = 0; start < N; start++) {
        for (end = start; end < N; end++) {
            int len = end - start + 1;
            if (len % 2 == 1) {
                count += 중앙값_확인(A, start, end, B);
            }
        }
    }

    printf("중앙값이 %d인 부분수열의 개수 : %d\n", B, count);

    return 0;
}