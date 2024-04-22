#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;


// 스택 초기화 함수
void init_stack(StackType *s){
    s->top =-1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
    return ( s->top == -1 );
}

// 포화 상태 검출 함수

int is_full(StackType *s){
    return ( s->top == (MAX_STACK_SIZE - 1) );
}

// 삽입함수
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

// 피크함수

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러");
        exit(1);
    }
    else
        return s->data[s->top];
}

int eval(char expr[]) {

	StackType s;
	init_stack(&s);
	int len = strlen(expr);

	for (int i = 0; i < len; i++) {
		int ch = expr[i];
		int value;
		int op1, op2;

		if ((ch == '+') || (ch == '-')|| (ch == '*') || (ch == '/')) {
			op1 = pop(&s);
			op2 = pop(&s);
            
			switch (ch) {
				case '+': push(&s, op2 + op1); break;
				case '-' :push(&s, op2 - op1); break;
				case '*' :push(&s, op2 * op1); break;
				case '/' :push(&s, op2 / op1); break;
				default:;
			}
		}
		else if ((ch >= '0') && (ch <= '9')) {
			value = ch - '0';
			push(&s, value);
		}
	}
	return (pop(&s));
}


int main(){
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("8 2 / 3 - 3 2 * +\n");
    printf("결과값은 %d\n", result);
    return 0;
}