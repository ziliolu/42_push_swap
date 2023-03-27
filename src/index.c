#include "../includes/push_swap.h"

int find_index(t_stack stack, t_node *node)
{
    t_node *tmp;
    int i;

    tmp = stack.top;
    i = 0;
    while(i < stack.size)
    {
        if(tmp == node)
            break;
        tmp = tmp->next;
        i++;
    }
    return(i);
}