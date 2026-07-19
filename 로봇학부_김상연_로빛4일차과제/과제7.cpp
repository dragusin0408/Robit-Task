#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//문자열, 위치 저장
char 열1[100];
char 열2[100];
int pos[100];
//
int sub(char s1[], char s2[]) {
    int 범위1 = strlen(s1);
    int 범위2 = strlen(s2);
    int cnt = 0;
    int i, j;

    for (i = 0; i <= 범위1 - 범위2; i++) {
        j = 0;
        while (j < 범위2 && s1[i + j] == s2[j]) { // 한 글자씩 비교
            j++;
        }
        if (j == 범위2) {
            pos[cnt] = i + 1;
            cnt++;
        }
    }

    return cnt; // 찾은 개수 반환
}

int main() {
    int n, i;

    printf("최대 99개 문자 입력 <inputStr> : ");
    scanf("%s", 열1);
    printf("찾는 문자열 <subStr> : ");
    scanf("%s", 열2);

    n = sub(열1, 열2);

    if (n == 0) {
        printf("%s가 존재하지 않습니다.\n", 열2);
    }
    else {
        for (i = 0; i < n; i++) {// 찾은 위치 전부 출력
            printf("%s의 위치 : %d\n", 열2, pos[i]);
        }
    }

    printf("계속하려면 아무 키나 누르십시오...\n");
    getchar();
    getchar();

    return 0;
}