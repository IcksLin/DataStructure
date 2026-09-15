#include "test_util.h"
#include "my_list.h"

static void test_empty(void)
{
    Node *head = NULL;
    CHECK(list_length(head) == 0);
    CHECK(list_find(head, 1) == NULL);

    int out = -1;
    CHECK(list_get(head, 0, &out) == 0);
    list_free(head);
}

static void test_insert_head_tail(void)
{
    Node *head = NULL;
    for (int i = 1; i <= 5; ++i)
        head = list_insert_tail(head, i);
    head = list_insert_head(head, 0);

    CHECK(list_length(head) == 6);
    const int expected[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < 6; ++i) {
        int out = -1;
        CHECK(list_get(head, i, &out) == 1);
        CHECK(out == expected[i]);
    }
    list_free(head);
}

static void test_insert_pos(void)
{
    Node *head = NULL;
    for (int i = 1; i <= 3; ++i)
        head = list_insert_tail(head, i);      /* 1 2 3 */

    head = list_insert_pos(head, 1, 20);       /* 1 20 2 3 */
    CHECK(list_length(head) == 4);

    int out = -1;
    CHECK(list_get(head, 0, &out) == 1 && out == 1);
    CHECK(list_get(head, 1, &out) == 1 && out == 20);
    CHECK(list_get(head, 2, &out) == 1 && out == 2);

    head = list_insert_pos(head, 0, 10);       /* 10 1 20 2 3 */
    CHECK(list_length(head) == 5);
    CHECK(list_get(head, 0, &out) == 1 && out == 10);
    list_free(head);
}

static void test_delete(void)
{
    Node *head = NULL;
    for (int i = 1; i <= 5; ++i)
        head = list_insert_tail(head, i);      /* 1 2 3 4 5 */

    head = list_delete_value(head, 1);          /* 2 3 4 5 */
    CHECK(list_length(head) == 4);
    CHECK(list_find(head, 1) == NULL);

    head = list_delete_value(head, 3);          /* 2 4 5 */
    CHECK(list_length(head) == 3);
    CHECK(list_find(head, 3) == NULL);

    head = list_delete_position(head, 0);       /* 4 5 */
    CHECK(list_length(head) == 2);

    int out = -1;
    CHECK(list_get(head, 0, &out) == 1 && out == 4);

    head = list_delete_value(head, 99);         /* 删除不存在的值 */
    CHECK(list_length(head) == 2);
    list_free(head);
}

static void test_reverse(void)
{
    Node *head = NULL;
    for (int i = 1; i <= 4; ++i)
        head = list_insert_tail(head, i);      /* 1 2 3 4 */

    head = list_reverse(head);                 /* 4 3 2 1 */
    const int expected[] = {4, 3, 2, 1};
    for (int i = 0; i < 4; ++i) {
        int out = -1;
        CHECK(list_get(head, i, &out) == 1 && out == expected[i]);
    }
    list_free(head);
}

int main(void)
{
    test_empty();
    test_insert_head_tail();
    test_insert_pos();
    test_delete();
    test_reverse();
    printf("PASS: test_list\n");
    return 0;
}
