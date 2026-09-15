#ifndef MY_DLIST_H
#define MY_DLIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode *dlist_create_node(int value);
void   dlist_free(DNode *head);

DNode *dlist_insert_head(DNode *head, int value);
DNode *dlist_insert_tail(DNode *head, int value);
DNode *dlist_insert_pos(DNode *head, int pos, int value);

DNode *dlist_delete_value(DNode *head, int value);
DNode *dlist_delete_pos(DNode *head, int pos);

DNode *dlist_find(DNode *head, int value);
int    dlist_length(DNode *head);

void   dlist_print_forward(DNode *head);
void   dlist_print_backward(DNode *head); 


#endif
