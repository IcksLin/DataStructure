#include "my_queue.h"

void queue_init(Queue *q)
{
    q->front = NULL;
    q->rear =NULL;
    q->size = 0;

}
int queue_enqueue(Queue *q, int value)
{
    QNode *n = malloc(sizeof(QNode));
    if(!n)
    {
        printf("enqueue false\r\n");
        return 0;
    }
    n->data = value;
    n->next = NULL;
    if(q->front == NULL){
        q->front = q->rear = n;
    }else
    {
        q->rear->next = n;
        q->rear = n;    
    }
    q->size++;
    return 1;

}
int queue_dequeue(Queue *q, int *out)
{
    if(q->front == NULL)
    {
        printf("queue is empty\r\n");
        return 0;
    }
    QNode *n = q->front;
    if(out) *out = n->data;
    q->front = n->next;
    if(q->front == NULL) q->rear = NULL;
    q->size--;
    free(n);
    return 1;
    
}
int queue_front(Queue *q, int *out)
{
    if(q->front==NULL)
    {
        printf("queue is empty\r\n");
        return 0;
    }
    *out = q->front->data;
    return 1;
}

int queue_empty(Queue *q)
{
    return q->front == NULL;
}

int queue_free(Queue *q)
{
    while (q->front)
    {
        QNode *n = q->front;
        q->front = n->next;
        free(n);

    }
    q->rear = NULL;
    q->size = 0;
    return 1;
}