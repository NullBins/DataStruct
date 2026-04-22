#include <stdio.h>
#include <stdlib.h>
#include "Arrlist.h"

void find_loop() {
    int val;
    while (1) {
        get_line(DEFVAL);
        printf("찾을 값을 넣으세요 (종료: -1 입력) : ");
        if (only_num(&val)) continue;
        if (val == -1) break;
        if (find_index(&list1, val) < 0) printf("리스트1에 %d(은)는 없습니다.\n", val);
        else printf("리스트1에 %d(은)는 [%d]번 인덱스에 있습니다.\n", val, find_index(&list1, val));
        if (find_index(&list2, val) < 0) printf("리스트2에 %d(은)는 없습니다.\n", val);
        else printf("리스트2에 %d(은)는 [%d]번 인덱스에 있습니다.\n", val, find_index(&list2, val));
    }
}

void add_list(arrlist_t* listp, int val) {
    printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
    listp->elem[listp->size++] = val; /*맨 뒤 인덱스에 값을 넣고, size 후증가
    (ex. 공간이 8이면 인덱스는 0~7인데, size는 8이므로 맨 뒤에 추가 됨) */
}

void insert_list(arrlist_t* listp, int pos, int val) {
    printf("값 %d를 리스트 %d번째에 추가합니다.\n", val, pos);
    for(int index = listp->size - 1; index >= pos; index--) { // 인덱스 마지막요소에서 pos위치까지
        listp->elem[index + 1] = listp->elem[index]; // 요소의 값을 한 칸씩 뒤로 땡김
    }
    listp->elem[pos] = val; // pos에 있던 값을 뒤로 땡겼으니 pos번째에 값 할당
    listp->size++; // 값이 추가됐으니 size 후증가
}

int delete_list(arrlist_t* listp, int pos) {
    int delete = listp->elem[pos]; // pos에 있는 값 임시저장
    printf("리스트 %d번째 값 %d를 삭제합니다.\n", pos, delete);
    for(int index = pos; index <= listp->size - 1; index++) { // pos에서 인덱스 마지막까지
        listp->elem[index] = listp->elem[index + 1]; // 요소 값을 앞으로 한 칸씩 땡김 (pos값 지워짐)
    }
    listp->size--; // 앞으로 한칸씩 땡겼으니 size 1 내려감
    return delete; // 삭제한 값 반환
}

int update_list(arrlist_t* listp, int pos, int val) {
    int update = listp->elem[pos];
    printf("리스트 %d번째 값을 %d로 변경합니다.\n", pos, val);
    listp->elem[pos] = val; // pos번째 값을 입력한 값으로 변경
    return update; // 업데이트 전 값 반환
}

void init_list(arrlist_t* listp, int size) {
    listp->size = size;
}

int get_index(arrlist_t* listp, int index) {
    return listp->elem[index];
}

int find_index(arrlist_t* listp, int val) {
    for(int i = 0; i < listp->size; i++) {
        if (listp->elem[i] == val) return i;
    }
    return -1;
}

void input_list(arrlist_t* listp) {
    for(int i = 0; i < listp->size; i++) {
        listp->elem[i] = rand() % 100;
        // scanf("%d", &elem[i]); // 입력 주석처리
    }
}

void print_list(arrlist_t* listp) {
    for(int i = 0; i < listp->size; i++) {
        printf("%d ", listp->elem[i]);
    }
    printf("\n");
}

int get_sum(arrlist_t* listp) {
    int sum = 0;
    for(int i = 0; i < listp->size; i++) sum += listp->elem[i];
    return sum;
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