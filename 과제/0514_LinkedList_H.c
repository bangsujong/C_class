#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 // 리스트의 최대크기

typedef int element; // 항목의 정의

typedef struct {
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType *L) {
    L->size = 0;
}

// 리스트가 비어있으면 1을 반환, 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L) {
    return L->size == 0;
}

// 리스트가 가득차 있으면 1을 반환, 그렇지 않으면 0을 반환
int is_full(ArrayListType *L) {
    return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos) {
    if (pos < 0 || pos >= L->size) {
        error("위치 오류");
    }
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType *L) {
    for (int i = 0; i < L->size; i++) {
        printf("%d -> ", L->array[i]);
    }
    printf("NULL\n");
}

void insert_last(ArrayListType *L, element item) {
    if (L->size >= MAX_LIST_SIZE) {
        error("리스트 오버플로우");
    }
    L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item) {
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        int move_count = 0;
        for (int i = (L->size - 1); i >= pos; i--) {
            L->array[i + 1] = L->array[i];
            move_count++;
        }
        L->array[pos] = item;
        L->size++;
        printf("데이터 이동 횟수: %d\n", move_count);
    } else {
        error("삽입할 수 없습니다.");
    }
}

element delete(ArrayListType *L, int pos) {
    if (pos < 0 || pos >= L->size) {
        error("위치 오류");
    }
    element item = L->array[pos];
    int move_count = 0;
    for (int i = pos; i < (L->size - 1); i++) {
        L->array[i] = L->array[i + 1];
        move_count++;
    }
    L->size--;
    printf("데이터 이동 횟수: %d\n", move_count);
    return item;
}

int main() {
    ArrayListType list;
    int choice, position;
    element item;

    init(&list);

    while (1) {
        printf("\n메뉴\n");
        printf("1. 리스트에 숫자와 위치 삽입\n");
        printf("2. 리스트에서 위치 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(is_full(&list)) {
                    printf("리스트가 꽉 찼습니다.\n");
                }
                else {
                    printf("삽입할 숫자: ");
                    scanf("%d", &item);
                    printf("삽입할 위치: ");
                    scanf("%d", &position);
                    insert(&list, position, item);
                }
                break;
            case 2:
                if(is_empty(&list)){
                    printf("리스트가 비어있습니다.\n");
                }
                else{
                    printf("삭제할 위치: ");
                    scanf("%d", &position);
                    delete(&list, position);
                }
                break;
            case 3:
                print_list(&list);
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}
