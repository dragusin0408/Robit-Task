#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//문장을 거꾸로 뒤집는 함수 
void re_sentence(char* s) {
	char* left = s;
	char* right = s + strlen(s) - 1;

	//개행문자 있으면 거기 빼고 시작 
	if (*right == '\n') {
		*right = '\0';
		right--;
	}

	while (left < right) {
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

//가장 많이 등장한 문자 찾는 함수 (알파벳만 세고 공백,특수문자는 제외)
char find_most_char(char* s) {
	int count[128] = { 0 };  //아스키코드별 카운트
	char* p = s;

	//문장 끝까지 포인터로 돌면서 알파벳이면 카운트 증가
	while (*p != '\0') {
		if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
			count[(unsigned char)*p]++;
		}
		p++;
	}

	//가장 많이 나온 문자 찾기
	char most = ' ';
	int max_count = 0;
	int i;
	for (i = 0;i < 128;i++) {
		if (count[i] > max_count) {
			max_count = count[i];
			most = (char)i;
		}
	}

	return most;
}

int main() {
	char sentence[100];

	printf("입력 : ");
	fgets(sentence, sizeof(sentence), stdin);
	char most = find_most_char(sentence);

	//문장 거꾸로 뒤집기
	re_sentence(sentence);

	printf("\n출력 : %s\n", sentence);
	printf("최다등장문자 : %c\n", most);

	return 0;
}