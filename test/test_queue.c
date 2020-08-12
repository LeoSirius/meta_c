#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "queue.h"

void test1()
{
    bool is_pass = true;
    queue *que = queue_new();

    if(!queue_is_empty(que)) {
        printf("!queue_is_empty(que)");
        is_pass = false;
    }

    int v1 = 1, v2 = 2, v3 = 3;
    queue_push(que, &v1);
    queue_push(que, &v2);
    queue_push(que, &v3);

    int *front1 = queue_front(que);
    queue_pop(que);
    int *front2 = queue_front(que);
    queue_pop(que);
    int *front3 = queue_front(que);
    queue_pop(que);
    int *front4 = queue_front(que);

    if (*front1 != v1 || *front2 != v2 || *front3 != v3 || front4 != NULL) {
        is_pass = false;
        printf("*front1 = %d, *front2 = %d, *front3 = %d, front4 = %p\n", *front1, *front2, *front3, front4);
    }

    queue_del(que);

    if (is_pass)
        printf("test1 success.\n");
    else
        printf("test1 failed\n");
}

void test2()
{
    bool is_pass = true;
    queue *que = queue_new();
    char *strs[] = {"I", "am", "Leo", "Sirius"};
    queue_push(que, strs[0]);
    queue_push(que, strs[1]);
    queue_push(que, strs[2]);
    queue_push(que, strs[3]);

    char *top1 = queue_front(que);
    queue_pop(que);
    char *top2 = queue_front(que);
    queue_pop(que);
    char *top3 = queue_front(que);
    queue_pop(que);
    char *top4 = queue_front(que);
    queue_pop(que);
    char *top5 = queue_front(que);
    queue_pop(que);

    if (!is_equal_str(top1, strs[0]) ||
        !is_equal_str(top2, strs[1]) ||
        !is_equal_str(top3, strs[2]) ||
        !is_equal_str(top4, strs[3]) ||
        top5 != NULL
    ) {
        printf("top1 = %s\n", top1);
        printf("top2 = %s\n", top2);
        printf("top3 = %s\n", top3);
        printf("top4 = %s\n", top4);
        printf("top5 = %p\n", top5);
        is_pass = false;
    }

    queue_del(que);

    if (is_pass)
        printf("test2 success.\n");
    else
        printf("test2 failed\n");

}

void test3()
{
    bool is_pass = true;
    queue *que = queue_new();
    const int LIMIT = 10000;
    int *arr = (int*)malloc(sizeof(int) * LIMIT);
    for (int i = 0; i < LIMIT; i++) {
        arr[i] = i;
        queue_push(que, &(arr[i]));
    }
    for (int i = 0; i < LIMIT; i++) {
        int *res = queue_pop(que);

        if (*res != i) {
            is_pass = false;
        }
    }

    int size = queue_size(que);
    if (size != 0) {
        is_pass = false;
        printf("size = %d\n", size);
    }

    if (is_pass)
        printf("test3 success.\n");
    else
        printf("test3 failed\n");
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}