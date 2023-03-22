#include "../includes/push_swap.h"

int swap(t_stack *stack)
{
    t_node *tmp;
    if(verify_two_elements(*stack, OP.swap, stack.charac) == 1)
    {
        printf("SWAP %c\n", stack->charac);
        tmp = stack->top;
        stack->top = stack->top->next;
        tmp->next = stack->top->next;
        stack->top->next = tmp;
        stack->top->prev = find_last_node(*stack);
        find_last_node(*stack)->next = stack->top;
        return (1);     
    }
    return (-1);
}