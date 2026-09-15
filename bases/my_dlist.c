#include "my_dlist.h"

DNode *dlist_create_node(int value)
{
    DNode *n = malloc(sizeof(DNode));
    if(!n) return NULL;
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void   dlist_free(DNode *head)
{
    while (head)
    {
        DNode *n = head;
        head = head->next;
        free(n);
    }
    
}

DNode *dlist_insert_head(DNode *head, int value)
{
    DNode *n = dlist_create_node(value);
    if(!n) return head;
    n->next = head;
    if(head) head->prev = n;
    return n;
}

DNode *dlist_insert_tail(DNode *head, int value)
{
    DNode *n = dlist_create_node(value);
    if(!n) return head;
    if(!head) return n;
    DNode *p = head;
    while (p->next) p = p->next;
    p->next = n;
    n->prev = p;
    return head;
}

DNode *dlist_insert_pos(DNode *head, int pos, int value)
{
    if(pos < 0) return head;
    if(pos == 0) return dlist_insert_head(head,value);

    DNode *prev = head;
    for(int i = 0;i < pos -1;i++)
    {
        if(!prev) return head;
        prev = prev->next;
    }

    if(!prev) return head;
    DNode *n = dlist_create_node(value);
    if(!n) return ;
    n->next = prev->next;
    n->prev = prev;

    if(prev->next) prev->next->prev = n;
    prev->next = n;
    return head;

}

DNode *dlist_delete_value(DNode *head, int value)
{
    DNode *cur = head;
    while (cur&&cur->data != value)
    {
        cur = cur->next;
    }
    if(!cur) return head;
    if(cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if(cur->next) cur->next->prev = cur->prev;
    free(cur);
    return head;
    
}
DNode *dlist_delete_pos(DNode *head, int pos)
{
    if(!head||pos < 0) return head;
    if(pos == 0){
        DNode *n = head;
        head = head->next;
        if(head) head->prev = NULL;
        free(n);
        return head;
    }

    DNode *cur = head;
    for(int i = 0;i <pos && cur;i++)
    {
        cur = cur->next;
    }

    if(!cur) return head;
    cur->prev->next = cur->next;
    if(cur->next) cur->next->prev = cur->prev;
    free(cur);
    return head;
}

DNode *dlist_find(DNode *head, int value)
{
    for(DNode *p = head; p; p = p->next)
    {
        if(p->data == value) return p;
    }
    return NULL;
}
int    dlist_length(DNode *head)
{
    int n = 0;
    for(DNode *p = head; p; p++) n++;
    return n;

}

void   dlist_print_forward(DNode *head)
{
    printf("NULL <-");
    for(DNode *p = head; p; p = p->next)printf("%d<->",p->data);
    printf("NULL\r\n");
}

void   dlist_print_backward(DNode *head)
{
    if(!head)
    {
        printf("NULL\r\n");
        return;
    }
    DNode *p = head;
    while(p->next) p = p->next;
    printf("NULL <-");
    for(; p; p = p->prev)printf("%d<->",p->data);
    printf("NULL\r\n");
}