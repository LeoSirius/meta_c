/*
 * stack implemented in array
 */

#ifndef DARRAY_H
#define DARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _darray {
    int capacity;
    int size;
    void **data;
}darray;


#define INIT_CAPACITY (100)
#define INCREMENT_FACTOR (2)

darray*     darray_new      ();
void        darray_del      (darray* self);

void        darray_expand   (darray* self);
void        darray_append   (darray* self, void* x);

void        darray_insert   (darray* self, void* x, int pos);
void        darray_delete   (darray* self, int pos);

int         darray_size     (darray* self);
bool        darray_is_empty (darray* self);

bool        _darray_is_full (darray* self);  /* never full to user */

/*
 * cap 0 means default capacity
 */
darray* darray_new(int cap)
{
    darray *self = (darray*)malloc(sizeof(darray));
    if (self == NULL) {
        perror("Error: ");
        return NULL;
    }
    self->capacity = cap ? cap : INIT_CAPACITY;
    self->data = (void**)calloc(INIT_CAPACITY, sizeof(void*));
    if (self->data == NULL) {
        perror("Error: ");
        return NULL;
    }
    self->size = 0;
    return self;
}

void darray_del(darray *self)
{
    if (self == NULL)
        return;
    free(self->data);
    free(self);
    self = NULL;
}

bool _darray_is_full(darray *self)
{
    return self->size == self->capacity;
}

bool darray_is_empty(darray *self)
{
    return self->size == 0;
}

void darray_expand(darray *self)
{
    self->capacity *= 2;
    self->data = realloc(self->data, sizeof(void*) * self->capacity);
}

void darray_append(darray *self, void *p_target)
{
    if (_darray_is_full(self))
        darray_expand(self);
    self->data[self->size++] = p_target;
}

void* darray_back(darray *self)
{
    if (darray_is_empty(self))
        return NULL;
    return self->data[self->size-1];
}

void* darray_pop(darray *self)
{
    if (darray_is_empty(self))
        return NULL;
    return self->data[--(self->size)];
}

int darray_size(darray *self)
{
    return self->size;
}

void darray_insert(darray *self, void *x, int pos)
{
    if (pos < 0 || self->size < pos) {
        printf("darray_insert pos %d invalid.\n", pos);
        printf("self->size = %d\n", self->size);
        return;
    }
    if (_darray_is_full(self))
        darray_expand(self);
    for (int i = self->size; pos < i; i--) {
        self->data[i] = self->data[i-1];
    }
    (self->size)++;
    self->data[pos] = x;
}

void darray_delete(darray *self, int pos)
{
    if (pos < 0 || self->size <= pos) {
        printf("darray_insert pos %d invalid.\n", pos);
        printf("self->size = %d\n", self->size);
        return;
    }
    for (int i = pos; i < self->size - 1; i++)
        self->data[i] = self->data[i+1];
    (self->size)--;
}


#endif