#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef struct{
    int id;
    int arrival_time;
    int service_time;
} element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int is_full(QueueType *q){
    return q->front == ((q->rear + 1 )%MAX_QUEUE_SIZE );
}

int is_empty(QueueType *q){
    return (q -> front == q->rear );
}

void init_queue(QueueType *q){
    q -> front = q->rear = 0;
}

void print_queue(QueueType *q){
    int i;
    for( i = (q->front+1)%MAX_QUEUE_SIZE; i != q->rear; i = (i+1)%MAX_QUEUE_SIZE ){
        printf("[%2d] %2d ", i , q->data[i]);
    }
    printf("[%2d] %2d\n", i , q->data[i]);
}

void enqueue(QueueType *q, element item){
    if(is_full(q) ){
        error("Queue is full\n");
    }
    else{
        q->rear =(q->rear+1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("Queue is empty\n");
    }
    else{
        q->front = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
}

int main(){
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time = 0;
    int service_customer;
    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));
    for( int clock=0; clock < minutes; clock++){
        printf("현재시간 = %d\n", clock);

    // producer
        if(( rand() % 10 ) < 3){
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3+1;
            enqueue(&queue, customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", customer.id, customer.arrival_time, customer.service_time);
        }
        // consummer
        if(service_time == 0 ){ /* 작업처리 완료, 새로운 작업 가져오기 */
            if(!is_empty(&queue)){
                element customer = dequeue(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작하빈다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
        else{
            service_time--;
            printf("고객 %d의 업무 처리 중입니다.\n",service_customer);
        }
    }
    printf(" \n Total Wait = %d , Average Wait %d\n ", total_wait, total_wait/total_customers);
    return 0;
}