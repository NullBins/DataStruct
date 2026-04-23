#include <stdio.h>
#include <math.h>
#include "SubUtils.h"

// Line Print
void getLine(int n) {
    for(int i = 1; i <= n; i++) printGrad("=");
    printf("\n");
}

// Terminal Gradation Text Color
void printGrad(const char* str) { // 문자열 리터럴 파라미터로 받음
    int r, g, b;
    double freq = 0.05; // 주파수 0.05 (20초에 1번)
    for(int i = 0; str[i] != '\0';) {
        r = (sin(freq * i + 0) * 127) + 128; // sin[-1 ~ 1] * 127 = (-127 ~ 127)
        g = (sin(freq * i + 1) * 127) + 128; // (-127 ~ 127) + 128 = (1 ~ 255)
        b = (sin(freq * i + 2) * 127) + 128; // 24Bit(RGB) = 0~255, 0~255, 0~255
        if ((str[i] & 0x80) != 0) { // ASCII를 제외한 1바이트를 넘는 문자는 1000 0000 형태로 앞이 항상 1임
            printf("\033[38;2;%d;%d;%dm%.3s", r, g, b, &str[i]); // UTF-8 때문에 3바이트 씩 read
            i += 3; // 3Byte
        } else {
            printf("\033[38;2;%d;%d;%dm%c", r, g, b, str[i]); // ASCII라면 1바이트씩
            i++; // 1Byte
        }
    }
    printf("\033[0m"); // 컬러 초기화
}

// Input the Only Number
int onlyNumber(int *num) {
    if (scanf("%d", num) != 1) { // 숫자가 아니면 1 (숫자가 맞으면 0)
        printf(RED "숫자만 입력해주세요.\n" RESET);
        while (getchar() != '\n') continue; // New Line(\n) 까지 버퍼 비움
        return 1; // 숫자가 아님
    }
    return 0; // 숫자임
}