#include "../includes/push_swap.h"

void	init_structs(t_stack *a, t_stack *b)
{
	a->top = NULL;
    b->top = NULL;
    a->size = 0;
    b->size = 0;
    a->charac = 'a';
    b->charac = 'b';
}

void init_utils(t_utils *utils)
{
    utils->a_data = 0;
    utils->b_data = 0;
    utils->a_rotate = 0;
    utils->b_rotate = 0;
    utils->a_reverse_rotate = 0;
    utils->b_reverse_rotate = 0;
    utils->rr = 0;
    utils->rrr = 0;
}
