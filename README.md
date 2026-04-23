# Data Structure (*with C-Language*)

## 1. Array List Functions (<u>Week02</u>)
- ["Phase1.c"](./Week02/Phase1.c)
- ["Phase2.c"](./Week02/Phase2.c)
- ["Phase3.c"](./Week02/Phase3.c)
- ["Phase4.c"](./Week02/Phase4.c)
- ["Phase5.c"](./Week02/Phase5.c)
> [ Phase4 on Terminal ]
> ![Terminal](./Week02/Terminal1.png)
> [ Phase5 on Terminal ]
> ![Terminal](./Week02/Terminal2.png)

---

## 2. Array List using ADT(Abstract Data Type) structure (<u>Week03</u>)
### 2-1) ADT structure
> [ ADT Struct ]
>```c
>typedef struct {
>    int arr[MAX];
>    int size;
>} arrlist_t;
>
>arrlist_t list;
>```
- ["ArrListPhase1.c"](./Week03/ArrListPhase1.c)
- ["ArrListPhase2.c"](./Week03/ArrListPhase2.c)
> [ ArrListPhase2 on Terminal ]
> ![Terminal](./Week03/Terminal1.png)

### 2-2) Code separation
> [ Linking example ]
> ![Picture](./Week03/Separate/sep1.png)
> [ UDH example ]
> ![Picture](./Week03/Separate/sep2.png)
- ["Separate/main.c"](./Week03/Separate/main.c)
- ["Separate/Arrlist.h"](./Week03/Separate/Arrlist.h)
- ["Separate/Arrlist.c"](./Week03/Separate/Arrlist.c)

---

## 4. Stack Implimentation (<u>Week05</u>)
> [ Stack example ]
>
> ![Terminal](./Week05/Stack.png)
### 4-1) Stack ADT structure
> [ Stack ADT Struct & Functions ]
>```c
>typedef int elem_int; // 정수 타입 자료형을 elem_int로 정의
>typedef struct Stack {
>    int* data; // 동적 할당을 위한 스택 포인터 변수
>    int top; // top 변수 (기본 0)
>    int capacity; // 스택 용량(크기) 변수
>} stk_t;
>
>void init_stack(stk_t* st); // 스택 초기화
>int is_empty(stk_t* st); // 스택이 비었는가
>int is_pull(stk_t* st); // 스택이 가득 찼는가
>void push(stk_t* st, int data); // 스택에 push 하기
>int pop(stk_t* st); // 스택에 pop 하기
>int peek(stk_t* st); // 스택에 peek 하기
>void print_stack(stk_t* st); // 스택 공간 출력
>void free_stack(stk_t* st); // 스택 공간 메모리 반납
>```
- ["Stack/Stack.h"](./Week05/Stack/Stack.h)
- ["Stack/Stack.c"](./Week05/Stack/Stack.c)
- ["Stack/StackMain.c"](./Week05/Stack/StackMain.c)
> [ StackMain on Terminal ]
> ![Terminal](./Week05/Terminal1.png)

### 4-2) Paren checking using stack
> [ Paren check example]
>
> ![Terminal](./Week05/ParenCheck.png)
>```c
>int is_open(char paren); // 여는 괄호 확인
>int is_closing(char paren); // 닫는 괄호 확인
>int matching(char open_pr, char pr); // 여닫는 괄호가 일치하는지 확인
>void print_line(stk_t* st, char* parens); // 문자열과 스택 출력
>int paren_check(char* parens); // 괄호 검사 함수
>```
- ["ParenCheck/Stack.h"](./Week05/ParenCheck/Stack.h)
- ["ParenCheck/Stack.c"](./Week05/ParenCheck/Stack.c)
- ["ParenCheck/ParenCheck.c"](./Week05/ParenCheck/ParenCheck.c)
> [ ParenCheck on Terminal ]
> ![Terminal](./Week05/Terminal2.png)

---