#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("몇 개의 원소를 할당하겠습니까? : ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("범위를 벗어났습니다.");
		return 1;
	}
	//동적배열활용
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0;i < n;i++) {
		printf("정수형 데이터 입력:");
		scanf_s("%d", &arr[i]);
	}
	
	int max = arr[0];
	int min = arr[0];
	int sum = 0;

//최대최소 판별
	for (int i = 0;i < n;i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		sum += arr[i];
	}

	double avr = (double)sum / n;

	printf("최대값: %d\n", max);
	printf("최소값: %d\n", min);
	printf("전체합: %d\n", sum);
	printf("평균: %f\n", avr);

	free(arr);
	return 0;
}