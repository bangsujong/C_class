#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode{
    element data;
    struct listnode *link;
} ListNode;

ListNode *insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = pre -> link;
    pre -> link = p;
    return head;
}
int main(){
    ListNode *head = (ListNode *)NULL;
    insert(head, head, 10);
}