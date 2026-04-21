#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/*
Phase2의 프로그램 부분에서
'입력부'에서 입력 대신 개수만큼 난수를 생성하여 저장한다.
'출력부'에서는 한 줄에 8개씩 줄바꿈 기능을 추가한다.
*/

void input_list();
void print_list();

int size;
int elem[MAX];

int main(void) {
    srand(time(NULL));

    printf("숫자의 개수를 입력하세요 : ");
    scanf("%d", &size);
    input_list();
    print_list();
    printf("\n감사합니다.\n");

    return 0;
}

void input_list() {
    for(int i = 0; i < size; i++) {
        elem[i] = rand() % 100;
        // scanf("%d", &elem[i]); // 입력 주석처리
    }
}

void print_list() {
    for(int i = 0; i < size; i++) {
        printf("%d, ", elem[i]);
        if (i % 8 == 7) printf("\n"); // 8개씩 나눠 개행, 배열 인덱스는 0부터라 나머지 7확인
    }
}