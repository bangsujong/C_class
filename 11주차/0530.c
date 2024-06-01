// circular LinkedList로 Stack 구현

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode *insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

void print_list(ListNode* tail) {
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	do {
		printf("[%2d] ", p->data);
		p = p->link;
	} while (p != tail->link);
}

ListNode* insert_last(ListNode* tail, element data) {
	
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); // <1>
	node->data = data; // <2>

	if (tail == NULL) {
		tail = node;
		node->link = node;
	}
	else {
		node->link = tail->link; //<3>
		tail->link = node; //<4>
		tail = node; //<5>
	}
	return tail; //<5>
}

ListNode *delete_first(ListNode *tp, element *dp){
    ListNode *fp;

    if(tp ==NULL){ // ERROR
        fprintf(stderr,"No data to be deleted in delete_first()\n");
        *dp = -1;
        return NULL;
    }
    else{
        tp = tp->link; // <1>
        tp->link = fp->link; // <2>
        *dp = fp->data;// <3>
        free(fp); // <4>
        if( tp == fp){
            return NULL;
        }
        else{
            return tp; // <5>
        }
    }
}

ListNode *push(ListNode *tp, element d){
    return insert_first(tp,d);
}

ListNode *pop(ListNode *tp, element *dp){
    return delete_first(tp,dp);
}

int main() {
	ListNode* tail = NULL;

	tail = insert_first(tail, 30);
	tail = insert_first(tail, 20);
	tail = insert_first(tail, 10);
	// print_list(tail);

	// tail = insert_last(tail, 40);
	// tail = insert_last(tail, 50);
	// tail = insert_last(tail, 60);
    // print_list(tail);
    // printf("\n");

    element poped_data;
    tail = delete_first(tail, &poped_data);
    if(poped_data != -1) printf("Deleted Data = %d\n", poped_data);
    print_list(tail);


    printf("-----------------------------------------\n");

    ListNode *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    top = pop(top, &pd);
    top = pop(top, &pd);
    top = pop(top, &pd);
    top = pop(top, &pd);

}
