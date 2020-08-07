#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct _queue {
    stack *stk_in;
    stack *stk_out;
} queue;

queue *queue_new();
void queue_del(queue *self);
void* queue_front(queue *self);
void* queue_back(queue *self);
void* queue_pop(queue *self);
void queue_push(queue *self, void *p_target);
bool queue_is_empty(queue *self);
int queue_size(queue *self);

queue* queue_new()
{
    queue *self = (queue*)malloc(sizeof(queue));
    if (self == NULL) {
        perror("Error: ");
        return NULL;
    }
    self->stk_in = stack_new();
    self->stk_out = stack_new();
    return self;
}

void queue_del(queue *self)
{
    stack_del(self->stk_in);
    stack_del(self->stk_out);
    free(self);
    self = NULL;
}

bool queue_is_empty(queue *self)
{
    return stack_is_empty(self->stk_in) && stack_is_empty(self->stk_out);
}


void* queue_front(queue *self)
{
    if (queue_is_empty(self))
        return NULL;
    
    if (!stack_is_empty(self->stk_out))
        return stack_top(self->stk_out);

    /* out stack is empty 
     * 1. in stack has one item, return that item
     * 2. in stack has more than one item, move all but remain one to out stack
     * 
     * we keep in stack at least one item, for back usage
     */

    if (stack_size(self->stk_in) == 1)
        return stack_top(self->stk_in);

    while (stack_size(self->stk_in) > 1) {
        void *tmp = stack_pop(self->stk_in);
        stack_push(self->stk_out, tmp);
    }

    return stack_top(self->stk_out);

}

void* queue_pop(queue *self)
{
    if (queue_is_empty(self))
        return NULL;

    if (!stack_is_empty(self->stk_out))
        return stack_pop(self->stk_out);

    /* same as front
     * we keep in stack at least one item, for back usage 
     */
    if (stack_size(self->stk_in) == 1)
        return stack_pop(self->stk_in);

    while (stack_size(self->stk_in) > 1) {
        void *tmp = stack_pop(self->stk_in);
        stack_push(self->stk_out, tmp);
    }

    return stack_pop(self->stk_out);
}

void* queue_back(queue *self)
{
    if (stack_is_empty(self->stk_in))
        return NULL;
    
    return stack_top(self->stk_in);
}

void queue_push(queue *self, void *p_target)
{
    stack_push(self->stk_in, p_target);
}

int queue_size(queue *self)
{
    return stack_size(self->stk_in) + stack_size(self->stk_out);
}



#endif