#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// 리스트 초기화 함수
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

// 리스트 출력 함수
void print_dlist(DListNode* phead) {
    if (phead->rlink == phead) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf(" %d ->", p->data);
    }
    printf(" (head)\n");
}
// 리스트 처음에 노드 추가 함수
void add_to_beginning(DListNode* phead, element data) {
    DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
    new_node->data = data;
    
    new_node->rlink = phead->rlink;
    new_node->llink = phead;
    phead->rlink->llink = new_node;
    phead->rlink = new_node;
}

// 리스트 마지막에 노드 추가 함수
void add_to_end(DListNode* phead, element data) {
    DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
    new_node->data = data;
    
    new_node->llink = phead->llink;
    new_node->rlink = phead;
    phead->llink->rlink = new_node;
    phead->llink = new_node;
}

// 리스트 처음 노드 삭제 함수
void delete_from_beginning(DListNode* phead) {
    if (phead->rlink == phead) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    DListNode* removed = phead->rlink;
    phead->rlink = removed->rlink;
    removed->rlink->llink = phead;
    free(removed);
}

// 리스트 마지막 노드 삭제 함수
void delete_from_end(DListNode* phead) {
    if (phead->llink == phead) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    DListNode* removed = phead->llink;
    phead->llink = removed->llink;
    removed->llink->rlink = phead;
    free(removed);
}

int main() {
    DListNode head;
    init(&head);
    int choice, num;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("3. 리스트 처음 노드 삭제\n");
        printf("4. 리스트 마지막 노드 삭제\n");
        printf("5. 리스트 프린트\n");
        printf("6. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("숫자 입력: ");
                scanf("%d", &num);
                add_to_beginning(&head, num);
                break;
            case 2:
                printf("숫자 입력: ");
                scanf("%d", &num);
                add_to_end(&head, num);
                break;
            case 3:
                delete_from_beginning(&head);
                break;
            case 4:
                delete_from_end(&head);
                break;
            case 5:
                print_dlist(&head);
                break;
            case 6:
                printf("프로그램 종료.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }
    }
}
