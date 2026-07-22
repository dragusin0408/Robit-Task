#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




struct thing {
	char name[20];
	int price;
};

int name_same(const char* a, const char* b) {
	while (*a != '\0' && *a == *b) {
		a++;
		b++;
	}
	if (*a == '\0' && *b == '\0')
		return 1;
	return 0;
}
int main() {
	int n, i;
	char last_name[20];//마지막 이름

	printf("입력 : ");
	scanf_s("%d", &n);

	struct thing* list = (struct thing*)malloc(n * sizeof(struct thing));

	for (i = 0;i < n;i++) {
		scanf_s("%s %d", list[i].name, (unsigned)sizeof(list[i].name), &list[i].price);
	}
	
	scanf_s("%s", last_name, (unsigned)sizeof(last_name));

	int total = 0;
	for (i = 0;i < n;i++) {
		if (name_same(list[i].name, last_name))
			total += list[i].price;
	}

	printf("\n출력 : %d\n", total);
	free(list);
	return 0;
}