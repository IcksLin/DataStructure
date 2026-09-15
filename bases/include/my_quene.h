#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct QNode
{
    int date;
    struct QNode *next;

} QNode;

typedef struct
{
    QNode *front;
    QNode *rear;
    int size;

}Queue;

void queue_init(Queue *q);
int queue_enqueue(Queue *q, int value);
int queue_dequeue(Queue *q, int *out);
int queue_front(Queue *q, int *out);
int queue_empty(Queue *q);
int queue_free(Queue *q);






#endif
