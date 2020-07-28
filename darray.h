/*
 * dynamic array
 */

#ifndef DARRAY_H
#define DARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef void* element_type;

struct darray_record {
    int capacity;
    int size;
    element_type *array;
};

typedef struct darray_record *darray;

darray new_darray(int capacity);
int is_empty(darray da);
int is_full(darray da);
// long int get_size(darray da);
void del_darray(darray da);
void make_empty(darray da);
void expand(darray da);
void append(darray da, element_type x);

/*
 * capacity: new array's capacity in bytes
 */
darray new_darray(int capacity)
{
    darray da = (darray)malloc(sizeof(struct darray_record));
    if (da == NULL) {
        printf("This is %s() from %s, line %d\n", __FUNCTION__, __FILE__, __LINE__);
        printf("malloc error\n");
        return NULL;
    }
    // cannot create init capacity accroding to element_type
    // element_type is void*, we cannot know size of element it pointed to
    da->array = malloc(sizeof(char*) * capacity);
    da->capacity = capacity;
    da->size = 0;
    return da;
}

// long int get_size(darray da)
// {
//     return sizeof(da->array);
// }

int is_empty(darray da)
{
    return da->size == 0;
}

int is_full(darray da)
{
    return da->size == da->capacity;
}

void del_darray(darray da)
{
    if (da == NULL)
        return;
    free(da->array);
    free(da);
}

void make_empty(darray da)
{
    da->size = 0;
}

void expand(darray da)
{
    da->capacity *= 2;
    printf("size before = %ld\n", sizeof(da->array));
    da->array = realloc(da->array, da->capacity);
    printf("size after = %ld\n", sizeof(da->array));
    // for (int i = 0; i < 10; i++) {
    //     printf("%d\n", da->array[i]);
    // }
}

void append(darray da, element_type x)
{
    if (is_full(da)) expand(da);
    da->array[(da->size)++] = x;
}


#endif