#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int coef;
    int expo;
}element;

typedef struct listNode{
    element data;
    struct listNode *link;
}ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    int size;
}ListType;

ListType *create(){
    ListType *plist = (ListType *)malloc(sizeof(ListType));
}

void insert_last(ListType *plist, element term){
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = term;
    temp->link = NULL;
    if(plist->head == NULL){
        plist->head = plist->tail = temp;
    }
    else{
        plist->tail->link = temp;
        plist -> tail = temp;
    }
    plist->size++;
}

void print_poly(ListType *pl){
    ListNode *np = pl->head;

    while(np != NULL){
        printf("%2dx%2d ", np->data.coef, np->data.expo);
        np = np -> link;
        if(np == NULL)
            printf("+");
    }
    printf("\n");
}

poly_add(ListType *plist1, ListType *plist2, ListType *plist3){
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;

    while ((a != NULL) && (b != NULL)){
        if(a->data.expo == b->data.expo){
            int sum;
            sum = a->data.coef + b->data.coef;
            if(sum != 0){
                element x;
                x.coef = sum, x.expo = a->data.expo;
                insert_last(plist3, x);
            }
            a = a->link, b = b->link;
        } 
        else if (a->data.expo > b->data.expo){
            insert_last(plist3, a->data);
            a= a->link;
        }
        else{
            insert_last(plist3, b->data);
            b= b->link;
        }
    }
    while (a != NULL){
        insert_last(plist3, a->data);
        a = a->link;
    }

    while (b != NULL){
        insert_last(plist3, b->data);
        b = b->link;
    }
}

int main(){
    ListType *list1 = create();
    ListType *list2 = create();
    ListType *list3 = create();

    element x;
    x.coef = 3, x.expo = 12;
    insert_last(list1, x);
    x.coef = 2, x.expo = 8;
    insert_last(list1, x);
    x.coef = 1, x.expo = 0;
    insert_last(list1, x);
    printf("A = ");
    x.coef = 8, x.expo = 12;
    insert_last(list2, x);
    x.coef = -3, x.expo = 10;
    insert_last(list2, x);
    x.coef = 10, x.expo = 6;
    insert_last(list2, x);


}
