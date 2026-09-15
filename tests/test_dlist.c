#include "test_util.h"
#include "my_dlist.h"

static void test_empty(void)
{
    DNode *head = NULL;
    CHECK(dlist_length(head) == 0);
    CHECK(dlist_find(head, 1) == NULL);
    dlist_free(head);
}

static void test_insert_head_tail(void)
{
    DNode *head = NULL;
    for (int i = 1; i <= 5; ++i)
        head = dlist_insert_tail(head, i);
    head = dlist_insert_head(head, 0);         /* 0 1 2 3 4 5 */

    CHECK(dlist_length(head) == 6);

    DNode *p = head;
    for (int i = 0; i <= 5; ++i) {
        CHECK(p != NULL);
        CHECK(p->data == i);
        p = p->next;
    }
    CHECK(p == NULL);

    /* 反向链接检查 */
    DNode *tail = head;
    while (tail->next) tail = tail->next;
    CHECK(tail->data == 5);
    for (int i = 5; i >= 0; --i) {
        CHECK(tail != NULL);
        CHECK(tail->data == i);
        tail = tail->prev;
    }
    CHECK(tail == NULL);
    dlist_free(head);
}

static void test_insert_pos(void)
{
    DNode *head = NULL;
    for (int i = 1; i <= 3; ++i)
        head = dlist_insert_tail(head, i);      /* 1 2 3 */

    head = dlist_insert_pos(head, 1, 20);       /* 1 20 2 3 */
    CHECK(dlist_length(head) == 4);
    CHECK(head->data == 1);
    CHECK(head->next->data == 20);
    CHECK(head->next->prev == head);
    CHECK(head->next->next->data == 2);
    CHECK(head->next->next->prev == head->next);
    dlist_free(head);
}

static void test_delete(void)
{
    DNode *head = NULL;
    for (int i = 1; i <= 5; ++i)
        head = dlist_insert_tail(head, i);      /* 1 2 3 4 5 */

    head = dlist_delete_value(head, 1);          /* 2 3 4 5 */
    CHECK(dlist_length(head) == 4);
    CHECK(head->data == 2);
    CHECK(head->prev == NULL);

    head = dlist_delete_value(head, 3);          /* 2 4 5 */
    CHECK(dlist_length(head) == 3);
    CHECK(dlist_find(head, 3) == NULL);
    CHECK(head->next->data == 4);
    CHECK(head->next->prev == head);

    head = dlist_delete_pos(head, 0);            /* 4 5 */
    CHECK(dlist_length(head) == 2);
    CHECK(head->data == 4);
    CHECK(head->prev == NULL);
    dlist_free(head);
}

int main(void)
{
    test_empty();
    test_insert_head_tail();
    test_insert_pos();
    test_delete();
    printf("PASS: test_dlist\n");
    return 0;
}
