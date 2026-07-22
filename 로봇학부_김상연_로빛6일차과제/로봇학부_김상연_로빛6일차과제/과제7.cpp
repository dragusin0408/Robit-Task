#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
    Node* cur;
    int size;
};

void init_list(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->size = 0;
}

// 맨 앞에 노드 추가
void insert_first(LinkedList* list, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = list->head;

    if (list->head == NULL)
        list->tail = new_node;

    list->head = new_node;
    list->size++;
}

// 맨 뒤에 노드 추가
void insert_back(LinkedList* list, int data) {
    Node* new_node = new Node;
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
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = list->head;
        list->head = new_node;
        if (list->size == 0)
            list->tail = new_node;
        list->size++;
        return;
    }

    list->cur = list->head;
    for (int i = 0; i < index - 1; i++)
        list->cur = list->cur->next;

    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = list->cur->next;
    list->cur->next = new_node;

    if (new_node->next == NULL)
        list->tail = new_node;

    list->size++;
}

// target 값 바로 뒤에 삽입
void insert_after_data(LinkedList* list, int data, int target) {
    list->cur = list->head;
    while (list->cur != NULL && list->cur->data != target)
        list->cur = list->cur->next;

    if (list->cur == NULL) {
        printf("target 값을 못찾음\n");
        return;
    }

    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = list->cur->next;
    list->cur->next = new_node;

    if (list->cur == list->tail)
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

    delete temp;
    list->size--;
}

// 맨 뒤 노드 삭제
void delete_back(LinkedList* list) {
    if (list->head == NULL)
        return;

    if (list->head == list->tail) {
        delete list->head;
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }

    list->cur = list->head;
    while (list->cur->next != list->tail)
        list->cur = list->cur->next;

    delete list->tail;
    list->cur->next = NULL;
    list->tail = list->cur;
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

    list->cur = list->head;
    for (int i = 0; i < index - 1; i++)
        list->cur = list->cur->next;

    Node* temp = list->cur->next;
    list->cur->next = temp->next;

    if (temp == list->tail)
        list->tail = list->cur;

    delete temp;
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

    list->cur = list->head;
    while (list->cur->next != NULL && list->cur->next->data != data)
        list->cur = list->cur->next;

    if (list->cur->next == NULL) {
        printf("못찾음\n");
        return;
    }

    Node* temp = list->cur->next;
    list->cur->next = temp->next;

    if (temp == list->tail)
        list->tail = list->cur;

    delete temp;
    list->size--;
}

// index 주면 데이터 반환
int get_data_at_index(LinkedList* list, int index) {
    list->cur = list->head;
    for (int i = 0; i < index; i++)
        list->cur = list->cur->next;
    return list->cur->data;
}

// 데이터 주면 index 반환 (없으면 -1)
int get_index_of_data(LinkedList* list, int data) {
    list->cur = list->head;
    int idx = 0;
    while (list->cur != NULL) {
        if (list->cur->data == data)
            return idx;
        list->cur = list->cur->next;
        idx++;
    }
    return -1;
}

int get_length(LinkedList* list) {
    return list->size;
}

void print_list(LinkedList* list) {
    list->cur = list->head;
    while (list->cur != NULL) {
        printf("%d", list->cur->data);
        if (list->cur->next != NULL)
            printf(" -> ");
        list->cur = list->cur->next;
    }
    printf("\n");
}

// 링크 방향 뒤집기
void reverse(LinkedList* list) {
    Node* prev = NULL;
    list->cur = list->head;
    list->tail = list->head;

    while (list->cur != NULL) {
        Node* next_node = list->cur->next;
        list->cur->next = prev;
        prev = list->cur;
        list->cur = next_node;
    }
    list->head = prev;
}

void print_menu() {
    printf("1. insert_first\n");
    printf("2. insert_back\n");
    printf("3. insert_at_index\n");
    printf("4. insert_after_data\n");
    printf("5. delete_first\n");
    printf("6. delete_back\n");
    printf("7. delete_at_index\n");
    printf("8. delete_by_data\n");
    printf("9. get_data_at_index\n");
    printf("10. get_index_of_data\n");
    printf("11. get_length\n");
    printf("12. print_list\n");
    printf("13. reverse\n");
    printf("0. 종료\n");
}

int main() {
    LinkedList list;
    init_list(&list);

    int choice;
    int data, index, target;

    while (true) {
        print_menu();
        scanf_s("%d", &choice);

        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            printf("추가할 값: ");
            scanf_s("%d", &data);
            insert_first(&list, data);
        }
        else if (choice == 2) {
            printf("추가할 값: ");
            scanf_s("%d", &data);
            insert_back(&list, data);
        }
        else if (choice == 3) {
            printf("추가할 값, index: ");
            scanf_s("%d %d", &data, &index);
            insert_at_index(&list, data, index);
        }
        else if (choice == 4) {
            printf("추가할 값, 그 앞에 올 data: ");
            scanf_s("%d %d", &data, &target);
            insert_after_data(&list, data, target);
        }
        else if (choice == 5) {
            delete_first(&list);
        }
        else if (choice == 6) {
            delete_back(&list);
        }
        else if (choice == 7) {
            printf("삭제할 index: ");
            scanf_s("%d", &index);
            delete_at_index(&list, index);
        }
        else if (choice == 8) {
            printf("삭제할 data: ");
            scanf_s("%d", &data);
            delete_by_data(&list, data);
        }
        else if (choice == 9) {
            printf("index 입력: ");
            scanf_s("%d", &index);
            printf("결과: %d\n", get_data_at_index(&list, index));
        }
        else if (choice == 10) {
            printf("data 입력: ");
            scanf_s("%d", &data);
            printf("결과: %d\n", get_index_of_data(&list, data));
        }
        else if (choice == 11) {
            printf("length: %d\n", get_length(&list));
        }
        else if (choice == 12) {
            print_list(&list);
        }
        else if (choice == 13) {
            reverse(&list);
        }
        else {
            printf("잘못된 입력\n");
        }
    }

    return 0;
}