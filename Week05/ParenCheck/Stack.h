#pragma once
#define MAX_STACK_SIZE 16
#define STACK_ERROR -1

typedef int elem_int; // 정수 타입 자료형을 elem_int로 정의
typedef struct Stack {
    // elem_int data[MAX_STACK_SIZE]; // 스택 공간
    elem_int* data; // 동적 할당을 위한 스택 포인터 변수
    elem_int top; // top 변수 (기본 0)
    elem_int capacity; // 스택 용량(크기) 변수
} stk_t;

void init_stack(stk_t* st); // 스택 초기화
elem_int is_empty(stk_t* st); // 스택이 비었는가
elem_int is_pull(stk_t* st); // 스택이 가득 찼는가
void push(stk_t* st, char data); // 스택에 push 하기
elem_int pop(stk_t* st); // 스택에 pop 하기
elem_int peek(stk_t* st); // 스택에 peek 하기
void print_stack(stk_t* st); // 스택 공간 출력
void free_stack(stk_t* st); // 스택 공간 메모리 반납