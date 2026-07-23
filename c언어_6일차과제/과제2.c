#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* nxt;
};

struct Stack {
	struct Node* top;
	int cnt;
};

// 처음 스택 만들 때 top이랑 cnt 0으로 세팅해서 빈 상태로 만들어놓음.
void initStack(struct Stack* s) {
	(*s).top = NULL;
	(*s).cnt = 0;
}

// cnt가 0이면 비어있는 거라서 그걸로 판단
int isEmpty(struct Stack* s) {
	if ((*s).cnt == 0) return 1;
	return 0;
}

// 새 노드 만들어서 기존 top을 가리키게 하고 그 자리에 꽂아넣었다
void push(struct Stack* s, int val) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	(*n).data = val;
	(*n).nxt = (*s).top;
	(*s).top = n;
	(*s).cnt++;
}

// 비어있으면 그냥 메시지만 띄우고, 아니면 top꺼 빼서 출력
void pop(struct Stack* s) {
	if (isEmpty(s)) {
		printf("스택이 비어있습니다\n");
		return;
	}

	struct Node* del = (*s).top;
	int val = (*del).data;

	(*s).top = (*del).nxt;
	free(del);
	(*s).cnt--;

	printf("%d\n", val);
}
// cnt 값 그대로 돌려주면 됨
int getSize(struct Stack* s) {
	return (*s).cnt;
}

// 비어있는지 먼저 체크하고 top 데이터만 반환하게 했다
int getTop(struct Stack* s) {
	if (isEmpty(s)) {
		printf("스택이 비어있습니다\n");
		return -1;
	}
	return (*(*s).top).data;
}

// top부터 시작해서 nxt 따라가며 끝까지 다 출력하게 만들었다
void printStack(struct Stack* s) {
	if (isEmpty(s)) {
		printf("스택이 비어있습니다\n");
		return;
	}

	struct Node* p = (*s).top;
	while (p != NULL) {
		printf("%d ", (*p).data);
		p = (*p).nxt;
	}
	printf("\n");
}

int main(void) {
	struct Stack st;
	initStack(&st);

	// 테스트해보려고 1, 2, 3 순서대로 넣음
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);

	printStack(&st);
	printf("size: %d\n", getSize(&st));
	printf("top: %d\n", getTop(&st));

	// 하나 빼고 나서 잘 빠졌는지 확인하려고 다시 출력해봤다
	pop(&st);
	printStack(&st);

	return 0;
}