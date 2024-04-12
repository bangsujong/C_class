#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack s) {
    return s.top == -1;
}

int isFull(Stack s) {
    return s.top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (isFull(*s)) {
        printf("Stack full, cannot push %d\n", value);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("Stack empty, cannot pop.\n");
        return -1;
    }
    int popped = s->arr[s->top];
    s->top--;
    return popped;
}

int main() {
    srand(time(NULL));
    Stack stack;
    init(&stack);

    for (int i = 0; i < 30; ++i) {
        int random_number = rand() % 100 + 1; // Generate random number between 1 and 100
        if (random_number % 2 == 0) {
            printf("Current rand_num : %d | Even\n", random_number);
            printf("Push : %d\n", random_number);
            push(&stack, random_number);
        } else {
            printf("Current rand_num : %d | Odd\n", random_number);
            printf("Pop : %d\n", random_number);
            pop(&stack);
        }

        printf("Stack elements: ");
        for (int j = 0; j <= stack.top; j++) {
            printf("%d ", stack.arr[j]);
        }
        printf("\n\n");
    }

    return 0;
}
