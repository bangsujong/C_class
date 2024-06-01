// #include <stdio.h>
// #include <stdlib.h>

// typedef int element;

// typedef struct listNode {
//     element data;
//     struct listNode *link;
// } ListNode;

// ListNode *insert_first(ListNode *tail, element data) {
//     ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//     node->data = data;

//     if (tail == NULL) {
//         tail = node;
//         node->link = tail;
//     } else {
//         node->link = tail->link;
//         tail->link = node;
//     }
//     return tail;
// }

// ListNode *insert_last(ListNode *tail, element data) {
//     ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//     node->data = data;

//     if (tail == NULL) {
//         tail = node;
//         node->link = node; // node->link = tail 같음
//     } else {
//         node->link = tail->link;
//         tail->link = node;
//         tail = node;
//     }
//     return tail;
// }

// ListNode *delete_first(ListNode *tail) {
//     if (tail == NULL) return NULL;
//     if (tail->link == tail) {
//         free(tail);
//         return NULL;
//     }

//     ListNode *first = tail->link;
//     tail->link = first->link;
//     free(first);

//     return tail;
// }

// ListNode *delete_last(ListNode *tail) {
//     if (tail == NULL) return NULL;
//     if (tail->link == tail) {
//         free(tail);
//         return NULL;
//     }

//     ListNode *current = tail->link;
//     while (current->link != tail) {
//         current = current->link;
//     }
//     current->link = tail->link;
//     free(tail);
//     tail = current;

//     return tail;
// }

// void print_list(ListNode *tail) {
//     if (tail == NULL) return;

//     ListNode *p = tail->link;
//     do {
//         printf("%2d-> ", p->data);
//         p = p->link;
//     } while (p != tail->link);
//     printf("(head)\n");
// }

// void menu() {
//     printf("메뉴:\n");
//     printf("1. 숫자를 리스트의 처음에 추가\n");
//     printf("2. 숫자를 리스트의 마지막에 추가\n");
//     printf("3. 첫 번째 노드 삭제\n");
//     printf("4. 마지막 노드 삭제\n");
//     printf("5. 리스트 출력\n");
//     printf("6. 종료\n");
// }

// int main() {
//     ListNode *tail = NULL;
//     int choice, value;

//     while (1) {
//         menu();
//         printf("선택: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("숫자 입력: ");
//                 scanf("%d", &value);
//                 tail = insert_first(tail, value);
//                 break;
//             case 2:
//                 printf("숫자 입력: ");
//                 scanf("%d", &value);
//                 tail = insert_last(tail, value);
//                 break;
//             case 3:
//                 tail = delete_first(tail);
//                 break;
//             case 4:
//                 tail = delete_last(tail);
//                 break;
//             case 5:
//                 print_list(tail);
//                 break;
//             case 6:
//                 exit(0);
//                 break;
//             default:
//                 printf("잘못된 선택입니다. 다시 시도하십시오.\n");
//         }
//     }
//     return 0;
// }

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
int main() {
	ListNode* tail = NULL;

	tail = insert_first(tail, 30);
	tail = insert_first(tail, 20);
	tail = insert_first(tail, 10);
	// print_list(tail);

	tail = insert_last(tail, 40);
	tail = insert_last(tail, 50);
	tail = insert_last(tail, 60);
	print_list(tail);

}
