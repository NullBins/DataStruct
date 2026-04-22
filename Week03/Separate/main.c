#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Arrlist.h"

int main(void) {
    srand(time(NULL));

    init_list(&list1, 10); init_list(&list2, 10);
    input_list(&list1); input_list(&list2);
    get_line(DEFVAL);
    printf("[리스트1] :\t"); print_list(&list1);
    printf("[리스트2] :\t"); print_list(&list2);
    get_line(DEFVAL);
    printf("[리스트1] 요소 전체 합:\t%d\n", get_sum(&list1));
    printf("[리스트2] 요소 전체 합:\t%d\n", get_sum(&list2));
    find_loop();

    return 0;
}