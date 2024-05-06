#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
}

int is_full(QueueType *q) {
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

void print_queue(QueueType *q) {
    int i = (q->front + 1) % MAX_QUEUE_SIZE;

    printf("--------------------------------\n");
    printf("현재 큐 상태 : ");

    if (is_empty(q)) {
        printf("큐는 비어 있습니다.\n");
    } 
    else {
        while (i != q->rear) {
            printf("%2d ", q->data[i]);
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
        printf("%2d\n", q->data[i]);
    }

    printf("--------------------------------\n");
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("큐는 포화상태입니다.\n");
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
        printf("%d을(를) 큐에 삽입했습니다.\n", item);
    }
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        error("Queue is empty\n");
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        printf("%d을(를) 큐에서 삭제했습니다.\n", q->data[q->front]);
        return q->data[q->front];
    }
}

int main() {
    QueueType queue;
    int choice;
    element item;

    init_queue(&queue);

    while (1) {
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에 원소를 삭제\n");
        printf("3. 큐에 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하시오 : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 원소를 입력하세요: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                print_queue(&queue);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 메뉴 선택입니다. 다시 선택해주세요.\n");
                break;
        }
    }

    return 0;
}
