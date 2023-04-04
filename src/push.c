#include "../includes/push_swap.h"

int push(t_stack *stack, t_node *node, bool op)
{
    if(!node)
        return (-1);
    stack->size++;
    if(op == 1)
        printf("p%c\n", stack->charac);
    if(!stack->top)
    {
        stack->top = node;
        stack->top->next = node;
        stack->top->prev = node;
        return (1);
    }    
    node->next = stack->top;
    node->prev = stack->top->prev;
    stack->top->prev->next = node;
    stack->top->prev = node;
    stack->top = node;
    return(1);
}