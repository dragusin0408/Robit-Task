#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[1000];
    printf("HTML 입력: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = 0;
        len--;
    }

    // 스택 (동적할당)
    char** stk = (char**)malloc(sizeof(char*) * 100);
    for (int i = 0; i < 100; i++)
        stk[i] = (char*)malloc(20);
    int top = -1;
    int dep = 0; // 들여쓰기 깊이
    int err = 0;

    int i = 0;
    while (i < len) {
        if (str[i] == '<') {
            // 태그 부분 잘라내기
            int j = i + 1;
            while (str[j] != '>') j++;

            char tag[20];
            strncpy(tag, str + i + 1, j - i - 1);
            tag[j - i - 1] = 0;

            if (tag[0] == '/') {
                // 닫는 태그면 스택 맨 위랑 비교
                if (top == -1) {
                    printf("에러: 태그 짝이 안맞음\n");
                    err = 1;
                    break;
                }
                if (strcmp(stk[top], tag + 1) != 0) {
                    printf("에러: 태그 순서 이상함\n");
                    err = 1;
                    break;
                }
                top--;
                dep--;
                for (int k = 0; k < dep; k++) printf("  ");
                printf("</%s>\n", tag + 1);
            }
            else {
                // 여는 태그면 push
                for (int k = 0; k < dep; k++) printf("  ");
                printf("<%s>\n", tag);
                top++;
                strcpy(stk[top], tag);
                dep++;
            }
            i = j + 1;
        }
        else {
            // 태그 사이 글자들
            int j = i;
            while (j < len && str[j] != '<') j++;
            if (j - i > 0) {
                char txt[500];
                strncpy(txt, str + i, j - i);
                txt[j - i] = 0;
                for (int k = 0; k < dep; k++) printf("  ");
                printf("%s\n", txt);
            }
            i = j;
        }
    }

    if (!err && top != -1)
        printf("에러: 안닫힌 태그 있음\n");

    for (int i = 0; i < 100; i++) free(stk[i]);
    free(stk);
    return 0;
}