#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//별세는 함수
void counting_stars(int size, int type) {
    if (size <= 0 || type < 1 || type > 4) {
        printf("범위를 벗어났습니다.\n");
        return;
    }

    int 가운데 = size / 2;

    for (int i = 0; i < size; i++) {
        int 별 = 0;
        int 공백 = 0;

        int distance;
        if (i <= 가운데) {
            distance = i;
        }
        else {
            distance = size - 1 - i;
        }

        if (type == 1) {
            별 = distance + 1;
            공백 = 0;
        }
        else if (type == 2) {
            별 = distance + 1;
            공백 = 가운데 - distance;
        }
        else if (type == 3) {
            int edge= 가운데 - distance;
            별 = edge * 2 + 1;
            공백 = distance;
        }
        else if (type == 4) {
            int edge_dist = 가운데 - distance;
            별 = edge_dist + 1;
            공백 = distance;
        }

        for (int j = 0; j < 공백; j++) {
            printf(" ");
        }
        for (int j = 0; j < 별; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int size = 0;
    int type = 0;

    printf("사이즈와 종류를 입력하시오. ");
    scanf_s("%d %d", &size, &type);
        
    counting_stars(size, type);
    
    return 0;
}