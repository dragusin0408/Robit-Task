#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Address {
	char country[20];
	char province[20];
	char city[20];
	char district[20];
};

struct Student {
	int num;
	char name[20];
	struct Address addr;
	int score;
};

struct Attend {
	struct Student list[MAX];
	int cnt;
};

// 출석부 초기화, 학생 수 0으로 맞춰놨다
void initAttend(struct Attend* a) {
	(*a).cnt = 0;
}

// 문자열이 전부 숫자로만 되어있는지 검사
int isAllDigit(char* str) {
	int len = strlen(str);
	if (len == 0) return 0;

	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9') return 0;
	}
	return 1;
}

// 문자열 안에 숫자가 하나라도 섞여있는지 검사 (이름, 주소용)
int hasDigit(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') return 1;
	}
	return 0;
}

// 번호 입력받는 함수, 숫자만 들어올 때까지 반복
int inputNum(void) {
	char buf[20];
	int val;

	while (1) {
		printf("번호 입력: ");
		scanf_s("%s", buf, (unsigned)sizeof(buf));

		if (isAllDigit(buf)) {
			val = atoi(buf);
			break;
		}
		printf("숫자만 입력해주세요\n");
	}

	return val;
}

// 이름 입력받는 함수, 숫자 섞이면 다시 입력받게 해뒀다
void inputName(char* name) {
	while (1) {
		printf("이름 입력: ");
		scanf_s("%s", name, 20);

		if (!hasDigit(name)) break;
		printf("이름에 숫자가 들어갈 수 없습니다\n");
	}
}

// 주소 입력받는 함수, 나라 도 시 구 순서로 하나씩 받았다
void inputAddr(struct Address* ad) {
	while (1) {
		printf("나라 입력: ");
		scanf_s("%s", (*ad).country, (unsigned)sizeof((*ad).country));
		if (!hasDigit((*ad).country)) break;
		printf("나라 이름에 숫자가 들어갈 수 없습니다\n");
	}

	while (1) {
		printf("도 입력: ");
		scanf_s("%s", (*ad).province, (unsigned)sizeof((*ad).province));
		if (!hasDigit((*ad).province)) break;
		printf("도 이름에 숫자가 들어갈 수 없습니다\n");
	}

	while (1) {
		printf("시 입력: ");
		scanf_s("%s", (*ad).city, (unsigned)sizeof((*ad).city));
		if (!hasDigit((*ad).city)) break;
		printf("시 이름에 숫자가 들어갈 수 없습니다\n");
	}

	while (1) {
		printf("구 입력: ");
		scanf_s("%s", (*ad).district, (unsigned)sizeof((*ad).district));
		if (!hasDigit((*ad).district)) break;
		printf("구 이름에 숫자가 들어갈 수 없습니다\n");
	}
}

// 성적 입력받는 함수, 숫자만 되고 0~100 사이만 통과시켰다
int inputScore(void) {
	char buf[20];
	int val;

	while (1) {
		printf("성적 입력: ");
		scanf_s("%s", buf, (unsigned)sizeof(buf));

		if (isAllDigit(buf)) {
			val = atoi(buf);
			if (val >= 0 && val <= 100) break;
			printf("성적은 0~100 사이여야 합니다\n");
		}
		else {
			printf("숫자만 입력해주세요\n");
		}
	}

	return val;
}

// 학생 한 명 정보 다 받아서 배열 맨 뒤에 추가했다
void addStudent(struct Attend* a) {
	if ((*a).cnt >= MAX) {
		printf("출석부가 가득 찼습니다\n");
		return;
	}

	struct Student s;
	s.num = inputNum();
	inputName(s.name);
	inputAddr(&s.addr);
	s.score = inputScore();

	(*a).list[(*a).cnt] = s;
	(*a).cnt++;

	printf("학생이 추가되었습니다\n");
}

// 번호, 이름, 주소, 성적 다 똑같은 학생 찾아서 지웠다, 중복이면 골라서 삭제하게 했다
void deleteStudent(struct Attend* a) {
	if ((*a).cnt == 0) {
		printf("출석부가 비어있습니다\n");
		return;
	}

	struct Student key;
	key.num = inputNum();
	inputName(key.name);
	inputAddr(&key.addr);
	key.score = inputScore();

	int idxArr[MAX];
	int found = 0;

	for (int i = 0; i < (*a).cnt; i++) {
		struct Student cur = (*a).list[i];

		if (cur.num == key.num &&
			strcmp(cur.name, key.name) == 0 &&
			strcmp(cur.addr.country, key.addr.country) == 0 &&
			strcmp(cur.addr.province, key.addr.province) == 0 &&
			strcmp(cur.addr.city, key.addr.city) == 0 &&
			strcmp(cur.addr.district, key.addr.district) == 0 &&
			cur.score == key.score) {
			idxArr[found] = i;
			found++;
		}
	}

	if (found == 0) {
		printf("일치하는 학생이 없습니다\n");
		return;
	}

	int target = idxArr[0];

	// 완전히 같은 정보가 여러 명이면 목록 보여주고 고르게 했다
	if (found > 1) {
		printf("중복된 학생이 %d명 있습니다. 지울 학생을 골라주세요\n", found);
		for (int i = 0; i < found; i++) {
			printf("%d) 배열 위치 %d\n", i + 1, idxArr[i]);
		}

		int pick;
		printf("선택: ");
		scanf_s("%d", &pick);
		pick--;

		if (pick < 0 || pick >= found) {
			printf("잘못된 선택입니다\n");
			return;
		}
		target = idxArr[pick];
	}

	for (int i = target; i < (*a).cnt - 1; i++) {
		(*a).list[i] = (*a).list[i + 1];
	}
	(*a).cnt--;

	printf("학생이 삭제되었습니다\n");
}

// 학생 한 명 정보 한 줄로 출력
void printStudent(struct Student* s) {
	printf("%d\t%s\t%s,%s,%s,%s\t%d\n",
		(*s).num, (*s).name,
		(*s).addr.country, (*s).addr.province, (*s).addr.city, (*s).addr.district,
		(*s).score);
}

// 출석부에 있는 학생 다 출력
void printAll(struct Attend* a) {
	if ((*a).cnt == 0) {
		printf("출석부가 비어있습니다\n");
		return;
	}

	for (int i = 0; i < (*a).cnt; i++) {
		printStudent(&(*a).list[i]);
	}
}

// 버블정렬로 번호순 정렬
void sortByNum(struct Attend* a) {
	int n = (*a).cnt;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if ((*a).list[j].num > (*a).list[j + 1].num) {
				struct Student tmp = (*a).list[j];
				(*a).list[j] = (*a).list[j + 1];
				(*a).list[j + 1] = tmp;
			}
		}
	}
}

// 버블정렬로 이름순 정렬
void sortByName(struct Attend* a) {
	int n = (*a).cnt;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (strcmp((*a).list[j].name, (*a).list[j + 1].name) > 0) {
				struct Student tmp = (*a).list[j];
				(*a).list[j] = (*a).list[j + 1];
				(*a).list[j + 1] = tmp;
			}
		}
	}
}

// level 값 받아서 나라(0), 도(1), 시(2), 구(3) 중 하나 기준으로 정렬해야 편하다고 생각했다.
void sortByAddr(struct Attend* a, int level) {
	int n = (*a).cnt;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			char* cur;
			char* nxtVal;

			if (level == 0) { cur = (*a).list[j].addr.country; nxtVal = (*a).list[j + 1].addr.country; }
			else if (level == 1) { cur = (*a).list[j].addr.province; nxtVal = (*a).list[j + 1].addr.province; }
			else if (level == 2) { cur = (*a).list[j].addr.city; nxtVal = (*a).list[j + 1].addr.city; }
			else { cur = (*a).list[j].addr.district; nxtVal = (*a).list[j + 1].addr.district; }

			if (strcmp(cur, nxtVal) > 0) {
				struct Student tmp = (*a).list[j];
				(*a).list[j] = (*a).list[j + 1];
				(*a).list[j + 1] = tmp;
			}
		}
	}
}

// 버블정렬로 성적순 정렬
void sortByScore(struct Attend* a) {
	int n = (*a).cnt;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if ((*a).list[j].score > (*a).list[j + 1].score) {
				struct Student tmp = (*a).list[j];
				(*a).list[j] = (*a).list[j + 1];
				(*a).list[j + 1] = tmp;
			}
		}
	}
}

// 정렬 기준 골라서 실행하고 바로 출력까지 이어지게 만들었다
void sortMenu(struct Attend* a) {
	if ((*a).cnt == 0) {
		printf("출석부가 비어있습니다\n");
		return;
	}

	printf("1) 번호순 2) 이름순 3) 주소순 4) 성적순\n");
	int sel;
	printf("선택: ");
	scanf_s("%d", &sel);

	if (sel == 1) {
		sortByNum(a);
	}
	else if (sel == 2) {
		sortByName(a);
	}
	else if (sel == 3) {
		printf("0) 나라 1) 도 2) 시 3) 구\n");
		int level;
		printf("선택: ");
		scanf_s("%d", &level);
		sortByAddr(a, level);
	}
	else if (sel == 4) {
		sortByScore(a);
	}
	else {
		printf("잘못된 선택입니다\n");
		return;
	}

	printAll(a);
}

// 번호 입력받아서 일치하는 학생 이름 다 출력
void searchByNum(struct Attend* a) {
	int key = inputNum();
	int found = 0;

	for (int i = 0; i < (*a).cnt; i++) {
		if ((*a).list[i].num == key) {
			printf("%s\n", (*a).list[i].name);
			found = 1;
		}
	}

	if (!found) printf("일치하는 학생이 없습니다\n");
}

// 주소 레벨 골라서 값 입력받고 일치하는 학생 이름 다 출력
void searchByAddr(struct Attend* a) {
	printf("0) 나라 1) 도 2) 시 3) 구\n");
	int level;
	printf("선택: ");
	scanf_s("%d", &level);

	char key[20];
	printf("값 입력: ");
	scanf_s("%s", key, (unsigned)sizeof(key));

	int found = 0;

	for (int i = 0; i < (*a).cnt; i++) {
		char* target;

		if (level == 0) target = (*a).list[i].addr.country;
		else if (level == 1) target = (*a).list[i].addr.province;
		else if (level == 2) target = (*a).list[i].addr.city;
		else target = (*a).list[i].addr.district;

		if (strcmp(target, key) == 0) {
			printf("%s\n", (*a).list[i].name);
			found = 1;
		}
	}

	if (!found) printf("일치하는 학생이 없습니다\n");
}

// 성적 입력받아서 일치하는 학생 이름 다 출력
void searchByScore(struct Attend* a) {
	int key = inputScore();
	int found = 0;

	for (int i = 0; i < (*a).cnt; i++) {
		if ((*a).list[i].score == key) {
			printf("%s\n", (*a).list[i].name);
			found = 1;
		}
	}

	if (!found) printf("일치하는 학생이 없습니다\n");
}

// 검색 기준 골라서 실행되게 이어줬다
void searchMenu(struct Attend* a) {
	if ((*a).cnt == 0) {
		printf("출석부가 비어있습니다\n");
		return;
	}

	printf("1) 번호로 찾기 2) 주소로 찾기 3) 성적으로 찾기\n");
	int sel;
	printf("선택: ");
	scanf_s("%d", &sel);

	if (sel == 1) searchByNum(a);
	else if (sel == 2) searchByAddr(a);
	else if (sel == 3) searchByScore(a);
	else printf("잘못된 선택입니다\n");
}

// 파일에 학생 정보 다 저장했다
void saveFile(struct Attend* a) {
	FILE* fp;
	errno_t err = fopen_s(&fp, "attend.txt", "w");

	if (err != 0 || fp == NULL) {
		printf("파일을 열 수 없습니다\n");
		return;
	}

	fprintf(fp, "%d\n", (*a).cnt);

	for (int i = 0; i < (*a).cnt; i++) {
		struct Student s = (*a).list[i];
		fprintf(fp, "%d %s %s %s %s %s %d\n",
			s.num, s.name,
			s.addr.country, s.addr.province, s.addr.city, s.addr.district,
			s.score);
	}

	fclose(fp);
	printf("저장되었습니다\n");
}

// 파일에서 학생 정보 다시 불러왔다
void loadFile(struct Attend* a) {
	FILE* fp;
	errno_t err = fopen_s(&fp, "attend.txt", "r");

	if (err != 0 || fp == NULL) {
		printf("저장된 파일이 없습니다\n");
		return;
	}

	int n;
	fscanf_s(fp, "%d", &n);

	(*a).cnt = 0;

	for (int i = 0; i < n; i++) {
		struct Student s;
		fscanf_s(fp, "%d %s %s %s %s %s %d",
			&s.num,
			s.name, (unsigned)sizeof(s.name),
			s.addr.country, (unsigned)sizeof(s.addr.country),
			s.addr.province, (unsigned)sizeof(s.addr.province),
			s.addr.city, (unsigned)sizeof(s.addr.city),
			s.addr.district, (unsigned)sizeof(s.addr.district),
			&s.score);

		(*a).list[(*a).cnt] = s;
		(*a).cnt++;
	}

	fclose(fp);
	printf("불러오기 완료되었습니다, 학생 %d명\n", (*a).cnt);
}

int main(void) {
	struct Attend a;
	initAttend(&a);

	int sel;

	while (1) {
		printf("\n1) 추가 2) 삭제 3) 정렬출력 4) 찾기 5) 저장 6) 불러오기 0) 종료\n");
		printf("선택: ");
		scanf_s("%d", &sel);

		if (sel == 1) addStudent(&a);
		else if (sel == 2) deleteStudent(&a);
		else if (sel == 3) sortMenu(&a);
		else if (sel == 4) searchMenu(&a);
		else if (sel == 5) saveFile(&a);
		else if (sel == 6) loadFile(&a);
		else if (sel == 0) break;
		else printf("잘못된 선택입니다\n");
	}

	return 0;
}