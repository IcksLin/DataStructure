#include <stdio.h>

#include "my_list.h"
#include "my_dlist.h"
#include "my_stack.h"
#include "my_queue.h"

static void demo_list(void)
{
    printf("========== 单向链表 my_list ==========\n");
    Node *head = NULL;
    for (int i = 1; i <= 5; ++i)
        head = list_insert_tail(head, i);
    head = list_insert_head(head, 0);
    head = list_insert_pos(head, 2, 99);
    printf("构建后：");
    list_print(head);
    printf("长度 = %d\n", list_length(head));

    Node *found = list_find(head, 99);
    printf("查找 99：%s\n", found ? "命中" : "未命中");

    int value = -1;
    if (list_get(head, 0, &value))
        printf("下标 0 的值 = %d\n", value);

    head = list_delete_value(head, 0);
    head = list_delete_position(head, 1);
    printf("删除后：");
    list_print(head);

    head = list_reverse(head);
    printf("反转后：");
    list_print(head);

    list_free(head);
    printf("\n");
}

static void demo_dlist(void)
{
    printf("========== 双向链表 my_dlist ==========\n");
    DNode *head = NULL;
    for (int i = 1; i <= 5; ++i)
        head = dlist_insert_tail(head, i);
    head = dlist_insert_head(head, 0);
    head = dlist_insert_pos(head, 3, 88);
    printf("正向：");
    dlist_print_forward(head);
    printf("反向：");
    dlist_print_backward(head);
    printf("长度 = %d\n", dlist_length(head));

    head = dlist_delete_value(head, 88);
    head = dlist_delete_pos(head, 0);
    printf("删除后正向：");
    dlist_print_forward(head);

    dlist_free(head);
    printf("\n");
}

static void demo_stack(void)
{
    printf("========== 链式栈 my_stack ==========\n");
    Stack s;
    stack_init(&s);
    for (int i = 1; i <= 5; ++i)
        stack_push(&s, i * 10);

    int top = -1;
    if (stack_top(&s, &top))
        printf("栈顶 = %d，大小 = %d\n", top, s.size);

    printf("出栈：");
    while (!stack_empty(&s)) {
        int out = -1;
        if (stack_pop(&s, &out))
            printf("%d ", out);
    }
    printf("\n");

    stack_free(&s);
    printf("\n");
}

static void demo_queue(void)
{
    printf("========== 链式队列 my_queue ==========\n");
    Queue q;
    queue_init(&q);
    for (int i = 1; i <= 5; ++i)
        queue_enqueue(&q, i);

    int front = -1;
    if (queue_front(&q, &front))
        printf("队头 = %d，大小 = %d\n", front, q.size);

    printf("出队：");
    while (!queue_empty(&q)) {
        int out = -1;
        if (queue_dequeue(&q, &out))
            printf("%d ", out);
    }
    printf("\n");

    queue_free(&q);
}

int main(void)
{
    demo_list();
    demo_dlist();
    demo_stack();
    demo_queue();
    return 0;
}
