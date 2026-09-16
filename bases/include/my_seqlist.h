#ifndef MY_SEQLIST_H
#define MY_SEQLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} SeqList;

SeqList *seqlist_create(int init_capacity);
void     seqlist_free(SeqList *list);

int  seqlist_push_back(SeqList *list, int value);   
int  seqlist_insert(SeqList *list, int pos, int value);
int  seqlist_delete(SeqList *list, int pos);        
int  seqlist_delete_value(SeqList *list, int value);

int  seqlist_get(SeqList *list, int pos, int *out); 
int  seqlist_set(SeqList *list, int pos, int value);
int  seqlist_find(SeqList *list, int value);       

int  seqlist_size(SeqList *list);
int  seqlist_empty(SeqList *list);
void seqlist_print(SeqList *list);


#endif
