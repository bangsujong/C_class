#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = h;
	h = p;
	return h;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	if (pre == (ListNode*)NULL) {
		fprintf(stderr, "Insert parameter error in pre == NULL");
		return ;
	}
	p->data = value;
	p->link = pre->link;    //<1>
	pre->link = p; // <2>
	return head;
}


ListNode* delete_first(ListNode* h) {

	if (h == NULL) return NULL;
	ListNode* remove = h;

	h = remove->link;
	free(remove);
	return h;
}

ListNode* delete(ListNode* h, ListNode* pre) {
	ListNode* remove = pre->link;

	pre->link = remove->link;
	free(remove);

	return h;
}

void print_list(ListNode* h) {
	while (h != (ListNode*)NULL) {
		printf("[%d] ", h->data);
		h = h->link;
	}
	printf("\n");
}

ListNode* search_list(ListNode* h, element x) {
	ListNode* p = h;
	
	while (p != NULL) {
		if (p->data == x ) break;
		p = p->link;
	}
	return p;
}

ListNode* reverse(ListNode* h) {
	ListNode* r, * q, * p;

	q = NULL;
	p = h;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}


int main() {
	ListNode* head=(ListNode *) NULL;

	head = insert_first(head, 10);

	insert(head, head, 20);
	print_list(head);

	insert(head, head, 15);
	print_list(head);

	ListNode* p = (ListNode*)head;
	for (int i = 0; i < 2; i++) {
		p = p->link;
	}
	insert(head, p, 40);
	print_list(head);

	ListNode *s = search_list(head, 20);
	if (s == (ListNode*)0)
		fprintf(stderr, "Not found %d\n", 20);
	else
		printf("Found %d\n", s->data);

	s = search_list(head, 30);
	if (s == (ListNode*)0)
		fprintf(stderr, "Not found %d\n", 30);
	else
		printf("Found %d\n", s->data);


	element value; 
	value = delete(head, head);
	print_list(head);

	head = reverse(head);
	print_list(head);
}
