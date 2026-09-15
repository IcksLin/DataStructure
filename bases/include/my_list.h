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
Node *list_insert_pos(Node *head,int postion,int val);

Node *list_delete_value(Node *head,int val);
Node *list_delete_postion(Node *head,int postion);

Node *list_find(Node *head,int val);
int list_get(Node *head,int postion,int *out);

int list_length(Node *head);
Node *list_reverse(Node *head);
void *list_print(Node *head);

#endif
