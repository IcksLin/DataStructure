#include "my_list.h"

Node *list_create_node(int val)
{
    Node *n = malloc(sizeof(Node));
    if(!n) return NULL;
    n->data = val;
    n->next = NULL;
    return n;

}

void list_free(Node *head)
{
    while (head)
    {
        Node *n = head;
        head = n->next;
        free(n);
    }
    
}

Node *list_insert_head(Node *head,int val)
{
    Node *n = list_create_node(val);
    if(!n) return head;
    n->next = head;
    return n;
}

Node *list_insert_tail(Node *head,int val){
    Node *n = list_create_node(val);
    if(!n) return 0;
    if(!head)
    {
        free(n);
        return n;
    } 
    Node *p = head;

    while (p->next)
    {
        p = p->next;
    }
    p->next = n;
    return head;
    
}

Node *list_insert_pos(Node *head,int postion,int val)
{
    if(postion<0)return head;
    if(postion == 0) return list_insert_head(head,val);

    Node *n = list_create_node(val);
    if(!n) return head;

    //到位置
    Node *pre = head;
    for(int i = 0; i < postion - 1; i++)
    {
        pre = pre->next;
    }
    if(!pre){
        free(n);
        return head;
    } 

    n->next = pre->next;
    pre->next = n;
    return head;
}

Node *list_delete_value(Node *head,int val)
{
    Node *pre = NULL;
    Node *cur = head;

    while (cur&&cur->data != val)
    {
        pre = cur;
        cur = cur->next;
    }
    if(!cur) return head;
    if(!pre) head = cur->next;
    else pre->next = cur->next;
    free(cur);
    return head;
}

Node *list_delete_postion(Node *head,int postion)
{
    if(!head||postion<0) return head;
    if(postion == 0)
    {
        Node *n = head;
        head = head->next;
        free(n);
        return head;
    }

    Node *pre = head;
    for(int i = 0;i < postion -1;i++)
    {
        pre = pre->next;
    }
    if(!pre) return head;
    Node *cur = pre->next;
    pre->next = cur->next;
    free(cur);
    return head;
}

Node *list_find(Node *head,int val)
{
    for(Node*p;p;p = p->next){
        if(p->data == val) return p;
    }
    return NULL;
}

int list_get(Node *head,int postion,int *out)
{
    if(postion<0) return 0;
    Node *p = head;
    for(int i = 0;i<postion&&p;i++)
    {
        p = p->next;
    }
    if(!p) return 0;
    if(out) *out = p->data;
    return 1;
}

int list_length(Node *head)
{
    int length = 0;
    for(Node *p = head;p;p = p->next) length++;
    return length;
}

Node *list_reverse(Node *head)
{
    Node *pre = NULL,*cur = head,*next;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void *list_print(Node *head)
{
    for(Node *p = head;p;p = p->next)
    {
        printf("%d->",p->data);
    }
    printf("NULL\r\n");
}