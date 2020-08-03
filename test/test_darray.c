#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "darray.h"
#include "utils.h"

void test1()
{
    bool is_pass = true;
    darray da = darray_new(2);
    int v1 = 1, v2 = 2, v3 = 3;
    darray_append(da, &v1);
    darray_append(da, &v2);
    darray_append(da, &v3);

    int *back1 = darray_back(da);
    if (*back1 != v3)
        is_pass = false;

    darray_pop(da);
    int *back2 = darray_back(da);
    if (*back2 != v2)
        is_pass = false;

    darray_append(da, &v3);

    for (int i = 0; i < 3; i++) {
        if (i+1 != *(int*)(da->data[i])) {
            printf("%d\n", *(int*)(da->data[i]));
            is_pass = false;
        }
    }
    if (da->size != 3 || da->capacity != 4) {
        printf("size = %d, cap = %d\n", da->size, da->capacity);
        is_pass = false;
    }
    darray_del(&da);
    if (da != NULL) {
        printf("da != NULL\n");
        is_pass = false;
    }

    if (is_pass)
        printf("test1 success.\n");
    else
        printf("test1 failed\n");
}

void test2()
{
    bool is_pass = true;
    darray da = darray_new(3);
    char *strs[] = {"I", "am", "Leo", "Sirius"};
    darray_append(da, strs[0]);
    darray_append(da, strs[1]);
    darray_append(da, strs[2]);
    darray_append(da, strs[3]);

    char *back1 = darray_back(da);
    if (!is_equal_str(back1, strs[3]))
        is_pass = false;

    darray_pop(da);
    char *back2 = darray_back(da);
    if (!is_equal_str(back2, strs[2]))
        is_pass = false;

    darray_append(da, strs[3]);

    for (int i = 0; i < 4; i++) {
        if (strs[i] != (char*)(da->data[i])) {
            printf("%s\n", (char*)(da->data[i]));
            is_pass = false;
        }
    }
    if (da->size != 4 || da->capacity != 6) {
        printf("size = %d, cap = %d\n", da->size, da->capacity);
        is_pass = false;
    }
    darray_del(&da);
    if (da != NULL) {
        printf("da != NULL\n");
        is_pass = false;
    }

    if (is_pass)
        printf("test2 success.\n");
    else
        printf("test2 failed\n");
}

void test3()
{
    bool is_pass = true;
    darray da = darray_new(2);
    int v1 = 1, v2 = 2;
    darray_append(da, &v1);
    darray_append(da, &v2);

    darray_pop(da);
    int *back1 = darray_back(da);
    if (*back1 != v1)
        is_pass = false;

    darray_pop(da);
    int *back2 = darray_back(da);
    if (back2 != NULL)
        is_pass = false;

    if (is_pass)
        printf("test3 success.\n");
    else
        printf("test3 failed\n");
}

int main()
{
    // 1 and 2 are general tests
    test1();
    test2();

    // test pop extreme case
    test3();
    return 0;
}