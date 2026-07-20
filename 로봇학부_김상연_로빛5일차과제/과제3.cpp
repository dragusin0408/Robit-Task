#include <stdio.h>
#include <stdlib.h>

int main() {
	int n1, n2;

	printf("행 개수: ");
	scanf_s("%d", &n1);

	printf("열 개수: ");
	scanf_s("%d", &n2);

	if (n1 <= 0 || n2 <= 0) {
		printf("범위를 벗어났습니다.");
		return 1;
	}

	int** arr = (int **)malloc(n1 * sizeof(int*));
	if (arr == NULL) {
		printf("동적할당 실패");
		return 1;
	}
	for (int i = 0;i < n1;i++) {
		arr[i] = (int *)malloc(n2 * sizeof(int));
		if (arr[i] == NULL) {
			printf("동적할당 실패");
			return 1;
		}
	}
	int  up= 0, down = n1 - 1, left = 0, right = n2 - 1;
	int num = 1;
	int T = n1 * n2;//total

	while (num<= T) {
		for (int j = left; j <= right && num<= T; j++) arr[up][j] = num++;
		up++;
		for (int i = up; i <= down && num <= T; i++) arr[i][right] = num++;
		right--;
		for (int j = right; j >= left && num <= T; j--) arr[down][j] = num++;
		down--;
		for (int i = down; i >= up && num <= T; i--) arr[i][left] = num++;
		left++;
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	// 메모리 해제
	for (int i = 0; i < n1; i++) free(arr[i]);
	free(arr);

	return 0;
}