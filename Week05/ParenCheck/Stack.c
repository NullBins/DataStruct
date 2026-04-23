#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void init_stack(stk_t* st) {
    st->capacity = MAX_STACK_SIZE;
    st->data = (elem_int*)malloc(sizeof(elem_int) * st->capacity);
    st->top = 0;
    for(int i = 0; i < st->capacity; i++) st->data[i] = 0;
}

elem_int is_empty(stk_t* st) {
    return (st->top == 0);
}

elem_int is_pull(stk_t* st) {
    return (st->top == st->capacity);
}

void push(stk_t* st, char data) {
    // if (is_pull(st)) { fprintf(stderr, "스택 pull 에러\n"); return STACK_ERROR; }
    if (is_pull(st)) {
        st->capacity *= 2; // 스택이 full이면 용량을 2배 늘림
        st->data = (elem_int*)realloc(st->data, (sizeof(elem_int) * st->capacity));
        // realloc을 사용해 스택 용량 2배로 다시 할당
    }
    st->data[st->top++] = data;
}

elem_int pop(stk_t* st) {
    if (is_empty(st)) { fprintf(stderr, "스택 empty 에러 (스택이 텅텅 비었음)\n"); return STACK_ERROR; }
    return st->data[--st->top];
}

elem_int peek(stk_t* st) {
    if (is_empty(st)) { fprintf(stderr, "스택 empty 에러 (스택이 텅텅 비었음)\n"); return STACK_ERROR; }
    return st->data[st->top - 1];
}

void print_stack(stk_t* st) {
    for(int i = 0; i < st->top; i++) printf("%-4c", st->data[i]);
    //printf("\n");
}

void free_stack(stk_t* st) {
    free(st->data);
}