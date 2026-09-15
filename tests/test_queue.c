#include "test_util.h"
#include "my_queue.h"

int main(void)
{
    Queue q;
    queue_init(&q);
    CHECK(queue_empty(&q));
    CHECK(q.size == 0);

    int out = -1;
    CHECK(queue_dequeue(&q, &out) == 0);
    CHECK(queue_front(&q, &out) == 0);

    for (int i = 1; i <= 5; ++i)
        CHECK(queue_enqueue(&q, i) == 1);
    CHECK(q.size == 5);
    CHECK(!queue_empty(&q));

    int front = -1;
    CHECK(queue_front(&q, &front) == 1 && front == 1);

    CHECK(queue_dequeue(&q, &out) == 1 && out == 1);
    CHECK(queue_dequeue(&q, &out) == 1 && out == 2);
    CHECK(q.size == 3);
    CHECK(queue_front(&q, &front) == 1 && front == 3);

    queue_free(&q);
    CHECK(queue_empty(&q));
    CHECK(q.size == 0);

    printf("PASS: test_queue\n");
    return 0;
}
