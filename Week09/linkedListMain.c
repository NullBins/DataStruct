#include <stdio.h>
#include "linkedList.h"

int main(void) {
    node_t* hdr = new_node(3);
    node_t* p1 = insert_first(hdr, 4);

    print_list(hdr);

    return 0;
}