#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} Stack;

// 에러 메시지 출력 후 프로그램 종료
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 큐가 가득 찼는지 확인
int is_full_queue(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE) == q->front;
}

// 큐가 비어있는지 확인
int is_empty_queue(QueueType *q) {
    return (q->front == q->rear);
}

// 큐 초기화
void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

// 큐에 원소 추가
void enqueue(QueueType *q, element item) {
    if (is_full_queue(q)) {
        error("Queue is full");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 큐에서 원소 제거
element dequeue(QueueType *q) {
    if (is_empty_queue(q)) {
        error("Queue is empty");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 스택 초기화
void init_stack(Stack *s) {
    s->top = -1;
}

// 스택이 가득 찼는지 확인
int is_full_stack(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// 스택이 비어있는지 확인
int is_empty_stack(Stack *s) {
    return s->top == -1;
}

// 스택에 원소 추가
void push(Stack *s, element item) {
    if (is_full_stack(s)) {
        error("Stack is full");
    }
    s->data[++s->top] = item;
}

// 스택에서 원소 제거
element pop(Stack *s) {
    if (is_empty_stack(s)) {
        error("Stack is empty");
    }
    return s->data[s->top--];
}

// 입력 문자열에서 알파벳만 추출하고 소문자로 변환
void preprocess(char *input, char *output) {
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0';
}

// 주어진 문자열이 회문인지 검사
int isPalindrome(char *str) {
    Stack s;
    QueueType q;
    char processed[MAX_QUEUE_SIZE];

    init_stack(&s);
    init_queue(&q);

    preprocess(str, processed);

    for (int i = 0; i < strlen(processed); i++) {
        push(&s, processed[i]);
        enqueue(&q, processed[i]);
    }

    while (!is_empty_stack(&s) && !is_empty_queue(&q)) {
        if (pop(&s) != dequeue(&q)) {
            return 0; // 회문이 아님
        }
    }

    return 1; // 회문임
}

int main() {
    char str[MAX_QUEUE_SIZE];
    int choice;

    while (1) {
        printf("\n1. 회문 입력\n");
        printf("2. 회문 검사\n");
        printf("3. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // 입력 버퍼 비우기

        switch (choice) {
            case 1:
                printf("회문을 입력하세요: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // 개행 문자 제거
                break;
            case 2:
                if (isPalindrome(str)) {
                    printf("회문입니다.\n");
                } else {
                    printf("회문이 아닙니다.\n");
                }
                break;
            case 3:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 메뉴 선택입니다.\n");
                break;
        }
    }

    return 0;
}
