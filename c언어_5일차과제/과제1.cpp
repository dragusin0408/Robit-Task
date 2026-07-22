#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2차원 배열 출력하는 함수
void print(int* row, int* col, int** pArr) {
	for (int i = 0;i < *row;i++) {
		for (int j = 0;j < *col;j++) {
			printf("%4d", pArr[i][j]); // 4칸씩 맞춰서 출력
		}
		printf("\n");
	}
}

// 달팽이 모양으로 숫자 채우는 함수
void arr_ij(int* sizeRow, int* sizeCol, int** pArr) {
	int up = 0;
	int down = *sizeRow - 1;
	int left = 0;
	int right = *sizeCol - 1; // 상하좌우 경계 설정
	int num = 1; // 채울 숫자, 1부터 시작

	while (up <= down && left <= right) {
		// 왼쪽 -> 오른쪽 (위쪽 줄)
		for (int j = left; j <= right; j++) {
			pArr[up][j] = num;
			num++;
		}
		up++;

		// 위 -> 아래 (오른쪽 줄)
		for (int i = up; i <= down; i++) {
			pArr[i][right] = num;
			num++;
		}
		right--;

		// 오른쪽 -> 왼쪽 (아래쪽 줄)
		if (up <= down) {
			for (int j = right; j >= left; j--) {
				pArr[down][j] = num;
				num++;
			}
			down--;
		}

		// 아래 -> 위 (왼쪽 줄)
		if (left <= right) {
			for (int i = down; i >= up; i--) {
				pArr[i][left] = num;
				num++;
			}
			left++;
		}
	}
}




int main() {
	int** arr = NULL;
	int row, col, sizeRow, sizeCol;

	printf("열의 수를 입력하세요: ");
	scanf_s("%d", &sizeCol);
	printf("행의 수를 입력하세요: ");
	scanf_s("%d", &sizeRow);

	row = sizeRow;
	col = sizeCol;

	// 2차원 동적 할당 (행 개수만큼 포인터 배열 생성)
	arr = (int**)malloc(sizeof(int*) * row);

	// 각 행마다 열 개수만큼 메모리 할당
	for (int i = 0;i < row;i++) {
		arr[i] = (int*)malloc(sizeof(int) * col);
	}

	arr_ij(&sizeRow, &sizeCol, arr); // 달팽이 숫자 채우기

	print(&row, &col, arr); // 결과 출력

	// 할당한 메모리 해제 (행 하나씩 먼저 해제하고 전체 해제)
	for (int i = 0;i < row;i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}