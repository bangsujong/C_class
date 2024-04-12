#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

typedef struct {
    int *arr;      // 정수 배열 포인터
    int top;       // 스택의 맨 위를 가리키는 인덱스
    int capacity;  // 스택의 용량 (배열의 크기)
} Stack;

void init(Stack *s) {
    s->arr = (int *)malloc(sizeof(int) * MAX_SIZE); // 초기 용량으로 메모리 할당
    s->top = -1;  // 스택 초기화: 맨 위 인덱스를 -1로 설정
    s->capacity = MAX_SIZE;  // 초기 용량 설정
}

int isEmpty(Stack *s) {
    return s->top == -1;  // 스택이 비어있으면 1 반환, 비어있지 않으면 0 반환
}

void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        // 스택이 가득 찼을 때
        // 용량을 두 배로 늘리기 위해 메모리 재할당
        s->capacity *= 2;
        s->arr = (int *)realloc(s->arr, sizeof(int) * s->capacity);
    }
    s->top++;  // 스택의 맨 위 인덱스를 증가시키고
    s->arr[s->top] = value;  // 해당 인덱스에 값을 저장
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다. 팝할 수 없습니다.\n");
        return -1;
    }
    int popped = s->arr[s->top];  // 맨 위의 값을 저장
    s->top--;  // 맨 위 인덱스를 감소시킴으로써 팝 연산 수행
    return popped;  // 팝한 값 반환
}

int main() {
    srand(time(NULL));  // 난수 생성을 위한 시드 설정
    Stack stack;  // 스택 선언
    init(&stack);  // 스택 초기화 함수 호출

    for (int i = 0; i < 30; ++i) {
        int random_number = rand() % 100 + 1; // 1부터 100 사이의 난수 생성
        if (random_number % 2 == 0) {
            printf("현재 난수 : %d | 짝수\n", random_number);
            printf("푸시 : %d\n", random_number);
            push(&stack, random_number);
        } else {
            printf("현재 난수 : %d | 홀수\n", random_number);
            printf("팝 : %d\n", random_number);
            pop(&stack);
        }

        printf("스택 요소: ");
        for (int j = 0; j <= stack.top; j++) {
            printf("%d ", stack.arr[j]);
        }
        printf("\n\n");
    }

    free(stack.arr); // 동적으로 할당된 메모리 해제
    return 0;
}
