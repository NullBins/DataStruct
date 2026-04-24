#pragma once
#define MAX_QUEUE_SIZE 10
#define QUEUE_ERROR -1

typedef int elem_int;
typedef struct Queue {
    elem_int data[MAX_QUEUE_SIZE];
    int rear;
    int front;
} que_t;

void init_queue(que_t* que);
elem_int is_empty(que_t* que);
elem_int is_full(que_t* que);
void enqueue(que_t* que, elem_int val);
elem_int dequeue(que_t* que);
elem_int peek(que_t* que);
void print_queue(que_t* que);