#include <stdio.h>
#define MAX 100

/*
Phase1의 프로그램을 함수를 만들어
'입력부'와 '출력부'로 독립시킨다.
Top-down 방식으로 프로그램을 구성한다. (메인에서는 전체 구조만 파악)
*/

void input_list();
void print_list();

int size;
int elem[MAX];

int main(void) {
    printf("숫자의 개수를 입력하세요 : ");
    scanf("%d", &size);
    input_list();
    print_list();
    printf("\n감사합니다.\n");

    return 0;
}

void input_list() {
    printf("%d개의 정수를 입력하세요 : ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &elem[i]);
    }
}

void print_list() {
    for(int i = 0; i < size; i++) {
        printf("%d ", elem[i]);
    }
}