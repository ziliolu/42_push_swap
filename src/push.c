#include "../includes/push_swap.h"

int push(t_stack *origin, t_stack *dest)
{
    t_node *tmp;

    printf("PUSH %c\n", dest->charac);
    
    if(!origin->top)
    {
        printf("-> não há elementos suficientes p/ push");
        return(-1);
    }    
    
    tmp = origin->top;
    
    find_last_node(*origin)->next = origin->top->next;
    origin->top->next->prev = find_last_node(*origin);
    origin->top = origin->top->next;
    origin->top->prev = find_last_node(*origin);

    
    add_node_front(dest, newNode(tmp->data));
    origin->size -= 1;
    return(1);
}