/*
 * stack implemented in array
 */

#ifndef DARRAY_H
#define DARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct darray_record {
    int capacity;
    int size;
    void **data;
};

typedef struct darray_record* darray;

#define INIT_CAPACITY (100)
#define INCREMENT_FACTOR (2)

darray darray_new();
void darray_del(darray *da);
bool darray_is_empty(darray da);
bool darray_is_full(darray da);
void darray_expand(darray da);
void darray_append(darray da, void *x);
int darray_size(darray da);

darray darray_new(int cap)
{
    darray da = (darray)malloc(sizeof(struct darray_record));
    if (da == NULL) {
        perror("Error: ");
        return NULL;
    }
    da->capacity = cap ? cap : INIT_CAPACITY;
    da->data = (void**)calloc(INIT_CAPACITY, sizeof(void*));
    if (da->data == NULL) {
        perror("Error: ");
        return NULL;
    }
    da->size = 0;
    return da;
}

void darray_del(darray *da)
{
    if (*da == NULL)
        return;
    free((*da)->data);
    free(*da);
    *da = NULL;
}

bool darray_is_full(darray da)
{
    return da->size == da->capacity;
}

bool darray_is_empty(darray da)
{
    return da->size == 0;
}

void darray_expand(darray da)
{
    da->capacity *= 2;
    da->data = realloc(da->data, sizeof(void*) * da->capacity);
}

void darray_append(darray da, void *p)
{
    if (darray_is_full(da)) darray_expand(da);
    da->data[da->size++] = p;
}

void* darray_back(darray da)
{
    if (darray_is_empty(da))
        return NULL;
    return da->data[da->size-1];
}

void* darray_pop(darray da)
{
    if (darray_is_empty(da))
        return NULL;
    return da->data[(da->size)--];
}

int darray_size(darray da)
{
    return da->size;
}


#endif