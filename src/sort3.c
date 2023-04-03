#include "../includes/push_swap.h"

int sort3(t_stack *stack)
{
    int n1;
    int n2;
    int n3;

    n1 = stack->top->data;
    n2 = stack->top->next->data;
    n3 = stack->top->next->next->data;
    while(is_organized(*stack) != 1)
    {
        if(n1 > n2 && n1 < n3) //case 2 1 3
            swap(stack);
        else if(n1 > n2 && n2 < n3 && n1 > n3) //case 3 1 2 
            rotate(stack, 1);
        else if(n1 < n2 && n2 > n3 && n1 > n3) // case 2 3 1
            reverse_rotate(stack, 1);
    }
    return(1);
}