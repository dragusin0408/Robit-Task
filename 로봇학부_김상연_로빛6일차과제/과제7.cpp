#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

typedef struct _LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

void init_list(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// 맨 앞에 노드 추가
void insert_first(LinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;

    if (list->head == NULL)
        list->tail = new_node;

    list->head = new_node;
    list->size++;
}

// 맨 뒤에 노드 추가
void insert_back(LinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// index 자리에 노드 끼워넣기
void insert_at_index(LinkedList* list, int data, int index) {
    if (index < 0 || index > list->size)
        return;

    if (index == 0) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = list->head;
        list->head = new_node;
        if (list->size == 0)
            list->tail = new_node;
        list->size++;
        return;
    }

    Node* cur = list->head;
    for (int i = 0; i < index - 1; i++)
        cur = cur->next;

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = cur->next;
    cur->next = new_node;

    if (new_node->next == NULL)
        list->tail = new_node;

    list->size++;
}

// target 값 바로 뒤에 삽입
void insert_after_data(LinkedList* list, int data, int target) {
    Node* cur = list->head;
    while (cur != NULL && cur->data != target)
        cur = cur->next;

    if (cur == NULL) {
        printf("target 값을 못찾음\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = cur->next;
    cur->next = new_node;

    if (cur == list->tail)
        list->tail = new_node;

    list->size++;
}

// 맨 앞 노드 삭제
void delete_first(LinkedList* list) {
    if (list->head == NULL)
        return;

    Node* temp = list->head;
    list->head = list->head->next;

    if (list->head == NULL)
        list->tail = NULL;

    free(temp);
    list->size--;
}

// 맨 뒤 노드 삭제
void delete_back(LinkedList* list) {
    if (list->head == NULL)
        return;

    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }

    Node* cur = list->head;
    while (cur->next != list->tail)
        cur = cur->next;

    free(list->tail);
    cur->next = NULL;
    list->tail = cur;
    list->size--;
}

// index로 삭제
void delete_at_index(LinkedList* list, int index) {
    if (index < 0 || index >= list->size)
        return;

    if (index == 0) {
        delete_first(list);
        return;
    }

    Node* cur = list->head;
    for (int i = 0; i < index - 1; i++)
        cur = cur->next;

    Node* temp = cur->next;
    cur->next = temp->next;

    if (temp == list->tail)
        list->tail = cur;

    free(temp);
    list->size--;
}

// data 값으로 찾아서 삭제 (처음 나오는 것만)
void delete_by_data(LinkedList* list, int data) {
    if (list->head == NULL)
        return;

    if (list->head->data == data) {
        delete_first(list);
        return;
    }

    Node* cur = list->head;
    while (cur->next != NULL && cur->next->data != data)
        cur = cur->next;

    if (cur->next == NULL)
        return; // 못찾음

    Node* temp = cur->next;
    cur->next = temp->next;

    if (temp == list->tail)
        list->tail = cur;

    free(temp);
    list->size--;
}

// index 주면 데이터 반환
int get_data_at_index(LinkedList* list, int index) {
    Node* cur = list->head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->data;
}

// 데이터 주면 index 반환 (없으면 -1)
int get_index_of_data(LinkedList* list, int data) {
    Node* cur = list->head;
    int idx = 0;
    while (cur != NULL) {
        if (cur->data == data)
            return idx;
        cur = cur->next;
        idx++;
    }
    return -1;
}

int get_length(LinkedList* list) {
    return list->size;
}

void print_list(LinkedList* list) {
    Node* cur = list->head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL)
            printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

// 링크 방향 뒤집기
void reverse(LinkedList* list) {
    Node* prev = NULL;
    Node* cur = list->head;
    list->tail = list->head;

    while (cur != NULL) {
        Node* next_node = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node;
    }
    list->head = prev;
}

int main(void) {
    LinkedList list;
    init_list(&list);

    insert_back(&list, 10);
    insert_back(&list, 20);
    insert_back(&list, 30);
    print_list(&list);

    insert_first(&list, 5);
    print_list(&list);

    insert_at_index(&list, 15, 2);
    print_list(&list);

    insert_after_data(&list, 17, 15);
    print_list(&list);

    printf("length = %d\n", get_length(&list));
    printf("20의 index = %d\n", get_index_of_data(&list, 20));
    printf("index 3의 data = %d\n", get_data_at_index(&list, 3));

    delete_by_data(&list, 17);
    print_list(&list);

    delete_at_index(&list, 2);
    print_list(&list);

    delete_first(&list);
    print_list(&list);

    delete_back(&list);
    print_list(&list);

    reverse(&list);
    print_list(&list);

    return 0;
}