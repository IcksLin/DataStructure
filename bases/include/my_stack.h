#ifndef MY_STACK_H
#define MY_STACK_H

#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
}StackNode;

typedef struct {
    StackNode *top;
    int size;
    
}Stack;

void stack_init(Stack *s);
int stack_push(Stack *s,int val);
int stack_pop(Stack *s,int *out);
int stack_top(Stack *s,int *out);
int stack_empty(Stack *s);
int stack_free(Stack *s);




#endif
