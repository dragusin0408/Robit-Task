#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* nxt;
	int data;
};

struct Queue {
	int cnt;
	struct Node* front;
	struct Node* rear;
};

// 큐가 비어있는지 확인
int isEmpty(struct Queue* q) {
	if ((*q).cnt == 0) return 1;
	return 0;
}

// front, rear, cnt 다 NULL이랑 0으로 초기화
void initQueue(struct Queue* q) {
	(*q).cnt = 0;
	(*q).front = NULL;
	(*q).rear = NULL;
}

// rear 쪽에 새 노드 붙이는 방식으로 enqueue 구현
void enqueue(struct Queue* q, int val) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	(*n).nxt = NULL;
	(*n).data = val;

	// 큐가 비어있으면 front, rear 둘 다 새 노드로 잡아줌
	if (!isEmpty(q)) {
		(*(*q).rear).nxt = n;
		(*q).rear = n;
	}
	else {
		(*q).front = n;
		(*q).rear = n;
	}

	(*q).cnt++;
}

// front 쪽에서 하나 빼서 출력 비어있으면 메시지만 띄워줬다.
void dequeue(struct Queue* q) {
	if (isEmpty(q)) {
		printf("queue가 비어있습니다\n");
		return;
	}

	struct Node* del = (*q).front;
	int val = (*del).data;

	(*q).front = (*del).nxt;
	(*q).cnt--;

	// 마지막 하나 빼면 rear도 같이 NULL로 만들어줘야함
	if ((*q).front == NULL) {
		(*q).rear = NULL;
	}

	free(del);

	printf("%d\n", val);
}

// front 값만 살짝 확인하는 용도
int getFront(struct Queue* q) {
	if (isEmpty(q)) {
		printf("queue가 비어있습니다\n");
		return -1;
	}
	return (*(*q).front).data;
}

// rear 값만 살짝 확인하는 용도
int getRear(struct Queue* q) {
	if (isEmpty(q)) {
		printf("queue가 비어있습니다\n");
		return -1;
	}
	return (*(*q).rear).data;
}

// 현재 몇 개 들어있는지 반환
int getSize(struct Queue* q) {
	return (*q).cnt;
}

// front부터 순서대로 다 훑으면서 출력
void printQueue(struct Queue* q) {
	if (isEmpty(q)) {
		printf("queue가 비어있습니다\n");
		return;
	}

	struct Node* p = (*q).front;
	while (p != NULL) {
		printf("%d ", (*p).data);
		p = (*p).nxt;
	}
	printf("\n");
}

int main(void) {
	struct Queue q;
	initQueue(&q);

	// 테스트용으로 1, 2, 3 순서대로 넣어봄
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printQueue(&q);
	printf("front: %d\n", getFront(&q));
	printf("rear: %d\n", getRear(&q));
	printf("size: %d\n", getSize(&q));

	// 하나 빼고 나서 잘 빠졌는지 다시 출력해서 확인
	dequeue(&q);
	printQueue(&q);

	return 0;
}