#ifndef DEQUE_H
#define DEQUE_H

/*
 * use darray 0 as front,    append side as back
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "darray.h"

typedef struct _deque {
    darray *array;
}deque;

deque*  deque_new           ();
void    deque_del           (deque *self);

void*   deque_back          (deque* self);
void    deque_push_back     (deque* self, void* x);
void*   deque_pop_back      (deque* self);

void*   deque_front         (deque* self);
void    deque_push_front    (deque* self, void* x);
void*   deque_pop_front     (deque* self, void* x);


int     deque_size          (deque* self);
bool    deque_is_empty      (deque* self);


deque* deque_new()
{
    deque *self = (deque*)malloc(sizeof(deque));
    if (self == NULL) {
        perror("Error: ");
        return NULL;
    }
    self->array = darray_new(0);
    return self;
}

void deque_del(deque* self)
{
    if (self == NULL)
        return;
    darray_del(self->array);
    free(self);
    self = NULL;
}

void* deque_back(deque* self)
{
    if (deque_is_empty(self))
        return NULL;
    return self->array->data[self->array->size-1];
}

void deque_push_back(deque* self, void* target_p)
{
    darray_append(self->array, target_p);
}

void* deque_pop_back(deque* self)
{
    if (deque_is_empty(self)) {
        printf("deque_pop_back, deque is empty.\n");
        return NULL;
    }
    return self->array->data[--(self->array->size)];
}

void* deque_front(deque* self)
{
    if (deque_is_empty(self))
        return NULL;
    return self->array->data[0];
}

void deque_push_front(deque* self, void* target_p)
{
    darray_insert(self->array, target_p, 0);
}

void* deque_pop_front(deque* self)
{
    void* res = self->array->data[0];
    darray_delete(self->array, 0);
    return res;
}

int deque_size(deque* self)
{
    return self->array->size;
}

bool deque_is_empty(deque* self)
{
    return darray_is_empty(self->array);
}


#endif