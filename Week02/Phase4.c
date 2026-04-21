#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define DEFVAL 36

/*
추가적으로 리스트 기능 프로그램을 만든다.
리스트의 추가, 삭제, 변경 기능을 추가한다.
*/

void input_list();
void print_list();
void run_menu();
void add_list(int val);
void insert_list(int pos, int val);
int delete_list(int pos);
int update_list(int pos, int val);
void get_line(int n);
int only_num(int *num);

int size;
int elem[MAX];

int main(void) {
    srand(time(NULL));

    printf("추가할 정수의 개수를 입력하세요 : ");
    if (only_num(&size) == 1) return 0;
    input_list();
    run_menu();

    return 0;
}

void run_menu() {
    int menu;
    int pos, val;
    int del, upd;
    while (1) {
        get_line(DEFVAL);
        print_list();
        printf("\n(1) 끝에 값 추가\t(2) pos번째에 값 추가\n");
        printf("(3) pos번째 삭제\t(4) pos번째 값 변경\n");
        printf("(5) 종료\n");
        printf("선택 => ");
        if(only_num(&menu) == 1) continue;
        if (menu == 5) break;
        switch (menu) {
        case 1:
            get_line(DEFVAL);
            printf("추가 값 : ");
            scanf("%d", &val);
            add_list(val);
            break;
        case 2:
            get_line(DEFVAL);
            printf("위치 입력 : ");
            scanf("%d", &pos);
            printf("추가 값 : ");
            scanf("%d", &val);
            insert_list(pos, val);
            break;
        case 3:
            get_line(DEFVAL);
            printf("위치 입력 : ");
            scanf("%d", &pos);
            del = delete_list(pos);
            printf("삭제된 값 : %d\n", del);
            break;
        case 4:
            get_line(DEFVAL);
            printf("위치 입력 : ");
            scanf("%d", &pos);
            printf("변경 값 : ");
            scanf("%d", &val);
            upd = update_list(pos, val);
            printf("변경전 값 : %d\n", upd);
            break;
        default: get_line(DEFVAL); printf("1 ~ 5 중 하나를 선택해주세요.\n"); continue;
        }
    }
}

void add_list(int val) {
    printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
    elem[size++] = val; /*맨 뒤 인덱스에 값을 넣고, size 후증가
    (ex. 공간이 8이면 인덱스는 0~7인데, size는 8이므로 맨 뒤에 추가 됨) */
}

void insert_list(int pos, int val) {
    printf("값 %d를 리스트 %d번째에 추가합니다.\n", val, pos);
    for(int index = size - 1; index >= pos; index--) { // 인덱스 마지막요소에서 pos위치까지
        elem[index + 1] = elem[index]; // 요소의 값을 한 칸씩 뒤로 땡김
    }
    elem[pos] = val; // pos에 있던 값을 뒤로 땡겼으니 pos번째에 값 할당
    size++; // 값이 추가됐으니 size 후증가
}

int delete_list(int pos) {
    int delete = elem[pos]; // pos에 있는 값 임시저장
    printf("리스트 %d번째 값 %d를 삭제합니다.\n", pos, delete);
    for(int index = pos; index <= size - 1; index++) { // pos에서 인덱스 마지막까지
        elem[index] = elem[index + 1]; // 요소 값을 앞으로 한 칸씩 땡김 (pos값 지워짐)
    }
    size--; // 앞으로 한칸씩 땡겼으니 size 1 내려감
    return delete; // 삭제한 값 반환
}

int update_list(int pos, int val) {
    int update = elem[pos];
    printf("리스트 %d번째 값을 %d로 변경합니다.\n", pos, val);
    elem[pos] = val; // pos번째 값을 입력한 값으로 변경
    return update; // 업데이트 전 값 반환
}

void input_list() {
    for(int i = 0; i < size; i++) {
        elem[i] = rand() % 100;
        // scanf("%d", &elem[i]); // 입력 주석처리
    }
}

void print_list() {
    for(int i = 0; i < size; i++) {
        printf("%d", elem[i]);
        if (i != size - 1) printf(", "); // 마지막 인덱스 제외
        if (i % 8 == 7) printf("\n"); // 8개씩 나눠 개행, 배열 인덱스는 0부터라 나머지 7확인
    }
}

void get_line(int n) {
    for(int i = 1; i <= n; i++) printf("=");
    printf("\n");
}

int only_num(int *num) {
    if (scanf("%d", num) != 1) {
        printf("\n숫자만 입력해 주세요.\n");
        while (getchar() != '\n') continue;
        return 1;
    }
    return 0;
}