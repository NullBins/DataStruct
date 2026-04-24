#include <stdio.h>
#include "Queue.h"
#include "../SubUtils.h"

int main(void) {
    elem_int menu, val;
    elem_int front;
    que_t queue;

    init_queue(&queue);
    for(int i = 0; i < MAX_QUEUE_SIZE; i++) queue.data[i] = 0;
    while (1) {
        getLine(50);
        printGrad("< 현재 Queue 공간 >\n");
        print_queue(&queue);
        getLine(50);
        printGrad("(1) 큐 enqueue\t(2) 큐 dequeue\n");
        printGrad("(3) 큐 peek\t(4) 종료\n");
        printGrad("=> "); if(onlyNumber(&menu)) continue;
        if (menu == 4) break;
        switch (menu) {
        case 1:
            getLine(50); printGrad("enqueue > "); if(onlyNumber(&val)) continue;
            enqueue(&queue, val); break;
        case 2:
            front = dequeue(&queue);
            if (front != QUEUE_ERROR) { getLine(50); printf("[pop] front에 있던 값 %d이 pop 되었습니다.\n", front); } break;
        case 3:
            front = peek(&queue);
            if (front != QUEUE_ERROR) { getLine(50); printf("[peek] front에 있던 값 %d이 peek 되었습니다.\n", front); } break;
        default: printf(RED "1 ~ 4 중 하나를 선택해주세요.\n" RESET); break;
        }
    }

    return 0;
}