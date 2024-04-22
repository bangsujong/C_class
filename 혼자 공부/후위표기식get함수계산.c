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

element eval(char exp[]){
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);
    for (i = 0; i < len; i++){
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch){
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

void get_expr(char expr[]) {
    printf("후위표기식을 입력하세요: ");
    fgets(expr, MAX_STACK_SIZE, stdin);
    expr[strcspn(expr, "\n")] = '\0'; // fgets로 입력 받은 문자열의 맨 끝에 있는 개행 문자 제거
}

int main(){
    char expr[MAX_STACK_SIZE];
    get_expr(expr);
    int result = eval(expr);
    printf("결과값은 %d\n", result);
    return 0;
}
