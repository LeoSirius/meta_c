/*
 * stack implemented in array
 */

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include "meta_c/darray.h"

struct stack_record {
    int top_of_stack;
    darray array;
};

typedef struct stack_record *stack;

stack stack_new(int size);
void stack_del(stack stk);
int stack_is_empty(stack stk);
int stack_is_full(stack stk);
void stack_make_empty(stack stk);
// void push(stack stk, element_type x);
// void pop(stack stk);
// element_type top(stack stk);

// void stack_expand(stack stk);


stack new_stack(int size)
{
    stack stk;
    stk = (stack)malloc(sizeof(struct stack_record));
    if (stk == NULL) {
        perror("Error: ");
        return NULL;
    }
    stk->array = darray_new();
    stack_make_empty(stk);

    return stk;
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




#endif