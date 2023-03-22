#include "../includes/push_swap.h"

int reverse_rotate(t_stack *stack)
{
    if(verify_two_elements(*stack) == 1)
    {
        printf("rr%c\n", stack->charac);
        stack->top = find_last_node(*stack);
        return (1);
    }
    return (-1);
}

int rrr(t_stack *a, t_stack *b)
{
    if(verify_two_elements(*a) == 1 && verify_two_elements(*b))
    {
        reverse_rotate(a);
        reverse_rotate(b);
        return (1);
    }
    return (-1);
}