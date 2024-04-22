# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# define MAX_STACK_SIZE 10




typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;


//create : 위 코드에 이미 만들었음


int is_empty(){
    // if ( top == -1 ) return 1;
    // else return 0;
    return (top == -1);
}

// is_full 

int is_full(){
    // if ( top == MAX_STACK_SIZE -1 ) return 1;
    // else return 0;
    return (top == MAX_STACK_SIZE -1);
}

// push

void push(element item){
    // if( top == MAX_STACK_SIZE-1 ){ // stack full
    //   printf(stderr,"Stack is FULL\n");
    //   return;
    // }
    if ( is_full() ){
        fprintf(stderr,"Stack is FULL\n");
        return ;
    }
    else{
        top = top + 1;
        stack[top] = item;

    }
}

// pop

element pop(){                           // element peek() 이면
    element r;
    if (is_empty()){
        fprintf(stderr,"stack is empty\n");
        return -1;
    }
    else {
        // r = stack[top];
        // top = top -1;
        // return r;
        return (stack[top--]);          // return (stack(top));


    }
}

// peek

element peek(){                           // element peek() 이면
    element r;
    if (is_empty()){
        fprintf(stderr,"stack is empty\n");
        return -1;
    }
    else {
        // r = stack[top];
        // top = top -1;
        // return r;
        return (stack[top]);          // return (stack(top));


    }
}



int main(){
    element e;

    srand(time(NULL));
    e=(rand()%100)+1;
    if(e%2==0){
        push(e);
        printf("push %d\n",e);
    }
    else{
        e = pop();
        printf("pop %d\n",e);
    }

    

}