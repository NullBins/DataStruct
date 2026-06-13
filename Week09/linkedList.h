#pragma once

typedef int elem_t;
typedef struct node {
    elem_t data;
    struct node *next;
} node_t;

char* str(elem_t e);
node_t* new_node(elem_t data);
node_t* insert_first(node_t* hdr, elem_t data);
void print_list(node_t* hdr);