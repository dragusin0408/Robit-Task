#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROWS 3
#define COLS 4
#define MAX_INPUT 100  //최대 몇개까지 입력받을지

//지금까지 입력받은 숫자들로 도형 그리는 함수
//hist : 입력받은 숫자들 배열, count : 몇개 입력받았는지
void print_shape(int* hist, int count) {
	int r, c;
	for (r = 0;r < ROWS;r++) {
		for (c = 0;c < COLS;c++) {
			int idx = r * COLS + c;          //도형을 가로로 폈을때 몇번째 칸인지
			int* p = hist + (idx % count);   //포인터로 순환하면서 접근 (나머지연산으로 돌아가면서)
			printf("%d", *p);
		}
		printf("\n");
	}
}

int main() {
	int hist[MAX_INPUT];  //지금까지 입력받은 숫자들 다 저장해둠
	int count = 0;
	int input;

	printf("input : ");
	scanf_s("%d", &input);
	hist[count++] = input;
	print_shape(hist, count);

	//다음 숫자 계속 입력받으면서 도형 갱신
	//-1 입력하면 종료
	while (1) {
		printf("\nnext input : ");
		scanf_s("%d", &input);

		if (input == -1)
			break;

		hist[count++] = input;
		print_shape(hist, count);
	}

	return 0;
}