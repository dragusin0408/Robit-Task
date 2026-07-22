#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//좌표 저장할 구조체
struct point {
	int x;
	int y;
};

//두 점 사이 거리 구하는 함수
double get_distance(struct point p1, struct point p2) {
	int distance_x = p1.x - p2.x;
	int distance_y = p1.y - p2.y;
	return sqrt((double)(distance_x * distance_x + distance_y * distance_y));
}

int main() {
	int n;
	int i, j;

	printf("입력 : ");
	scanf_s("%d", &n);

	//동적할당으로 좌표 n개 저장할 배열 만들기
	struct point* p = (struct point*)malloc(n * sizeof(struct point));

	for (i = 0;i < n;i++) {
		scanf_s("%d %d", &p[i].x, &p[i].y);
	}

	//각 좌표마다 나머지 좌표들까지의 거리 합 구하기
	double* total = (double*)malloc(n * sizeof(double));

	for (i = 0;i < n;i++) {
		total[i] = 0;
		for (j = 0;j < n;j++) {
			if (i != j)
				total[i] += get_distance(p[i], p[j]);
		}
	}

	//거리 합이 가장 큰 좌표 찾기
	int max_index = 0;
	for (i = 1;i < n;i++) {
		if (total[i] > total[max_index])
			max_index = i;
	}

	printf("\n출력 : 가장 거리가 먼 좌표는 (%d, %d)이며, 다른 좌표의 거리 총합은 약 %.1lf입니다.\n",
		p[max_index].x, p[max_index].y, total[max_index]);

	//동적할당한 메모리 해제
	free(p);
	free(total);

	return 0;
}