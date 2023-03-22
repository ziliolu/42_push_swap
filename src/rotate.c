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

int rr(t_stack *a, t_stack *b)
{
    if(verify_two_elements(*a) == 1 && verify_two_elements(*b))
    {
        rotate(a);
        rotate(b);
        return (1);
    }
    return (-1);
}