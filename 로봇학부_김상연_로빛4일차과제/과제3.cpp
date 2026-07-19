#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int 음계(char note) {
    switch (note) {
    case 'c': return 1;
    case 'd': return 2;
    case 'e': return 3;
    case 'f': return 4;
    case 'g': return 5;
    case 'a': return 6;
    case 'b': return 7;
    case 'C': return 8;
    default: return 0;
    }
}

int 음계_판정(char melody[]) {
    int ascending = 0;
    int descending = 0;
    int scores[8];

    for (int i = 0; i < 8; i++) {
        scores[i] = 음계(melody[i]);
    }

    //음계 비교
    for (int i = 0; i < 7; i++) {
        if (scores[i] < scores[i + 1]) {
            ascending++;
        }
        else if (scores[i] > scores[i + 1]) {
            descending++;
        }
    }

    if (ascending == 7) {
        return 1;
    }
    else if (descending == 7) {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    char melody[9];
    printf("음 입력\n");

    scanf("%s", melody);

    int result = 음계_판정(melody);

    printf("\n결과 : ");\
    //switvh문을 통한 결과 출력
    switch (result) {
    case 1:
        printf("ascending\n");
        break;
    case 2:
        printf("descending\n");
        break;
    case 3:
        printf("mixed\n");
        break;
    default:
        printf("error\n");
        break;
    }

    return 0;
}