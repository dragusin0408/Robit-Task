#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("N을 입력하세요: ");
    scanf_s("%d", &n);

    //2차원 배열 동적 할당
    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
        arr[i] = (int*)malloc(sizeof(int) * n);

    int num = 1;
    // 대각선 방향으로 순회 (전체 대각선 개수는 2n-1개)
    for (int dia = 0; dia < 2 * n - 1; dia++) {
        // 대각선의 시작 행 위치 계산
        int row = (dia < n) ? 0 : (dia - n + 1);

        // 현재 대각선 상의 모든 요소에 숫자 채우기
        while (row < n && dia - row >= 0) {
            arr[row][dia - row] = num++;
            row++;
        }
    }

    //결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    //메모리 해제
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}