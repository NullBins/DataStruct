#include <stdio.h>

// 최대 100개의 제한. 정수를 입력받아 출력하는 프로그램

#define MAX 100

int main(void) {
    int size;
    int elem[MAX];

    printf("숫자의 개수를 입력하세요 : ");
    scanf("%d", &size);
    printf("%d개의 정수를 입력하세요 : ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &elem[i]);
    }
    for(int i = 0; i < size; i++) {
        printf("%d ", elem[i]);
    }
    printf("\n감사합니다.\n");

    return 0;
}