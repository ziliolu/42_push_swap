#include "../includes/push_swap.h"

int rotate(t_stack *stack)
{
    printf("ROTATE %c\n", stack->charac);
    if (!stack->top || !stack->top->next) // verificar se há no minimo dois elementos
    {
        printf("-> não há elementos suficientes p/ rotate\n");
        return (-1);
    }
    stack->top = stack->top->next;
    return (1);
}