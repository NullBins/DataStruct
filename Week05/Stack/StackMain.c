#include <stdio.h>
#include "Stack.h"
#include "SubUtils.h"

int main(void) {
    elem_int menu, val;
    elem_int top;
    stk_t stack;

    init_stack(&stack);
    printGrad("< 현재 Stack 공간 >\n");
    printGrad("["); for(int i = 0; i < stack.capacity; i++) printf("%3d", stack.data[i]); printGrad(" ]\n");
    while (1) {
        if (stack.top > 0) {
            getLine(50); printGrad("<STACK> ["); print_stack(&stack); printGrad(" ]\n");
        }
        getLine(50);
        printGrad("(1) 스택 push\t(2) 스택 pop\n");
        printGrad("(3) 스택 peek\t(4) 종료\n");
        printGrad("=> "); if(onlyNumber(&menu)) continue;
        if (menu == 4) break;
        switch (menu) {
        case 1:
            getLine(50); printGrad("push > "); if(onlyNumber(&val)) continue;
            push(&stack, val); break;
        case 2:
            top = pop(&stack);
            if (top != STACK_ERROR) { getLine(50); printf("[pop] top에 있던 값 %d이 pop 되었습니다.\n", top); } break;
        case 3:
            top = peek(&stack);
            if (top != STACK_ERROR) { getLine(50); printf("[peek] top에 있던 값 %d이 peek 되었습니다.\n", top); } break;
        default: printf(RED "1 ~ 4 중 하나를 선택해주세요.\n" RESET); break;
        }
    }

    return 0;
}