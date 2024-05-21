#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode *insert(ListNode *head, int position, element value, int *count) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;

    if (position == 0) {
        p->link = head;
        head = p;
    } else {
        ListNode *prev = head;
        for (int i = 0; i < position - 1; i++) {
            if (prev == NULL) {
                printf("Position out of bounds\n");
                free(p);
                return head;
            }
            prev = prev->link;
            (*count)++;
        }
        p->link = prev->link;
        prev->link = p;
    }
    return head;
}

ListNode *delete_first(ListNode *head) {
    ListNode *removed;
    if (head == NULL) {
        return NULL;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode *delete(ListNode *head, int position, int *count) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (position == 0) {
        return delete_first(head);
    } else {
        ListNode *prev = head;
        for (int i = 0; i < position - 1; i++) {
            if (prev->link == NULL) {
                printf("Position out of bounds\n");
                return head;
            }
            prev = prev->link;
            (*count)++;
        }
        ListNode *removed = prev->link;
        if (removed == NULL) {
            printf("Position out of bounds\n");
            return head;
        }
        prev->link = removed->link;
        free(removed);
    }
    return head;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main() {
    ListNode *list = NULL;
    int choice, position;
    element item;

    while (1) {
        printf("\n메뉴\n");
        printf("1. 리스트에 숫자와 위치 삽입\n");
        printf("2. 리스트에서 위치 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int count = 0;
                printf("삽입할 숫자와 위치를 입력하세요 (숫자 위치): ");
                scanf("%d %d", &item, &position);
                list = insert(list, position, item, &count);
                printf("삽입시 링크를 따라 이동한 횟수: %d\n", count);
                break;
            }
            case 2: {
                int count = 0;
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                list = delete(list, position, &count);
                printf("삭제시 링크를 따라 이동한 횟수: %d\n", count);
                break;
            }
            case 3:
                print_list(list);
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
