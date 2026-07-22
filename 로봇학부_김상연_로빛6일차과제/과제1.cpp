#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//학년,성적,이름 지정
struct stud {
	int grade;
	double score;
	char name[20];
};

//이름 비교하는 함수 (사전순으로)
//같으면 0, a가 더 앞이면 음수, b가 더 앞이면 양수 리턴
int compare_name(const char* a, const char* b) {
	while (*a != '\0' && *a == *b) {
		a++;
		b++;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

//구조체 두개 자리 바꾸는 함수
void swap(struct stud* a, struct stud* b) {
	struct stud temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	struct stud s[5];  //학생 5명 배열
	int a, b;

	printf("입력 : \n");
	//학생 5명 정보 입력받기 
	for (a = 0;a < 5;a++) {
		scanf_s("%d %lf %s", &s[a].grade, &s[a].score, s[a].name, (unsigned)sizeof(s[a].name));
	}

	//버블정렬로 정렬
	//학년 - 성적 - 이름 순서로 비교
	for (a = 0;a < 4;a++) {
		for (b = 0;b < 4 - a;b++) {
			int swap_requirement = 0;  //바꿔야 하는지 체크하는 변수

			//학년이 다르면 학년으로 비교
			if (s[b].grade > s[b + 1].grade) {
				swap_requirement = 1;
			}
			//학년이 같으면 성적으로 비교
			else if (s[b].grade == s[b + 1].grade) {
				if (s[b].score > s[b + 1].score) {
					swap_requirement = 1;
				}
				//학년 성적 둘다 같으면 이름으로 비교
				else if (s[b].score == s[b + 1].score) {
					if (compare_name(s[b].name, s[b + 1].name) > 0)
						swap_requirement = 1;
				}
			}

			//바꿔야 하면 스왑 실행
			if (swap_requirement)
				swap(&s[b], &s[b + 1]);
		}
	}

	//정렬 끝난 결과 출력
	printf("\n출력 : \n");
	for (a = 0;a < 5;a++)
		printf("%d %.1lf %s\n", s[a].grade, s[a].score, s[a].name);

	return 0;
}