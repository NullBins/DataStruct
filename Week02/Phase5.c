#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
#define DEFVAL 36

/*
기존의 정수형 배열 리스트 프로그램을
문자열 배열 리스트 프로그램으로 수정한다.
*/

void input_list();
void print_list();
void run_menu();
void add_list(char* val);
void insert_list(int pos, char* val);
char* delete_list(int pos);
char* update_list(int pos, char* val);
char* get_next();
void free_list();
void get_line(int n);
int only_num(int *num);

int size;
char* elem[MAX];

int main(void) {
    srand(time(NULL));

    printf("추가할 문자열의 개수를 입력하세요 : ");
    if (only_num(&size)) return 0;
    printf("%d개 문자열 입력 : ", size);
    input_list();
    run_menu();
    free_list();

    return 0;
}

void run_menu() {
    int menu;
    int pos;
    while (1) {
        get_line(DEFVAL);
        print_list(); printf("\n");
        get_line(DEFVAL);
        printf("\n(1) 끝에 값 추가\t(2) pos번째에 값 추가\n");
        printf("(3) pos번째 삭제\t(4) pos번째 값 변경\n");
        printf("(5) 종료\n");
        printf("선택 => ");
        if(only_num(&menu)) continue;
        if (menu == 5) break;
        switch (menu) {
        case 1:
            get_line(DEFVAL);
            printf("추가 값 : ");
            add_list(get_next());
            break;
        case 2:
            get_line(DEFVAL);
            printf("위치 입력 : ");
            if (only_num(&pos)) continue;
            printf("추가 값 : ");
            insert_list(pos, get_next());
            break;
        case 3:
            get_line(DEFVAL);
            printf("위치 입력 : ");
            if (only_num(&pos)) continue;
            char* del = delete_list(pos);
            printf("삭제된 값 : %s\n", del);
            break;
        case 4:
            get_line(DEFVAL);
            printf("위치 입력 : ");
            if (only_num(&pos)) continue;
            printf("변경 값 : ");
            char* upd = update_list(pos, get_next());
            printf("변경전 값 : %s\n", upd);
            break;
        default: get_line(DEFVAL); printf("1 ~ 5 중 하나를 선택해주세요.\n"); continue;
        }
    }
}

void add_list(char* val) {
    printf("값 %s를 리스트 맨 끝에 추가합니다.\n", val);
    elem[size++] = val; /*맨 뒤 인덱스에 값을 넣고, size 후증가
    (ex. 공간이 8이면 인덱스는 0~7인데, size는 8이므로 맨 뒤에 추가 됨) */
}

void insert_list(int pos, char* val) {
    printf("값 %s를 리스트 %d번째에 추가합니다.\n", val, pos);
    for(int index = size - 1; index >= pos; index--) { // 인덱스 마지막요소에서 pos위치까지
        elem[index + 1] = elem[index]; // 요소의 값을 한 칸씩 뒤로 땡김
    }
    elem[pos] = val; // pos에 있던 값을 뒤로 땡겼으니 pos번째에 값 할당
    size++; // 값이 추가됐으니 size 후증가
}

char* delete_list(int pos) {
    char* delete = elem[pos]; // pos에 있는 값 임시저장
    printf("리스트 %d번째 값 %s를 삭제합니다.\n", pos, delete);
    for(int index = pos; index <= size - 1; index++) { // pos에서 인덱스 마지막까지
        elem[index] = elem[index + 1]; // 요소 값을 앞으로 한 칸씩 땡김 (pos값 지워짐)
    }
    size--; // 앞으로 한칸씩 땡겼으니 size 1 내려감
    return delete; // 삭제한 값 반환
}

char* update_list(int pos, char* val) {
    char* update = elem[pos];
    printf("리스트 %d번째 값을 %s로 변경합니다.\n", pos, val);
    elem[pos] = val; // pos번째 값을 입력한 값으로 변경
    return update; // 업데이트 전 값 반환
}

char* get_next() {
    char buf[20]; // 최대 20 '\0'포함 19글자
    scanf("%s", buf); // fgets를 사용하는게 좋으나 '\n'을 '\0'로 바꿔주는 코드 넣어야 함 (귀찮음)
    char* chptr = (char*)malloc(sizeof(char) * (strlen(buf) + 1)); // 문자열 길이만큼 동적 할당
    strcpy(chptr, buf); // 포인터로 문자열 복사
    return chptr; // 포인터 주소 반환
}

void input_list() {
    for(int i = 0; i < size; i++) {
        elem[i] = get_next(); // get_next()로 문자열 입력
    }
}

void print_list() {
    for(int i = 0; i < size; i++) {
        printf("%s ", elem[i]); // 배열 리스트 출력
    }
}

void free_list() {
    for(int i = 0; i < size; i++) free(elem[i]); // 배열 리스트 메모리 해제
}

void get_line(int n) {
    for(int i = 1; i <= n; i++) printf("=");
    printf("\n");
}

int only_num(int *num) {
    if (scanf("%d", num) != 1) {
        get_line(DEFVAL);
        printf("숫자만 입력해 주세요.\n");
        while (getchar() != '\n') continue;
        return 1;
    }
    return 0;
}