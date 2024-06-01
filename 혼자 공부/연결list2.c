#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *insert_first(ListNode *head, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode *insert(ListNode *head, int position, element value, int *count){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;

    if(position == 0){
        p->link = head;
        head = p;
    }
    else{
        ListNode *prev = head;
        for(int i = 0; i<position; i++){
            if(prev == NULL){
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

ListNode *delete_first(ListNode *head){
    ListNode *removed;
    if(head == NULL){
        return head;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}