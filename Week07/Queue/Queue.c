#include <stdio.h>
#include "Queue.h"
#include "../SubUtils.h"

void init_queue(que_t* que) {
    que->rear = 0;
    que->front = 0;
}

elem_int is_empty(que_t* que) {
    return (que->rear == que->front);
}

elem_int is_full(que_t* que) {
    return (que->front == (que->rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue(que_t* que, elem_int val) {
    if(is_full(que)) { getLine(50); fprintf(stderr, RED "Queue Full 에러! (큐가 꽉참)\n" RESET); return; }
    que->data[que->rear] = val;
    que->rear = (que->rear + 1) % MAX_QUEUE_SIZE;
}

elem_int dequeue(que_t* que) {
    elem_int e = que->data[que->front];
    if(is_empty(que)) { getLine(50); fprintf(stderr, RED "Queue Empty 에러! (큐가 텅텅 비었음)\n" RESET); return QUEUE_ERROR; }
    que->front = (que->front + 1) % MAX_QUEUE_SIZE;
    return e;
}

elem_int peek(que_t* que) {
    if(is_empty(que)) { getLine(50); fprintf(stderr, RED "Queue Empty 에러! (큐가 텅텅 비었음)\n" RESET); return QUEUE_ERROR; }
    return(que->data[que->front]);
}

void print_queue(que_t* que) {
    printGrad("[ ");
    for(int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (que->front < que->rear && (i >= que->front && i < que->rear)) {
            printf("%2d ", que->data[i % MAX_QUEUE_SIZE]);
        } else if (que->front > que->rear && (i < que->rear || i >= que->front)) {
            printf("%2d ", que->data[i % MAX_QUEUE_SIZE]);
        } else {
            printf("-- ");
        }
    }
    printGrad(" ]\n");
    printf("\n");
}