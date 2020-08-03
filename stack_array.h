/*
 * stack implemented in darray
 * darray it self is dynamic array, so stack build on top of
 * it will never full logically
 */

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "darray.h"

struct stack_record {
    int top_of_stack;
    darray array;
};

typedef struct stack_record *stack;

stack stack_new();
void stack_del(stack *stk);
void stack_make_empty(stack stk);

void stack_push(stack stk, void *);
void *stack_top(stack stk);
void *stack_pop(stack stk);
int stack_size(stack stk);
// void push(stack stk, element_type x);
// void pop(stack stk);
// element_type top(stack stk);
// void stack_expand(stack stk);


stack stack_new()
{
    stack stk;
    stk = (stack)malloc(sizeof(struct stack_record));
    if (stk == NULL) {
        perror("Error: ");
        return NULL;
    }
    stk->array = darray_new(0);
    stack_make_empty(stk);

    return stk;
}

void stack_del(stack *stk)
{
    if (*stk == NULL)
        return;
    darray_del(&(*stk)->array);
    free(*stk);
    *stk = NULL;
}

void stack_make_empty(stack stk)
{
    if (!stk)
        return;
    stk->top_of_stack = -1;
}

void del_stack(stack stk)
{
    if (stk == NULL) return;
    darray_del(&(stk->array));
    free(stk);
}

void stack_push(stack stk, void *x)
{
    darray_append(stk->array, x);
}

void* stack_top(stack stk)
{
    if (!stk)
        return NULL;
    return darray_back(stk->array);
}

void* stack_pop(stack stk)
{
    if (!stk)
        return NULL;
    return darray_pop(stk->array);
}

int stack_size(stack stk)
{
    return darray_size(stk->array);
}

#endif
