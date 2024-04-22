#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        exit(1);
    }
    else
        s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[s->top];
}

int precedence(char op) {
    switch(op) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
void infix_to_postfix(char infix[], char postfix[]){
	StackType s;
    init_stack(&s);
    int i = 0; // infix 문자열의 인덱스
    int j = 0; // postfix 문자열의 인덱스

    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(&s, infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (!is_empty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // '(' 제거
            i++;
        } else if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i++];
        } else { // 연산자인 경우
            while (!is_empty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
            i++;
        }
    }

    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // 후위 표기식의 끝에 널 문자 추가
}

// 후위 표기식을 계산하는 함수
element evaluate_postfix(char postfix[]){
	StackType s;
    init_stack(&s);
    int i = 0;

    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(&s, postfix[i] - '0'); // 문자를 숫자로 변환하여 스택에 저장
        } else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (postfix[i]) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
                default:
                    fprintf(stderr, "올바르지 않은 연산자입니다.\n");
                    exit(1);
            }
        }
        i++;
    }

    return pop(&s);

}

void get_infix_expr(char infix[]) {
    printf("중위표기식을 입력하세요: ");
    fgets(infix, MAX_STACK_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // fgets로 입력 받은 문자열의 맨 끝에 있는 개행 문자 제거
}

void print_postfix_expr(char infix[], char postfix[]){
    infix_to_postfix(infix, postfix);
    printf("후위표기식: %s\n", postfix);
}

void calculate_postfix_expr(char postfix[]){
    element result = evaluate_postfix(postfix);
    printf("후위표기식 계산 결과: %d\n", result);
}

int main(){
    char infix[MAX_STACK_SIZE];
    char postfix[MAX_STACK_SIZE];
    int choice;
    
    while (1) {
        printf("\n1. 중위표기식 입력\n");
        printf("2. 중위표기식을 후위표기식으로 변환하여 출력\n");
        printf("3. 후위표기식을 계산하여 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar(); // 버퍼 비우기

        switch (choice) {
            case 1:
                get_infix_expr(infix);
                break;
            case 2:
                print_postfix_expr(infix, postfix);
                break;
            case 3:
                calculate_postfix_expr(postfix);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
                break;
        }
    }

    return 0;
}
