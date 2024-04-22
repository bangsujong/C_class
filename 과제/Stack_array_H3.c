#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int *stackArray;
} stack;

// 스택 초기화 함수
void initStack(stack *s) {
    s->top = -1;
    s->stackArray = (int *)malloc(sizeof(int) * MAX_STACK_SIZE);
    if (s->stackArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(stack *s) {
    return s->top == -1;
}

// 스택이 꽉 찼는지 확인하는 함수
int isFull(stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// 스택에 요소를 추가하는 함수
void push(stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    s->stackArray[++(s->top)] = item;
}

// 스택에서 요소를 제거하고 반환하는 함수
int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return s->stackArray[(s->top)--];
}

// 후위 표기법 수식 계산 함수
int eval(char expression[]) {
    stack s;
    initStack(&s);

    int i, op1, op2, result;
    char ch;

    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];
        if (isdigit(ch)) {
            push(&s, ch - '0'); // 피연산자를 스택에 푸시
        } else if (ch != ' ') {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    exit(EXIT_FAILURE);
            }

            push(&s, result); // 연산 결과를 스택에 푸시
        }
    }

    result = pop(&s);
    free(s.stackArray);
    return result;
}

int main(){
    char expression[MAX_STACK_SIZE];
    int result;

    printf("postfix Expression: ");
    fgets(expression, sizeof(expression), stdin);

    result = eval(expression);
    printf("Result: %d\n", result);

    return 0;
}
