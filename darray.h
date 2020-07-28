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

darray new_darray();
void del_darray(darray *da);
bool is_empty(darray da);
bool is_full(darray da);
void expand(darray da);
void append(darray da, void *x);

darray new_darray(int cap)
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

void del_darray(darray *da)
{
    if (*da == NULL)
        return;
    free((*da)->data);
    free(*da);
    *da = NULL;
}

bool is_full(darray da)
{
    return da->size == da->capacity;
}

bool is_emoty(darray da)
{
    return da->size == 0;
}

void expand(darray da)
{
    da->capacity *= 2;
    da->data = realloc(da->data, sizeof(void*) * da->capacity);
}

void append(darray da, void *p)
{
    if (is_full(da)) expand(da);
    da->data[da->size++] = p;
}


#endif