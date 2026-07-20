#include <stdio.h>

int main(void) {
    int 배열[5][5] = { 0 };  //빈칸은 0으로 채움
    int 개수 = 1;             //1로 시작

    for (int 행 = 0; 행 < 5; 행++) {
        int 차이 = 행 - 2;
        if (차이 < 0) 차이 = -차이;
        int 시작 = 2 - 차이;    //
        for (int 열 = 시작; 열 <= 4 - 시작; 열++) {
            배열[행][열] = 개수++;
        }
    }

    for (int 행 = 0; 행 < 5; 행++) {
        for (int 열 = 0; 열 < 5; 열++) {
            printf("%2d ", 배열[행][열]);
        }
        printf("\n");
    }

    return 0;
}