#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[30];
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void copy_string(element dest, const element src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

ListNode *insert_last(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    copy_string(p->data, value);
    p->link = NULL;

    if (head == NULL) {
        head = p;
    } else {
        ListNode *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = p;
    }
    return head;
}

ListNode *insert(ListNode *head, int position, element value, int *count) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    copy_string(p->data, value);

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

ListNode *delete_first(ListNode *head, element deleted_fruits[], int *deleted_count) {
    ListNode *removed;
    if (head == NULL) {
        return NULL;
    }
    removed = head;
    head = removed->link;
    copy_string(deleted_fruits[*deleted_count], removed->data);
    (*deleted_count)++;
    free(removed);
    return head;
}

ListNode *delete(ListNode *head, int position, element deleted_fruits[], int *deleted_count, int *count) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (position == 0) {
        return delete_first(head, deleted_fruits, deleted_count);
    } 
    else {
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
        copy_string(deleted_fruits[*deleted_count], removed->data);
        (*deleted_count)++;
        free(removed);
    }
    return head;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%s -> ", p->data);
    }
    printf("NULL\n");
}

void print_deleted_fruits(element deleted_fruits[], int deleted_count) {
    if (deleted_count > 0) {
        printf("삭제된 과일 목록: ");
        for (int i = 0; i < deleted_count; i++) {
            printf("%s ", deleted_fruits[i]);
        }
        printf("\n");
    } else {
        printf("삭제된 과일이 없습니다.\n");
    }
}

int main() {
    ListNode *list = NULL;
    element deleted_fruits[20];
    int deleted_count = 0;
    int choice, position;
    element item;
    int count;

    // 초기 과일 리스트
    char *initial_fruits[] = {"Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach"};
    for (int i = 0; i < 10; i++) {
        list = insert_last(list, initial_fruits[i]);
    }

    while (1) {
        printf("\n메뉴\n");
        printf("1. 리스트의 새로운 과일 추가\n");
        printf("2. 리스트에 있는 과일을 삭제\n");
        printf("3. 삭제된 과일 목록 출력\n");
        printf("4. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("추가할 과일 이름: ");
                scanf("%s", item);
                list = insert_last(list, item);
                printf("%s 추가되었습니다.\n", item);
                break;
            case 2:
                count = 0;
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                list = delete(list, position, deleted_fruits, &deleted_count, &count);
                printf("링크를 따라 이동한 횟수: %d\n", count);
                break;
            case 3:
                print_deleted_fruits(deleted_fruits, deleted_count);
                break;
            case 4:
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
