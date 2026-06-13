#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

char* str(elem_t e) {
    static char out[20];
    snprintf(out, 20, "%d", e);
    return out;
}

node_t* new_node(elem_t data) {
    node_t *p = (node_t*)malloc(sizeof(node_t));
    p->data = data;
    p->next = NULL;
    return p;
}

node_t* insert_first(node_t* hdr, elem_t data) {
    node_t *p = new_node(data);
    p->next = hdr;
    return p;
}

void print_list(node_t* hdr) {
    node_t* p = hdr;
    while (p != NULL) {
        printf("%s -> ", str(p->data));
        p = p->next;
    }
    printf("\n");
}