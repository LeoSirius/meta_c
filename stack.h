/*
 * stack implemented in darray
 * darray it self is dynamic array, so stack build on top of
 * it will never full logically
 */

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "darray.h"

typedef struct _stack {
    darray *array;
}stack;

stack *stack_new();
void stack_del(stack *self);

void stack_push(stack *self, void *);
void *stack_top(stack *self);
void *stack_pop(stack *self);
int stack_size(stack *self);
bool stack_is_empty(stack *self);


stack* stack_new()
{
    stack *self = (stack*)malloc(sizeof(stack));
    if (self == NULL) {
        perror("Error: ");
        return NULL;
    }
    self->array = darray_new(0);
    return self;
}

void stack_del(stack *self)
{
    if (self == NULL)
        return;
    darray_del(self->array);
    free(self);
    self = NULL;
}

void stack_push(stack *self, void *p_target)
{
    darray_append(self->array, p_target);
}

void* stack_top(stack *self)
{
    if (!self)
        return NULL;
    return darray_back(self->array);
}

void* stack_pop(stack *self)
{
    if (!self)
        return NULL;
    return darray_pop(self->array);
}

int stack_size(stack *self)
{
    return darray_size(self->array);
}

bool stack_is_empty(stack *self)
{
    return darray_is_empty(self->array);
}

#endif
