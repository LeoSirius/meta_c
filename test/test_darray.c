#include <stdio.h>
#include <stdbool.h>
#include "darray.h"

void test1()
{
    bool is_pass = true;
    darray da = new_darray(5);
    int v1 = 1, v2 = 2, v3 = 3, v4 = 4, v5 = 5, v6 = 6;
    append(da, &v1);
    append(da, &v2);
    append(da, &v3);
    append(da, &v4);
    append(da, &v5);
    append(da, &v6);
    if (da->capacity != 10) {
        printf("da->capacity != 10\n");
        is_pass = false;
    }
    // printf("da->size = %d\n", da->size);
    // for (int i = 0; i < da->size; i++) {
    //     printf("*(da->array[i]) = %d, i = %d\n", *(int*)(da->array[i]), i);
    //     // if ((i + 1) != *(int*)(da->array[i]))
    //     //     is_pass = false;
    //     printf("after ==\n");
    // }
    printf("-=-=-=bb\n");
    if (is_pass)
        printf("%s test1 success.\n", __FILE__);
    else
        printf("%s test1 failed.\n", __FILE__);
}

int main()
{
    test1();
}