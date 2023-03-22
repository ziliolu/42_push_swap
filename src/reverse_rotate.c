#include "../includes/push_swap.h"

int reverse_rotate(t_stack *stack)
{
    printf("rr%c\n", stack->charac);
    if (!stack->top || !stack->top->next) // verificar se há no minimo dois elementos
    {
        printf("-> não há elementos suficientes p/ rotate\n");
        return (-1);
    }
    //The last element becomes the first one.

	stack->top = find_last_node(*stack);
    return (1);
}