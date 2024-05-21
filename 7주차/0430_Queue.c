#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

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
    QueueType queue;
    element e;
    init_queue(&queue);

    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);
    enqueue(&queue, 4); print_queue(&queue);
    enqueue(&queue, 5); print_queue(&queue);
    enqueue(&queue, 6); print_queue(&queue);

    e= dequeue(&queue); printf("<2%d>",e);; print_queue(&queue);
    e= dequeue(&queue); printf("<2%d>",e);; print_queue(&queue);
    e= dequeue(&queue); printf("<2%d>",e);; print_queue(&queue);
}