#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_array.h"
#include "utils.h"

void test1()
{
    bool is_pass = true;
    stack stk = stack_new();
    int v1 = 1, v2 = 2, v3 = 3;
    stack_push(stk, &v1);
    stack_push(stk, &v2);
    stack_push(stk, &v3);

    int *top1 = stack_top(stk);
    stack_pop(stk);
    int *top2 = stack_top(stk);
    stack_pop(stk);
    int *top3 = stack_top(stk);
    stack_pop(stk);
    int *top4 = stack_top(stk);

    if (*top1 != v3 || *top2 != v2 || *top3 != v1 || top4 != NULL) {
        is_pass = false;
        printf("*top1 = %d, *top2 = %d, *top3 = %d, top4 = %p", *top1, *top2, *top3, top4);
    }

    stack_del(&stk);
    if (stk != NULL)
        is_pass = false;

    if (is_pass)
        printf("test1 success.\n");
    else
        printf("test1 failed\n");

}

void test2()
{
    bool is_pass = true;
    stack stk = stack_new();
    char *strs[] = {"I", "am", "Leo", "Sirius"};
    stack_push(stk, strs[0]);
    stack_push(stk, strs[1]);
    stack_push(stk, strs[2]);
    stack_push(stk, strs[3]);

    char *top1 = stack_top(stk);
    stack_pop(stk);
    char *top2 = stack_top(stk);
    stack_pop(stk);
    char *top3 = stack_top(stk);
    stack_pop(stk);
    char *top4 = stack_top(stk);
    stack_pop(stk);
    char *top5 = stack_top(stk);
    stack_pop(stk);

    if (!is_equal_str(top1, strs[3]) ||
        !is_equal_str(top2, strs[2]) ||
        !is_equal_str(top3, strs[1]) ||
        !is_equal_str(top4, strs[0]) ||
        top5 != NULL
    ) {
        printf("top1 = %s\n", top1);
        printf("top2 = %s\n", top2);
        printf("top3 = %s\n", top3);
        printf("top4 = %s\n", top4);
        printf("top5 = %p\n", top5);
        is_pass = false;
    }

    if (is_pass)
        printf("test2 success.\n");
    else
        printf("test2 failed\n");

}

int main()
{
    test1();
    test2();
    return 0;
}