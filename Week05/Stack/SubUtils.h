#pragma once

// Terminal Text Colors
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define GRAY "\033[0;37m"
#define RESET "\033[0m"
#define DEF_LINE_COUNT 36

// Sub Util Functions
void getLine(int n);
void printGrad(const char* str);
int onlyNumber(int* num);