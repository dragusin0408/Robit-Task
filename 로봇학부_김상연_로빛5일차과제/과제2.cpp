#include <stdio.h>
#include <stdlib.h>

int main() {
	int 배열a[4][3];
	int 배열b[3][4];
	int num = 1;

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			배열a[i][j] = num++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			배열b[j][i] = 배열a[i][j];
		}
	}

	printf("배열A\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", 배열a[i][j]);
		}
		printf("\n");
	}

	printf("배열B\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", 배열b[i][j]);
		}
		printf("\n");
	}
}