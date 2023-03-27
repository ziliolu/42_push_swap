#include "../includes/push_swap.h"

int swap(t_stack *stack)
{
    int tmp;
    if(stack->size >= 2)
    {
        printf("s%c\n", stack->charac);
        tmp = stack->top->data;
        stack->top->data = stack->top->next->data;
        stack->top->next->data = tmp;
        return (1);     
    }
    return (-1);
}