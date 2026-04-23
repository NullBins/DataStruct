#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "../Stack/SubUtils.h"
#define SUCCESS 0
#define MORE_RIGHT_PAREN 1
#define MISMATCH 2
#define MORE_LEFT_PAREN 3

int paren_check(char* parens);
char* msg[] = { "성공!", "ERROR: 오른쪽 괄호 먼저 나옴!", "괄호 불일치!", "ERROR: 왼쪽 괄호 먼저 나옴!" };

int main(void) {
    char parens[20];
    int msg_num;

    while (1) {
        printGrad("\n[ Paren \"[,{,(,),},]\" 입력 ](종료: end) >> "); scanf("%s", parens);
        if (strcmp(parens, "end") == 0) { printGrad("안녕히가세요!\n"); break; }
        msg_num = paren_check(parens);
        printGrad("< "); printf("%s %s", parens, msg[msg_num]); printGrad(" >\n");
    }
    return 0;
}

int is_open(char paren) {
    return (paren == '(' || paren == '{' || paren == '[');
}

int is_closing(char paren) {
    return (paren == ')' || paren == '}' || paren == ']');
}

int matching(char open_pr, char pr) {
    return ((open_pr == '(' && pr == ')') || (open_pr == '{' && pr == '}') || (open_pr == '[' && pr == ']'));
}

void print_line(stk_t* st, char* parens) {
    printGrad("[ "); printf("%-20s", parens); printGrad(" ]\t");
    print_stack(st);
    printf("\n");
}

int paren_check(char* parens) {
    char open_pr, pr;
    int n = strlen(parens);
    stk_t stack;
    init_stack(&stack);

    printGrad("\n\t(Input)\t\t\t(Stack)\n");
    print_line(&stack, parens);

    for(int i = 0; i < n; i++) {
        pr = parens[i];
        if (is_open(pr)) push(&stack, pr);
        else if (is_closing(pr)) {
            if (is_empty(&stack)) return MORE_RIGHT_PAREN;
            open_pr = pop(&stack);
            if (!matching(open_pr, pr)) return MISMATCH;
        } else if (pr == ' ') continue;
        else { printf(RED "잘못된 입력입니다."); exit(1); }
        print_line(&stack, parens + (i + 1)); // 앞에서 부터 하나씩 뒤로 출력 위함
    }
    if (is_empty(&stack)) return SUCCESS;
    return MORE_LEFT_PAREN;
}