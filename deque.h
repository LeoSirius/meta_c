#ifndef DEQUE_H
#define DEQUE_H

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

typedef struct _deque {
    darray *array;
}deque;

#endif