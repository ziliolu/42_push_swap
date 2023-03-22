#include "../includes/push_swap.h"

void free_stacks(t_stack *a, t_stack *b)
{
    t_node *tmp;
    while(a->top)
    {
        tmp = a->top; 
        a->top = a->top->next;
        free(tmp);
    }
    while(b->top)
    {
        tmp = b->top;
        b->top = b->top->next;
        free(tmp);
    }
}