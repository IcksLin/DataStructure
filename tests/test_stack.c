#include "test_util.h"
#include "my_stack.h"

int main(void)
{
    Stack s;
    stack_init(&s);
    CHECK(stack_empty(&s));
    CHECK(s.size == 0);
    CHECK(stack_pop(&s, NULL) == 0);

    for (int i = 1; i <= 5; ++i)
        CHECK(stack_push(&s, i) == 1);
    CHECK(s.size == 5);
    CHECK(!stack_empty(&s));

    int top = -1;
    CHECK(stack_top(&s, &top) == 1 && top == 5);

    int out = -1;
    CHECK(stack_pop(&s, &out) == 1 && out == 5);
    CHECK(stack_pop(&s, &out) == 1 && out == 4);
    CHECK(s.size == 3);
    CHECK(stack_top(&s, &top) == 1 && top == 3);

    stack_free(&s);
    CHECK(stack_empty(&s));
    CHECK(s.size == 0);

    printf("PASS: test_stack\n");
    return 0;
}
