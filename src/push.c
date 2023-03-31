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
    
    // tmp = origin->top;
    
    // find_last_node(*origin)->next = origin->top->next;
    // origin->top->next->prev = find_last_node(*origin);
    // origin->top = origin->top->next;
    // origin->top->prev = find_last_node(*origin);

    
    // add_node_front(dest, newNode(tmp->data));
    // origin->size -= 1;
    return(1);
}