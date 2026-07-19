#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//정렬된 값 출력 함수
void 정렬(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf("\t");
        }
    }
    printf("\n");
}
//정렬 함수
void sorting(int array[], int size) {
    정렬(array, size);

    for (int i = size - 1; i > 0; i--) {
        int max = 0;

        for (int j = 1; j <= i; j++) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        //최댓값을 맨 뒤로 보냄
        if (max != i) {
            int temp = array[i];
            array[i] = array[max];
            array[max] = temp;
        }
        정렬(array, size);
    }
}

int main() {
    int arr[8];

    //정수 8개 입력 받기
    for (int i = 0; i < 8; i++) {
        printf("%d : ", i);
		scanf_s("%d", &arr[i]);
    }
    sorting(arr, 8);

    printf("출력\n");
    for (int i = 0; i < 8; i++) {
        printf("%d : %d\n", i, arr[i]);
    }

    return 0;
}