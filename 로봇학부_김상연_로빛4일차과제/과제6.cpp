#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int S[21];
//추가 함수
void add(int x) {
    S[x] = 1;
}
//삭제 함수
void remove_(int x) {
    S[x] = 0;
}
//확인 함수
int check(int x) {
    return S[x];
}
//토글 함수
void toggle(int x) {
    if (S[x] == 1) {
        S[x] = 0;
    }
    else {
        S[x] = 1;
    }
}
//전체 집합 
void all(void) {
    int i;
    for (i = 1; i <= 20; i++) {
        S[i] = 1;
    }
}
//공집합 
void empty(void) {
    int i;
    for (i = 1; i <= 20; i++) {
        S[i] = 0;
    }
}

void print_set(void) {
    int i;
    printf("집합 : { ");
    for (i = 1; i <= 20; i++) {
        if (S[i] == 1) {
            printf("%d, ", i);
        }
    }
    printf("}\n");
}
//집합 판별
int main() {
    char cmd[20];
    int x;

    printf("연산을 선택하세요. (1 <= x <= 20)\n");
    printf("add X\n");
    printf("remove X\n");
    printf("check X\n");
    printf("toggle X\n");
    printf("all 0\n");
    printf("empty 0\n\n");

    while (scanf("%s %d", cmd, &x) != EOF) {
        printf("input : %s %d\n", cmd, x);

        if (strcmp(cmd, "add") == 0) {
            add(x);
            print_set();
        }
        else if (strcmp(cmd, "remove") == 0) {
            remove_(x);
            print_set();
        }
        else if (strcmp(cmd, "check") == 0) {
            printf("%d\n", check(x));
        }
        else if (strcmp(cmd, "toggle") == 0) {
            toggle(x);
            print_set();
        }
        else if (strcmp(cmd, "all") == 0) {
            all();
            print_set();
        }
        else if (strcmp(cmd, "empty") == 0) {
            empty();
            print_set();
        }

        printf("\n");
    }

    return 0;
}