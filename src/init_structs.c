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