#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode *insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = node;
    } else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode *delete_first(ListNode *head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return NULL;
    }

    ListNode *removed = head->link;
    if (head == removed) {
        free(removed);
        return NULL;
    } else {
        head->link = removed->link;
        free(removed);
        return head;
    }
}

ListNode *delete_last(ListNode *head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return NULL;
    }

    ListNode *curr = head->link;

    // 노드가 하나만 있는 경우
    if (curr == head) {
        free(head);
        return NULL;
    }

    // 노드가 여러 개 있는 경우
    else{
        while(curr->link != head){
            curr = curr ->link;
        }
        curr -> link = head->link;
        free(head);
        return curr;
    }
}

void print_list(ListNode *head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    ListNode *p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("(head)\n");
}

int main() {
    ListNode *head = NULL;
    int choice, data;

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
                printf("추가할 숫자 입력: ");
                scanf("%d", &data);
                head = insert_first(head, data);
                break;
            case 2:
                printf("추가할 숫자 입력: ");
                scanf("%d", &data);
                head = insert_last(head, data);
                break;
            case 3:
                head = delete_first(head);
                break;
            case 4:
                head = delete_last(head);
                break;
            case 5:
                print_list(head);
                break;
            case 6:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}