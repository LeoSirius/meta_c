#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "darray.h"

void test1()
{
    bool is_pass = true;
    darray da = new_darray(2);
    int v1 = 1, v2 = 2, v3 = 3;
    append(da, &v1);
    append(da, &v2);
    append(da, &v3);

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
    del_darray(&da);
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
    darray da = new_darray(3);
    char *strs[] = {"I", "am", "Leo", "Sirius"};
    append(da, strs[0]);
    append(da, strs[1]);
    append(da, strs[2]);
    append(da, strs[3]);
    for (int i = 0; i < 4; i++) {
        // printf("strs[i] = %s\ndata[i] = %s\n", strs[i], (char*)(da->data[i]));
        if (strs[i] != (char*)(da->data[i])) {
            printf("%s\n", (char*)(da->data[i]));
            is_pass = false;
        }
    }
    if (da->size != 4 || da->capacity != 6) {
        printf("size = %d, cap = %d\n", da->size, da->capacity);
        is_pass = false;
    }
    del_darray(&da);
    if (da != NULL) {
        printf("da != NULL\n");
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