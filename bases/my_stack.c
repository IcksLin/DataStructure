#include "my_stack.h"


void stcak_init(Stack *s)
{
    s->top = NULL;
    s->size = 0;
}

int Stack_push(Stack *s,int val)
{
    StackNode *n = malloc(sizeof(StackNode));

    if(!n) return 0;
    n->data = val;
    n->next = s->top;
    s->top = n;
    s->size++;
    return 1;
}

int stack_pop(Stack *s,int *out)
{
    if(!s->top)
    {
        printf("Stack is empty,pop false\r\n");
        return 0;
    } 
    StackNode *n = s->top;
    if(out) *out = n->data;
    s->top = n->next;
    s->size--;
    free(n);
    return 1;
}

int stack_top(Stack *s,int *out)
{
    if(!s->top)
    {
        printf("Stack is empty,top false\r\n");
        return 0;
    } 
    if(out) 
    {
        *out = s->top->data;
        return 1;
    }
    return 0;
}

int stack_empty(Stack *s)
{
    return s->top == NULL;
}

int stack_free(Stack *s)
{
    while (s->top)
    {
        StackNode *n = s->top;
        s->top = n->next;
        free(n);
    }
    s->size = 0;
    
}
