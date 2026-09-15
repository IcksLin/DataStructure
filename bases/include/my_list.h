#ifndef MY_LIST_H
#define MY_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *list_create_node(int val);
void list_free(Node *head);

Node *list_insert_head(Node *head,int val);
Node *list_insert_tail(Node *head,int val);
Node *list_insert_pos(Node *head,int position,int val);

Node *list_delete_value(Node *head,int val);
Node *list_delete_position(Node *head,int position);

Node *list_find(Node *head,int val);
int list_get(Node *head,int position,int *out);

int list_length(Node *head);
Node *list_reverse(Node *head);
void list_print(Node *head);

#endif
