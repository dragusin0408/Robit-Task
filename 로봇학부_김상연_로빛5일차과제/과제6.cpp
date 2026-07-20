#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n1, n2;
    printf("N1 N2 입력: ");
    scanf("%d %d", &n1, &n2);

    int** arr = (int**)malloc(sizeof(int*) * n1);
    for (int i = 0; i < n1; i++)
        arr[i] = (int*)malloc(sizeof(int) * n2);

    int r1 = (n1 - 1) / 2; // 중심 행
    int r2 = (n2 - 1) / 2; // 중심 열
    int maxR = r1 + r2;

    int num = 1;
    arr[r1][r2] = num++; // 중심에 1 넣기

    for (int r = 1; r <= maxR; r++) {
        // dr+dc=u, dr-dc=v 로 바꾸면 마름모가 정사각형이 됨
        int size = 4 * r;
        int uList[4000], vList[4000];
        int cnt = 0;

        // 정사각형 테두리 4변 순서대로 저장
        for (int u = -r; u <= r - 2; u += 2) {
            uList[cnt] = u;
            vList[cnt] = r;
            cnt++;
        }
        for (int v = r; v >= -r + 2; v -= 2) {
            uList[cnt] = r;
            vList[cnt] = v;
            cnt++;
        }
        for (int u = r; u >= -r + 2; u -= 2) {
            uList[cnt] = u;
            vList[cnt] = -r;
            cnt++;
        }
        for (int v = -r; v <= r - 2; v += 2) {
            uList[cnt] = -r;
            vList[cnt] = v;
            cnt++;
        }

        // u,v를 다시 dr,dc로 변환해서 채우기
        for (int k = 0; k < size; k++) {
            int idx = (k + 1) % size;
            int u = uList[idx];
            int v = vList[idx];
            int dr = (u + v) / 2;
            int dc = (u - v) / 2;

            if (dr < -r1 || dr > r1) continue; // 범위 밖이면 스킵
            if (dc < -r2 || dc > r2) continue;

            int row = r1 + dr;
            int col = r2 + dc;
            arr[row][col] = num++;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n1; i++)
        free(arr[i]);
    free(arr);

    return 0;
}