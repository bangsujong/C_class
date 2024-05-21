#include <stdio.h>
#include <stdlib.h>

// typedef int element;
// typedef struct ListNode{  // 노드 타입을 구조체로 정의한다.
//     element data;
//     struct ListNode *link;
// } ListNode;

// // 리스트의 생성
// ListNode *head = NULL;
// head = (ListNode *)malloc(sizeof(ListNode));
// head -> data = 10;
// head -> link = NULL;

// // 두번째 노드 생성
// ListNode *p;
// p=(ListNode *)malloc(sizeof(ListNode));
// p->data=20;
// p->link=NULL;

// // 노드의 연결
// head->link =p;

// 연결 리스트의 연산
// - insert_first()
// - insert()           -> 리스트의 중간 부분에 항목을 삽입하는 함수
// - delete_first()
// - delete()           -> 리스트의 중간 항목을 삭제하는 함수
// - print_list()       -> 리스트를 방문하여 모듴 항목을 출력하는 함수

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p -> link = head;
    head = p;
    return head;
}

// 노드 pre뒤에 새로운 노드 집합
ListNode *insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = pre -> link;
    pre -> link = p;
    return head;
}
ListNode *delete_first(ListNode *head){
    ListNode *removed;
    if(head == NULL){
        return NULL;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

// pre가 가르키는 노드의 다음 노드를 삭제한다.
ListNode *delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

ListNode *reverse(ListNode *head){
    ListNode *r, *q, *p;

    q = NULL;
    p = head;
    
    while (p != NULL){
        r=q;
        q=p;
        p = p->link;
        q -> link = r;
    }
    return q;

}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p->link){
        printf("%d -> ", p->data);
    }
    printf("NULL \n");
}



int main(){
    ListNode *head = NULL;
    for(int i = 0; i<5; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    for(int i = 0; i < 5; i ++){
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}

